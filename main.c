#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>

#include "common.c"
#include "lexer.c"
#include "ast.h"
#include "ast.c"
#include "printer.c"
#include "parser.c"
#include "type.c"
#include "resolver.c"

static void run_tests(void) {
	common_test();
	lexer_test();
	//parser_test();
	resolver_test();
}

int main() {
	init_keywords();
	run_tests();
	return 0;
}
