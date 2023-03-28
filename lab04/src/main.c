#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <windows.h>

#pragma warning(disable: 4305)

#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)
#define For(x) for (size_t i = 0; i < (x); ++i)

static void error(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static uint32_t counter;
static CRITICAL_SECTION section;
static HANDLE mutex, event, semaphore;

static DWORD WINAPI critical_section_thread_routine(LPVOID param) {
	(void)param;
	EnterCriticalSection(&section);
	counter++;
	printf("[critsec] counter is %u\n", counter);
	LeaveCriticalSection(&section);
	return 0;
}

static DWORD WINAPI mutex_thread_routine(LPVOID param) {
	(void)param;
	WaitForSingleObject(mutex, INFINITE);
	counter++;
	printf("[mutex] counter is %u\n", counter);
	if (!ReleaseMutex(mutex)) {
		fatal_error("unable to release mutex (code %lu)", GetLastError());
	}

	return 1;
}

static DWORD WINAPI event_thread_routine(LPVOID param) {
	(void)param;
	WaitForSingleObject(mutex, INFINITE);
	counter++;
	printf("[event] counter is %u\n", counter);
	return 1;
}

static DWORD WINAPI semaphore_thread_routine(LPVOID param) {
	(void)param;
	WaitForSingleObject(semaphore, INFINITE);
	counter++;
	printf("[semaphore] counter is %u\n", counter);
	if (!ReleaseSemaphore(semaphore, 1, NULL)) {
		fatal_error("unable to release semaphore (code %lu)", GetLastError());
	}

	return 1;
}

static void WaitAndReleaseThreads(HANDLE* threads, size_t num_threads) {
	WaitForMultipleObjects(num_threads, threads, TRUE, INFINITE);
	For(num_threads) { CloseHandle(threads[i]); }
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fatal_error("Usage: lab04.exe <threads-number>");
	}

	uint32_t num_threads = strtoul(argv[1], NULL, 10);
	if (num_threads == ULONG_MAX) {
		num_threads = MAXIMUM_WAIT_OBJECTS;
	} else if (num_threads > MAXIMUM_WAIT_OBJECTS) {
		fatal_error("The number of threads cannot exceed %d", MAXIMUM_WAIT_OBJECTS);
	}

	// NOTE(wkns37): Critical Section
	DWORD tid;
	HANDLE threads[MAXIMUM_WAIT_OBJECTS] = { 0 };

	InitializeCriticalSection(&section);
	For(num_threads) {
		threads[i] = CreateThread(NULL, 0, critical_section_thread_routine, NULL, 0, &tid);
	}

	WaitAndReleaseThreads(threads, num_threads);
	DeleteCriticalSection(&section);

	// NOTE(wkns37): Mutex
	mutex = CreateMutexA(NULL, FALSE, NULL);
	if (mutex == NULL) {
		fatal_error("unable to create mutex (code %lu)", GetLastError());
	}

	For(num_threads) {
		threads[i] = CreateThread(NULL, 0, mutex_thread_routine, NULL, 0, &tid);
	}

	WaitAndReleaseThreads(threads, num_threads);

	// NOTE(wkns37): Event
	event = CreateEventA(NULL, FALSE, TRUE, NULL);
	if (event == NULL) {
		fatal_error("unable to create event (code %lu)", GetLastError());
	}

	For(num_threads) {
		threads[i] = CreateThread(NULL, 0, event_thread_routine, NULL, 0, &tid);
	}

	WaitAndReleaseThreads(threads, num_threads);

	// NOTE(wkns37): Semaphore
	semaphore = CreateSemaphoreA(NULL, 1, 1, NULL);
	if (semaphore == NULL) {
		fatal_error("unable to create semaphore (code %lu)", GetLastError());
	}

	For(num_threads) {
		threads[i] = CreateThread(NULL, 0, semaphore_thread_routine, NULL, 0, &tid);
	}

	WaitAndReleaseThreads(threads, num_threads);
	return 0;
}