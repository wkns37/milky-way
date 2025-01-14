#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dbghelp.h>

#pragma comment(lib, "dbghelp.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

void print_stack_trace(CONTEXT ctx) {
	HANDLE process = GetCurrentProcess();
	HANDLE thread = GetCurrentThread();

	SymSetOptions(SymGetOptions() | SYMOPT_DEFERRED_LOADS);
	SymInitialize(process, NULL, TRUE);

#if _M_IX86
	STACKFRAME frame = { 0 };
	frame.AddrPC.Offset = ctx.Eip;
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrFrame.Offset = ctx.Ebp;
	frame.AddrFrame.Mode = AddrModeFlat;
	frame.AddrStack.Offset = ctx.Esp;
	frame.AddrStack.Mode = AddrModeFlat;
	DWORD machine = IMAGE_FILE_MACHINE_I386;

	IMAGEHLP_LINE line = { 0 };
	line.SizeOfStruct = sizeof(IMAGEHLP_LINE);
#elif _M_IA64
	STACKFRAME64 frame = { 0 };
	frame.AddrPC.Offset = ctx.StIIP;
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrFrame.Offset = ctx.RsBSP;
	frame.AddrFrame.Mode = AddrModeFlat;
	frame.AddrBStore.Offset = ctx.RsBSP;
	frame.AddrBStore.Mode = AddrModeFlat;
	frame.AddrStack.Offset = ctx.IntSp;
	frame.AddrStack.Mode = AddrModeFlat;
	DWORD machine = IMAGE_FILE_MACHINE_IA64;

	IMAGEHLP_LINE64 line = { 0 };
	line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
#elif _M_X64
	STACKFRAME64 frame = { 0 };
	frame.AddrPC.Offset = ctx.Rip;
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrFrame.Offset = ctx.Rbp;
	frame.AddrFrame.Mode = AddrModeFlat;
	frame.AddrStack.Offset = ctx.Rsp;
	frame.AddrStack.Mode = AddrModeFlat;
	DWORD machine = IMAGE_FILE_MACHINE_AMD64;

	IMAGEHLP_LINE64 line = { 0 };
	line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
#else
#error Unsupported CPU architecture.
#endif

	enum { MAX_FUNC_NAME_LEN = 2048 };
	char buf[sizeof(SYMBOL_INFO) + MAX_FUNC_NAME_LEN - 1] = { 0 };
	PSYMBOL_INFO symbol = (PSYMBOL_INFO)buf;
	symbol->MaxNameLen = MAX_FUNC_NAME_LEN;
	symbol->SizeOfStruct = sizeof(SYMBOL_INFO);

	fprintf(stderr, "Stack trace:\n");

	// @Threadsafety
	while (StackWalk(machine, process, thread, &frame, &ctx, NULL, NULL, NULL, NULL)) {
		if (SymFromAddr(process, frame.AddrPC.Offset, NULL, symbol)) {
			DWORD displacement = 0;
			if (SymGetLineFromAddr(process, frame.AddrPC.Offset, &displacement, &line)) {
				fprintf(stderr, "  %s(%lu) : %s\n", line.FileName, line.LineNumber, symbol->Name);
			} else {
				fprintf(stderr, "  %s(%lu) : %s\n", "<unknown>", 0, symbol->Name);
			}
		}
	}
}

LONG WINAPI exception_handler(PEXCEPTION_POINTERS exception) {
	PEXCEPTION_RECORD record = exception->ExceptionRecord;
	PCONTEXT context = exception->ContextRecord;
	DWORD code = record->ExceptionCode;
	if (code > 0x80000000L) { // Valuable exceptions only.
		print_stack_trace(*context);
	}
	return EXCEPTION_CONTINUE_SEARCH;
}

void setup_exception_handler(void) {
	AddVectoredExceptionHandler(0, exception_handler);
}

void debug_break(void) {
	__debugbreak();
}

void dump_memory_leaks(void) {
	_CrtDumpMemoryLeaks();
}

void* default_alloc(struct Allocator* self, size_t size) {
	assert(self != NULL);
	return malloc(size);
}

void default_free(struct Allocator* self, void* block) {
	assert(self != NULL);
	free(block);
}

allocator_t* runtime_allocator(unsigned i) {
	switch (i) {
		case 0: {
			static struct Allocator allocator = {
				default_alloc, default_free
			};
			return &allocator;
		} break;

		case 1: {
			enum { N = MiB(1) };
			static char buffer[N];
			static struct BumpAllocator allocator = {
				.base = {bump_alloc, bump_free},
				.ptr = buffer,
				.end = buffer + N
			};
			return &allocator;
		} break;

		default: assert(0); break;
	}
	return NULL;
}
