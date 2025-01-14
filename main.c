#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#include "debug.h"
#include "allocator.h"
#include "buffer.h"
#include "xstring.h"

#include "ast.h"
#include "token.h"
#include "lexer.h"
#include "parser.h"

#include "test.h"
#include "tau.h"

#ifdef _WIN32
#include "win32.h"
#else
#error Non-Windows systems are not supported yet.
#endif

int main(int argc, char* argv[]) {
	return tau_main(argc, argv);
}
