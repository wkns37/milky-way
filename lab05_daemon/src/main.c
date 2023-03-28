#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <windows.h>

#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)
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

static DWORD WINAPI process_pipe(LPVOID param) {
	HANDLE pipe = (HANDLE)param;

	DWORD read;
	char filename[BUFFER_SIZE];
	BOOL success = ReadFile(pipe, filename, sizeof(filename), &read, NULL);
	if (!success || !read) {
		if (GetLastError() == ERROR_BROKEN_PIPE) {
			error("the pipe was disconnected");
			goto end;
		} else {
			error("unable to read from the pipe (code %lu)", GetLastError());
			goto end;
		}
	}

	HANDLE file = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, filename);
	if (file == NULL) {
		error("unable to open a file mapping object (code %lu)", GetLastError());
		goto end;
	}

	uint32_t* view = MapViewOfFile(file, FILE_MAP_ALL_ACCESS, 0, 0, 8 * sizeof(uint32_t));
	if (view == NULL) {
		error("unable to map view of the file (code %lu)", GetLastError());
		goto end;
	}

	uint32_t result[8] = { 0 };
	result[0] = view[0] * view[4] + view[1] * view[6];
	result[1] = view[0] * view[5] + view[1] * view[7];
	result[2] = view[2] * view[4] + view[3] * view[6];
	result[3] = view[2] * view[5] + view[3] * view[7];
	memcpy(view, result, sizeof(result));

	UnmapViewOfFile(view);
	CloseHandle(file);

	printf("Job done for the %p file mapping object\n", file);

	DWORD written;
	char msg[] = "ok";
	if (!WriteFile(pipe, msg, sizeof(result) + 1, &written, NULL)) {
		error("unable to write to the pipe (code %lu)", GetLastError());
	}

end:
	return 1;
}

int main() {
	const char* mailslot_name = "\\\\.\\mailslot\\sample_mailslot";
	HANDLE mailslot = CreateMailslotA(mailslot_name, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (mailslot == INVALID_HANDLE_VALUE) {
		fatal_error("unable to create mailslot (code %lu)", GetLastError());
	}

	printf("Waiting for a message...\n");

	for (;;) {
		DWORD msg_size = 0, msg_count = 0, msg_read = 0;
		if (!GetMailslotInfo(mailslot, NULL, &msg_size, &msg_count, NULL)) {
			error("unable to read from the mailslot (code %lu)", GetLastError());
			goto end;
		}

		if (msg_count == MAILSLOT_NO_MESSAGE) {
			goto end;
		}

		while (msg_count) {
			char* short_pipe_name = xmalloc(msg_size);
			if (!ReadFile(mailslot, short_pipe_name, msg_size, &msg_read, NULL)) {
				error("unable to read from the mailslot (code %lu)", GetLastError());
				goto end;
			}

			char* pipe_name = strf("\\\\.\\pipe\\%s", short_pipe_name);
			HANDLE pipe = CreateNamedPipeA(
				pipe_name,
				PIPE_ACCESS_DUPLEX,
				PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
				1, BUFFER_SIZE, BUFFER_SIZE, 5000, NULL
			);

			free(pipe_name);
			free(short_pipe_name);

			if (pipe == INVALID_HANDLE_VALUE) {
				error("unable to create a pipe '%s' (code %lu)", short_pipe_name, GetLastError());
				continue;
			}

			BOOL connected = ConnectNamedPipe(pipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
			if (connected) {
				DWORD tid;
				HANDLE thread = CreateThread(NULL, 0, process_pipe, (LPVOID)pipe, 0, &tid);
				if (thread == NULL) {
					error("unable to create a thread (code %lu)", GetLastError());
					continue;
				}

				CloseHandle(thread);
			} else {
				CloseHandle(pipe);
			}

			if (!GetMailslotInfo(mailslot, NULL, &msg_size, &msg_count, NULL)) {
				error("unable to read the mailslot (code %lu)", GetLastError());
				goto end;
			}
		}

		end : 0;
	}
}