#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../../common/protocol.h"

#pragma comment(lib, "ws2_32.lib")

#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)

enum {
	BUFFER_SIZE = 512,
};

static void error(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static void* xmalloc(size_t size) {
	void* ptr = malloc(size);
	if (!ptr) {
		fatal_error("unable to allocate memory");
	}

	return ptr;
}

static DWORD global_drive_last_error;
static uint32_t global_drive_ts;
static uint8_t global_drive_count;
static DriveInfo global_drive_infos[26];
static CRITICAL_SECTION global_drive_critical_section;
static CONDITION_VARIABLE global_drive_condition_variable;

static DWORD get_drive_info(uint32_t in_ts, uint32_t* out_ts, DriveInfo* out_infos, uint8_t* out_count, bool force) {
	EnterCriticalSection(&global_drive_critical_section);
	while ((in_ts >= global_drive_ts) && !force) {
		SleepConditionVariableCS(&global_drive_condition_variable, &global_drive_critical_section, INFINITE);
	}

	*out_ts = global_drive_ts;
	memcpy(out_infos, global_drive_infos, sizeof(DriveInfo) * global_drive_count);
	*out_count = global_drive_count;
	DWORD error = global_drive_last_error;
	LeaveCriticalSection(&global_drive_critical_section);
	return error;
}

static void update_drive_info(void) {
	char drives[BUFFER_SIZE] = { 0 };
	char* p = drives;
	if (!GetLogicalDriveStringsA(sizeof(drives) - 1, drives)) {
		DWORD code = GetLastError();
		error("unable to get logical drive strings (code %lu)", code);
		return;
	}

	EnterCriticalSection(&global_drive_critical_section);
	uint8_t count = 0;
	DriveInfo tmp[sizeof(global_drive_infos) / sizeof(DriveInfo)] = { 0 };
	DriveInfo* entry = tmp;
	while (*p) {
		if (!GetVolumeInformationA(p, NULL, 0, NULL, NULL, NULL, entry->fs, sizeof(entry->fs) - 1)) {
			DWORD code = GetLastError();
			error("unable to get volume '%c' information (code %lu)", *p, code);
			global_drive_last_error = code;

			goto skip;
		}

		count++;
		entry->letter = *p;
		entry++;
	skip:
		while (*p++);
	}

	bool should_wakeup = false;
	if (memcmp(global_drive_infos, tmp, sizeof(DriveInfo) * count)) {
		global_drive_ts++;
		memcpy(global_drive_infos, tmp, sizeof(DriveInfo) * count);
		global_drive_count = count;
		should_wakeup = true;
		printf("Drive information updated\n");
	}

	LeaveCriticalSection(&global_drive_critical_section);
	if (should_wakeup) {
		WakeAllConditionVariable(&global_drive_condition_variable);
	}
}

static DWORD count_bits(ULONG_PTR mask) {
	DWORD shift = sizeof(ULONG_PTR) * 8 - 1;
	DWORD count = 0;
	ULONG_PTR test = (ULONG_PTR)1 << shift;
	for (DWORD i = 0; i <= shift; i++) {
		count += ((mask & test) ? 1 : 0);
		test /= 2;
	}

	return count;
}

static DWORD get_cpu_info(unsigned long* out_logical_cpu_count) {
	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION info = NULL;
	DWORD len = 0, offset = 0, count = 0;
retry:
	if (!GetLogicalProcessorInformation(info, &len)) {
		DWORD code = GetLastError();
		if (code == ERROR_INSUFFICIENT_BUFFER) {
			info = xmalloc(len);
			goto retry;
		}

		error("unable to get logical processor information (code %lu)", code);
		free(info);
		return code;
	}

	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION it = info;
	while (offset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= len) {
		if (it->Relationship == RelationProcessorCore) {
			count += count_bits(it->ProcessorMask);
		}

		offset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
		it++;
	}

	*out_logical_cpu_count = count;
	return ERROR_SUCCESS;
}

static DWORD WINAPI process_client(LPVOID param) {
	SOCKET client = (SOCKET)param;

retry:
	char buf[BUFFER_SIZE] = { 0 };
	int result = recv(client, buf, sizeof(buf), 0);
	if (result < 0) {
		error("unable to receive bytes (code %d)", WSAGetLastError());
		closesocket(client);
		return 1;
	} else if (result > 0) {
		Request request = *(Request*)buf;
		Response response = { .type = request.type };

		switch (request.type) {
			case TYPE_HARD_DRIVE_INFO: {
				switch (request.kind) {
					case REQ_UNARY: {
						response.error = 0 - get_drive_info(
							0, &response.ts,
							response.hard_drive_info.infos,
							&response.hard_drive_info.count,
							false
						);
					} break;

					case REQ_TIMER: {
						response.error = 0 - get_drive_info(
							request.ts,
							&response.ts,
							response.hard_drive_info.infos,
							&response.hard_drive_info.count,
							true
						);

						if (request.ts >= response.ts) {
							Response empty = {
								.type = response.type,
								.error = ERROR_EMPTY_RESPONSE
							};

							response = empty;
						}

						GetSystemTime(&response.time);
						result = send(client, (char*)&response, sizeof(Response), 0);
						if (result == SOCKET_ERROR) {
							error("unable to send (code %d)", WSAGetLastError());
							closesocket(client);
							return 1;
						}

						goto retry;
					} break;

					case REQ_REACTIVE: {
						uint32_t ts = 0;
						for (;;) {
							response.error = 0 - get_drive_info(
								ts, &ts,
								response.hard_drive_info.infos,
								&response.hard_drive_info.count,
								false
							);

							GetSystemTime(&response.time);
							result = send(client, (char*)&response, sizeof(Response), 0);
							if (result == SOCKET_ERROR) {
								error("unable to send (code %d)", WSAGetLastError());
								closesocket(client);
								return 1;
							}
						}
					} break;

					default: {
						error("unsupported request kind %d", request.kind);
						response.error = ERROR_UNSUPPORTED_REQUEST_KIND;
					} break;
				}
			} break;

			case TYPE_CPU_INFO: {
				switch (request.kind) {
					case REQ_UNARY: {
						response.error = 0 - get_cpu_info(&response.logical_cpu_count);
					} break;

					default: {
						error("unsupported request kind %d", request.kind);
						response.error = ERROR_UNSUPPORTED_REQUEST_KIND;
					} break;
				}
			} break;

			default: {
				error("unknown request type %d", request.type);
				response.error = ERROR_UNSUPPORTED_REQUEST_TYPE;
			} break;
		}

		GetSystemTime(&response.time);
		result = send(client, (char*)&response, sizeof(Response), 0);
		if (result == SOCKET_ERROR) {
			error("unable to send (code %d)", WSAGetLastError());
		}
	}

	result = shutdown(client, SD_BOTH);
	if (result == SOCKET_ERROR) {
		error("unable to shutdown client (code %d)", WSAGetLastError());
		closesocket(client);
		return 1;
	}

	return 0;
}

static DWORD WINAPI update_drive_info_routine(LPVOID param) {
	(void)param;
	for (;;) {
		update_drive_info();
		Sleep(3000);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: coursework_server_a.exe <port>\n");
		exit(1);
	}

	InitializeCriticalSection(&global_drive_critical_section);
	InitializeConditionVariable(&global_drive_condition_variable);

	WSADATA data;
	int result = WSAStartup(MAKEWORD(2, 2), &data);
	if (result) {
		fatal_error("unable to start WSA (code %d)", result);
	}

	struct addrinfo hints = { 0 };
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	struct addrinfo* info;
	result = getaddrinfo(NULL, argv[1], &hints, &info);
	if (result) {
		error("unable to get address info (code %d)", result);
		WSACleanup();
		return 1;
	}

	SOCKET sock = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	if (sock == INVALID_SOCKET) {
		error("unable to create socket (code %d)", WSAGetLastError());
		freeaddrinfo(info);
		WSACleanup();
		return 1;
	}

	result = bind(sock, info->ai_addr, (int)info->ai_addrlen);
	if (result == SOCKET_ERROR) {
		error("unable to bind socket (code %d)", WSAGetLastError());
		freeaddrinfo(info);
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(info);

	result = listen(sock, SOMAXCONN);
	if (result == SOCKET_ERROR) {
		error("unable to listen socket (code %d)", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	HANDLE thread = CreateThread(NULL, 0, update_drive_info_routine, NULL, 0, NULL);
	if (thread == INVALID_HANDLE_VALUE) {
		error("unable to create routine thread (code %d)", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	for (;;) {
		SOCKET client = accept(sock, NULL, NULL);
		if (client == INVALID_SOCKET) {
			error("unable to accept client (code %d)", WSAGetLastError());
			closesocket(client);
			continue;
		}

		thread = CreateThread(NULL, 0, process_client, (LPVOID)client, 0, NULL);
		if (thread == INVALID_HANDLE_VALUE) {
			error("unable to create thread for client (code %lu)", GetLastError());
		}
	}
}