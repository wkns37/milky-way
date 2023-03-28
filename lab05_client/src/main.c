#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <windows.h>

#pragma warning(disable: 4305 4018)

#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)
#define For(x) for (size_t i = 0; i < (x); ++i)
#define BUFFER_SIZE 4096

static void error(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static bool check_matrix_size(uint32_t n) {
	uint32_t x = (uint32_t)sqrt(n);
	return n ? ((x * x) == n) : false;
}

static void* xmalloc(size_t size) {
	void* ptr = malloc(size);
	if (!ptr) {
		fatal_error("unable to allocate memory");
	}

	return ptr;
}

static char* strf(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	size_t n = 1 + vsnprintf(NULL, 0, fmt, args);
	va_end(args);
	char* buffer = xmalloc(n);
	va_start(args, fmt);
	vsnprintf(buffer, n, fmt, args);
	va_end(args);
	return buffer;
}

int main(int argc, char* argv[]) {
	argc--;
	argv++;
	if (argc != 8) {
		fatal_error("Usage: la05.exe <v1> <v2> <v3> <v4> <v5> <v6> <v7> <v8>");
	}

	DWORD written;
	const char* mailslot_name = "\\\\.\\mailslot\\sample_mailslot";
	HANDLE mailslot = CreateFileA(mailslot_name, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (mailslot == INVALID_HANDLE_VALUE) {
		fatal_error("unable to open the mailslot (code %lu)", GetLastError());
	}

	char* short_pipe_name = strf("sample_%lu", GetCurrentProcessId());
	char* pipe_name = strf("\\\\.\\pipe\\%s", short_pipe_name);
	if (!WriteFile(mailslot, short_pipe_name, strlen(pipe_name) + 1, &written, NULL)) {
		fatal_error("unable to write to the mailslot (code %lu)", GetLastError());
	}

	HANDLE pipe;
	for (;;) {
		// NOTE(wkns37): Well, it is not the best solution
		Sleep(200);
		pipe = CreateFileA(pipe_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (pipe != INVALID_HANDLE_VALUE) {
			break;
		} else if (GetLastError() != ERROR_PIPE_BUSY) {
			fatal_error("unable to open the pipe (code %lu)", GetLastError());
		}

		WaitNamedPipeA(pipe_name, NMPWAIT_WAIT_FOREVER);
	}

	free(pipe_name);
	free(short_pipe_name);

	DWORD mode = PIPE_READMODE_MESSAGE;
	if (!SetNamedPipeHandleState(pipe, &mode, NULL, NULL)) {
		fatal_error("unable to set the pipe state (code %lu)", GetLastError());
	}

	uint32_t values[8] = { 0 };
	for (uint32_t* ptr = values; *argv; ptr++, argv++) {
		uint32_t value = strtoul(*argv, NULL, 10);
		if (value != ULONG_MAX) {
			*ptr = value;
		} else {
			error("incorrect matrix value %s, using 0 instead", *argv);
		}
	}

	char filename[] = "MySampleFileMappingObject";
	HANDLE file = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(values), filename);
	if (file == NULL) {
		fatal_error("unable to create a file mapping object (code %lu)", GetLastError());
	}

	uint32_t* view = MapViewOfFile(file, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(values));
	if (view == NULL) {
		fatal_error("unable to map view of the file (code %lu)", GetLastError());
	}

	memcpy(view, values, sizeof(values));

	if (!WriteFile(pipe, filename, strlen(filename) + 1, &written, NULL)) {
		fatal_error("unable to write to the pipe (code %lu)", GetLastError());
	}

	DWORD read;
	char msg[BUFFER_SIZE];
	if (!ReadFile(pipe, msg, sizeof(msg), &read, NULL) || !read) {
		if (GetLastError() == ERROR_BROKEN_PIPE) {
			fatal_error("the pipe was disconnected");
		} else {
			fatal_error("unable to read from the pipe (code %lu)", GetLastError());
		}
	}

	printf("%s\n", msg);

	printf("(%-3d %3d)(%-3d %3d) = (%-3d %3d)\n", values[0], values[1], values[4], values[5], view[0], view[1]);
	printf("(%-3d %3d)(%-3d %3d) = (%-3d %3d)\n", values[2], values[3], values[6], values[7], view[2], view[3]);

	CloseHandle(mailslot);
	CloseHandle(pipe);
	CloseHandle(file);
	return 0;
}