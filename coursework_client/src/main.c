#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

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

static void print_timestamp(SYSTEMTIME time) {
	printf("=== %04hu-%02hu-%02hu %02hu:%02hu:%02hu.%03hu ===\n",
		time.wYear, time.wMonth, time.wDay,
		time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
}

static Request create_request(char* kind, char* type) {
	Request request = { 0 };
	for (RequestKind it = REQ_NONE; it < REQ_COUNT; it++) {
		if (kind_names[it] && !strcmp(kind, kind_names[it])) {
			request.kind = it;
			break;
		}
	}

	for (RequestType it = TYPE_NONE; it < TYPE_COUNT; it++) {
		if (type_names[it] && !strcmp(type, type_names[it])) {
			request.type = it;
			break;
		}
	}

	if (!request.kind) {
		fatal_error("unknown request kind '%s'", kind);
	}

	if (!request.type) {
		fatal_error("unknown request type '%s'", type);
	}

	return request;
}

static Response parse_response(char* buf) {
	Response response = *(Response*)buf;
	print_timestamp(response.time);
	if (response.error) {
		switch (response.error) {
			case ERROR_EMPTY_RESPONSE: break;

			case ERROR_UNSUPPORTED_REQUEST_KIND: {
				error("request kind is not supported by server");
				goto end;
			}

			case ERROR_UNSUPPORTED_REQUEST_TYPE: {
				error("request type is not supported by server");
				goto end;
			}

			default: {
				if (response.error < 0) {
					error("server responded with error code %d", -response.error);
				} else if (response.error != ERROR_EMPTY_RESPONSE) {
					error("unknown response error code %d", response.error);
				}

				goto end;
			} break;
		}
	}

	switch (response.type) {
		case TYPE_HARD_DRIVE_INFO: {
			printf("Hard drives information:");
			if (response.hard_drive_info.count) {
				printf("\n");
				for (uint8_t i = 0; i < response.hard_drive_info.count; i++) {
					DriveInfo* info = response.hard_drive_info.infos + i;
					printf("%c:\\\t%s\n", info->letter, info->fs);
				}
			} else {
				printf(" NONE\n");
			}
		} break;

		case TYPE_CPU_INFO: {
			printf("Server logical CPU cores: %lu\n", response.logical_cpu_count);
		} break;

		case TYPE_FULL_RAM: {
			printf("Server total RAM: %llu %s\n", response.ram_info.value, factor_names[response.ram_info.factor]);
		} break;

		case TYPE_AVAILABLE_RAM: {
			printf("Server available RAM: %llu %s\n", response.ram_info.value, factor_names[response.ram_info.factor]);
		} break;

		default: error("unknown response type %d", response.type); break;
	}

end:
	printf("\n");
	return response;
}

static uint32_t factorize(char* factor) {
	for (char** name = factor_names;
		name != factor_names + sizeof(factor_names) / sizeof(*factor_names);
		name++
		) {

		if (*name && !_stricmp(*name, factor)) {
			return name - factor_names;
		}
	}

	error("unknown factor parameter '%s', using bytes by default", factor);
	return 0;
}

static void print_usage(void) {
	fprintf(stderr,
		"Usage: coursework_client.exe <server> <port> <kind> <command> [<param>]...\n\n"
		"Available commands:\n"
		"    hdinfo             Determines the server's hard drives and their file system.\n"
		"    cpuinfo            Determines the number of logical CPU cores on the server.\n"
		"    flram <factor>     Determines the amount of RAM on the server.\n"
		"    avram <factor>     Determines the free amount of RAM on the server.\n\n"
		"The <kind> parameter is either 'unary', 'timer', or 'reactive'.\n"
		"The <factor> parameter is either 'KB', 'MB', or 'GB'.\n");
	exit(1);
}

int main(int argc, char* argv[]) {
	argc--, argv++;
	if (argc < 4) {
		print_usage();
	}

	char* server = argv[0];
	char* port = argv[1];
	Request request = create_request(argv[2], argv[3]);
	if ((request.type == TYPE_FULL_RAM) ||
		(request.type == TYPE_AVAILABLE_RAM)) {
		if (argc < 5) {
			print_usage();
		}

		request.factor = factorize(argv[4]);
	}

	WSADATA data;
	int result = WSAStartup(MAKEWORD(2, 2), &data);
	if (result) {
		fatal_error("unable to start WSA (code %d)", result);
	}

	struct addrinfo hints = { 0 };
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	struct addrinfo* info;
	result = getaddrinfo(server, port, &hints, &info);
	if (result) {
		error("unable to get address info (code %d)", result);
		WSACleanup();
		return 1;
	}

	SOCKET sock = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	if (sock == INVALID_SOCKET) {
		error("unable to create socket (code %d)", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	result = connect(sock, info->ai_addr, (int)info->ai_addrlen);
	if (result == SOCKET_ERROR) {
		closesocket(sock);
		sock = INVALID_SOCKET;
	}

	freeaddrinfo(info);

	if (sock == INVALID_SOCKET) {
		error("unable to connect to %s:%s (code %d)", server, port, WSAGetLastError());
		WSACleanup();
		return 1;
	}

	char buf[BUFFER_SIZE] = { 0 };
	switch (request.kind) {
		case REQ_UNARY: {
			result = send(sock, (char*)&request, sizeof(Request), 0);
			if (result == SOCKET_ERROR) {
				error("unable to send (code %d)", WSAGetLastError());
				break;
			}

			result = recv(sock, buf, sizeof(buf), 0);
			if (result > 0) {
				parse_response(buf);
			} else if (result < 0) {
				error("unable to receive bytes (code %d)", WSAGetLastError());
			}
		} break;

		case REQ_TIMER: {
			do {
				result = send(sock, (char*)&request, sizeof(Request), 0);
				if (result == SOCKET_ERROR) {
					error("unable to send (code %d)", WSAGetLastError());
					break;
				}

				result = recv(sock, buf, sizeof(buf), 0);
				if (result > 0) {
					Response response = parse_response(buf);
					if (response.error != ERROR_EMPTY_RESPONSE) {
						request.ts = response.ts;
					}
				} else if (result < 0) {
					error("unable to receive bytes (code %d)", WSAGetLastError());
				}

				Sleep(3000);
			} while (result > 0);
		} break;

		case REQ_REACTIVE: {
			result = send(sock, (char*)&request, sizeof(Request), 0);
			if (result == SOCKET_ERROR) {
				error("unable to send (code %d)", WSAGetLastError());
				break;
			}

			do {
				result = recv(sock, buf, sizeof(buf), 0);
				if (result > 0) {
					parse_response(buf);
				} else if (result < 0) {
					error("unable to receive bytes (code %d)", WSAGetLastError());
				}
			} while (result > 0);
		} break;

		default: assert(request.kind == REQ_NONE); break;
	}

	result = shutdown(sock, SD_BOTH);
	if (result == SOCKET_ERROR) {
		error("unable to shutdown socket (code %d)", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	closesocket(sock);
	WSACleanup();
	return 0;
}