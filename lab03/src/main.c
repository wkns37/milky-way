#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <windows.h>
#include <tlhelp32.h>

#pragma warning(disable: 4305)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))
#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)

static void error(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static void path_name(char fullpath[_MAX_PATH], char shortpath[_MAX_PATH]) {
	char filename[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath(fullpath, NULL, NULL, filename, ext);
	sprintf(shortpath, "%s%s", filename, ext);
}

static void print_processes(FILE* out) {
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 entry = { sizeof(PROCESSENTRY32) };
	if (Process32First(snapshot, &entry)) {
		do {
			fprintf(out, "%s  (PID: %u)\n", entry.szExeFile, entry.th32ProcessID);
		} while (Process32Next(snapshot, &entry));
	}
}

static void print_threads(FILE* out) {
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	THREADENTRY32 entry = { sizeof(THREADENTRY32) };
	if (Thread32First(snapshot, &entry)) {
		do {
			fprintf(out, "PID: %u  TID: %u  PRI: %ld\n", entry.th32OwnerProcessID, entry.th32ThreadID, entry.tpBasePri);
		} while (Thread32Next(snapshot, &entry));
	}
}

static void print_modules(FILE* out) {
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
	MODULEENTRY32 entry = { sizeof(MODULEENTRY32) };
	if (Module32First(snapshot, &entry)) {
		do {
			fprintf(out, "BaseAddr: %p  Module: %s\n", entry.modBaseAddr, entry.szModule);
		} while (Module32Next(snapshot, &entry));
	}
}

int main(int argc, char* argv[]) {
	argc--;
	argv++;

	char* module_input = NULL;
	char* threads_output_filename = NULL;
	char* processes_output_filename = NULL;
	char* modules_output_filename = NULL;

	switch (argc) {
		case 4: modules_output_filename = argv[3];
		case 3: processes_output_filename = argv[2];
		case 2: threads_output_filename = argv[1];
		case 1: module_input = argv[0]; break;

		default: fatal_error("Usage: lab03.exe (<module-handle> | <module-name> | <module-path>) [<threads-out>] [<processes-out>] [<modules-out>]\n");
	}

	HMODULE module = GetModuleHandleA(module_input);
	if (module == 0) {
		module = (HMODULE)strtoll(module_input, NULL, 0);
		if (module == 0) {
			fatal_error("unable to get module handle, check the program arguments");
		}
	}

	char fullname[_MAX_PATH];
	if (!GetModuleFileNameA(module, fullname, sizeof(fullname) / sizeof(TCHAR))) {
		fatal_error("unable to get handle information (code %lu)", GetLastError());
	}

	char shortname[_MAX_PATH];
	path_name(fullname, shortname);

	DWORD current_process_id = GetCurrentProcessId();
	HANDLE current_process = GetCurrentProcess();
	HANDLE current_process_dup;

	if (!DuplicateHandle(current_process, current_process, current_process, &current_process_dup, 0, FALSE, DUPLICATE_SAME_ACCESS)) {
		fatal_error("unable to duplicate current process (code %lu)", GetLastError());
	}

	if (!CloseHandle(current_process_dup)) {
		fatal_error("unable to close duplicated process (code %lu)", GetLastError());
	}

	HANDLE opened_process = OpenProcess(PROCESS_DUP_HANDLE, TRUE, current_process_id);
	if (!opened_process) {
		fatal_error("unable to open current process (code %lu)", GetLastError());
	}

	if (!CloseHandle(opened_process)) {
		fatal_error("unable to close opened process (code %lu)", GetLastError());
	}

	printf("Module descriptor: %X\n", (int)module);
	printf("Module name:       %s\n", shortname);
	printf("Module full name:  %s\n", fullname);
	printf("Current process identifier: %lu\n", current_process_id);
	printf("Current process:   %p\n", current_process);
	printf("Duplicated handle: %p\n", current_process_dup);
	printf("Opened process:    %p\n", opened_process);

	if (threads_output_filename) {
		FILE* out = fopen(threads_output_filename, "w");
		print_threads(out);
		fclose(out);
	} else {
		printf("\n");
		print_threads(stdout);
	}

	if (processes_output_filename) {
		FILE* out = fopen(processes_output_filename, "w");
		print_processes(out);
		fclose(out);
	} else {
		printf("\n");
		print_processes(stdout);
	}

	if (modules_output_filename) {
		FILE* out = fopen(modules_output_filename, "w");
		print_modules(out);
		fclose(out);
	} else {
		printf("\n");
		print_modules(stdout);
	}

	return 0;
}