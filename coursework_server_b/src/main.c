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

static DWORD global_ram_last_error;
static uint32_t global_ram_ts;
static DWORDLONG global_total_ram;
static DWORDLONG global_available_ram;
static CRITICAL_SECTION global_ram_critical_section;
static CONDITION_VARIABLE global_ram_condition_variable;

static DWORD get_ram_info(uint32_t in_ts, uint32_t* out_ts, DWORDLONG* out_total_ram, DWORDLONG* out_available_ram, bool force) {
	EnterCriticalSection(&global_ram_critical_section);
	while ((in_ts >= global_ram_ts) && !force) {
		SleepConditionVariableCS(&global_ram_condition_variable, &global_ram_critical_section, INFINITE);
	}

	if (out_total_ram) {
		*out_total_ram = global_total_ram;
	}

	if (out_available_ram) {
		*out_available_ram = global_available_ram;
	}

	*out_ts = global_ram_ts;
	DWORD error = global_ram_last_error;
	LeaveCriticalSection(&global_ram_critical_section);
	return error;
}

static void update_ram_info(void) {
	MEMORYSTATUSEX status = { sizeof(status) };
	if (!GlobalMemoryStatusEx(&status)) {
		DWORD code = GetLastError();
		error("unable to get global memory status (code %lu)", code);
		return;
	}

	EnterCriticalSection(&global_ram_critical_section);

	bool should_wakeup = false;
	if ((global_total_ram != status.ullTotalPhys) ||
		(global_available_ram != status.ullAvailPhys)) {
		global_total_ram = status.ullTotalPhys;
		global_available_ram = status.ullAvailPhys;
		global_ram_ts++;
		should_wakeup = true;
		printf("Memory information updated\n");
	}

	LeaveCriticalSection(&global_ram_critical_section);
	if (should_wakeup) {
		WakeAllConditionVariable(&global_ram_condition_variable);
	}
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
			case TYPE_FULL_RAM: {
				switch (request.kind) {
					case REQ_UNARY: {
						DWORDLONG value = 0;
						response.error = 0 - get_ram_info(0, &response.ts, &value, NULL, false);
						value /= 1ULL << request.factor;
						response.ram_info.factor = request.factor;
						response.ram_info.value = value;
					} break;

					default: {
						error("unsupported request kind %d", request.kind);
						response.error = ERROR_UNSUPPORTED_REQUEST_KIND;
					} break;
				}
			} break;

			case TYPE_AVAILABLE_RAM: {
				switch (request.kind) {
					case REQ_UNARY: {
						DWORDLONG value = 0;
						response.error = 0 - get_ram_info(0, &response.ts, NULL, &value, false);
						value /= 1ULL << request.factor;
						response.ram_info.factor = request.factor;
						response.ram_info.value = value;
					} break;

					case REQ_TIMER: {
						DWORDLONG value = 0;
						response.error = 0 - get_ram_info(0, &response.ts, NULL, &value, true);
						value /= 1ULL << request.factor;
						response.ram_info.factor = request.factor;
						response.ram_info.value = value;

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
						for (;;) {
							DWORDLONG value = 0;
							response.error = 0 - get_ram_info(response.ts, &response.ts, NULL, &value, false);
							value /= 1ULL << request.factor;
							response.ram_info.factor = request.factor;
							response.ram_info.value = value;

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

static DWORD WINAPI update_ram_info_routine(LPVOID param) {
	(void)param;
	for (;;) {
		update_ram_info();
		Sleep(3000);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: coursework_server_b.exe <port>\n");
		exit(1);
	}

	InitializeCriticalSection(&global_ram_critical_section);
	InitializeConditionVariable(&global_ram_condition_variable);

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

	HANDLE thread = CreateThread(NULL, 0, update_ram_info_routine, NULL, 0, NULL);
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