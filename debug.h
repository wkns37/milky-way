#pragma once

#ifdef NDEBUG
#define assert(expression) ((void)0)
#else
#define assert(expression)				\
	do if (!(expression)) {				\
		fprintf(stderr,					\
			"Assertion failed: %s\n"	\
			"  On file: %s\n"			\
			"  On line: %d\n\n", #expression, __FILE__, __LINE__); \
		debug_break();					\
	} while (0)
#endif

void debug_break(void);
void setup_exception_handler(void);
void dump_memory_leaks(void);
