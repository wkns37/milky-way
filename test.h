#pragma once

void allocator_test(void) {
	// @Refactor: Should write more robust tests.
	// Related: https://lukasatkinson.de/2024/allocator-testing/

	{
		struct StackAllocator allocator =
			stack_allocator(pallocator, KiB(256));

		char* ptr = xalloc(&allocator, 5);
		assert(ptr != NULL);

		ptr = xalloc(&allocator, KiB(128));
		assert(ptr != NULL);

		ptr = xalloc(&allocator, MiB(1));
		assert(ptr == NULL);

		ptr = xalloc(&allocator, 30);
		assert(ptr != NULL);

		stack_alloc_free(&allocator);
	}

	{
		// ...
	}
}

void buf_test(void) {
	{
		char* buf = NULL;

		buf_push_val(&buf, char, 'H');
		buf_push_val(&buf, char, 'e');
		buf_push_val(&buf, char, 'l');
		buf_push_val(&buf, char, 'l');
		buf_push_val(&buf, char, 'o');
		buf_push_val(&buf, char, '\0');

		assert(!strcmp(buf, "Hello"));
		buf_free(&buf);
		assert(buf == NULL);
	}

	{
		struct StackAllocator allocator =
			stack_allocator(pallocator, KiB(8));

		int* buf = buf_new(&allocator);

		enum { N = 1024 };
		buf_reserve(&buf, int, N);

		for (int i = 0; i < N; i++) {
			buf_push_ptr(&buf, int, &i);
		}

		for (int i = 0; i < N; i++) {
			assert(buf[i] == i);
		}

		buf_free(&buf);
		assert(buf == NULL);

		stack_alloc_free(&allocator);
	}
}

void lexer_test(void) {
	char* src = "a b c 123";

	struct Lexer lexer;
	lexer_init(&lexer, 0, src);
	while (lexer_next(&lexer)) {
		printf("%s\n", token_repr(lexer.token));
	}
}

void run_tests(void) {
	allocator_test();
	buf_test();
	lexer_test();
}
