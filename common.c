#define MAX(x, y) ((x) >= (y) ? (x) : (y))
#define fatal_error(...) do { error(__VA_ARGS__); exit(1); } while (0)

static void error(char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static void* xmalloc(size_t size) {
	void* memory = malloc(size);
	if (!memory) {
		fatal_error("unable to allocate memory");
	}

	return memory;
}

static void* xrealloc(void* block, size_t size) {
	void* memory = realloc(block, size);
	if (!memory) {
		fatal_error("unable to reallocate memory");
	}

	return memory;
}

typedef struct {
	size_t len;
	size_t cap;
} BufHdr;

static BufHdr* buf_hdr(void* buf) {
	return buf ? ((BufHdr*)buf - 1) : NULL;
}

static size_t buf_len(void* buf) {
	return buf ? buf_hdr(buf)->len : 0;
}

static size_t buf_cap(void* buf) {
	return buf ? buf_hdr(buf)->cap : 0;
}

static void buf_grow(void** buf_ptr, size_t new_len, size_t elem_size) {
	void* buf = *buf_ptr;
	size_t new_cap = MAX(new_len, buf_cap(buf) * 2);
	size_t new_size = sizeof(BufHdr) + new_cap * elem_size;
	BufHdr* new_hdr = xrealloc(buf_hdr(buf), new_size);
	if (!buf) {
		new_hdr->len = 0;
	}

	new_hdr->cap = new_cap;
	*buf_ptr = new_hdr + 1;
}

static void buf_free(void* buf_ptr) {
	void* buf = *(void**)buf_ptr;
	free(buf_hdr(buf));
	buf = NULL;
	*(void**)buf_ptr = buf;
}

static void buf_push(void** buf_ptr, void* elem, size_t elem_size) {
	void* buf = *buf_ptr;
	if (buf_len(buf) == buf_cap(buf)) {
		buf_grow(&buf, buf_len(buf) + 1, elem_size);
	}

	memcpy((char*)buf + buf_len(buf) * elem_size, elem, elem_size);
	buf_hdr(buf)->len++;
	*buf_ptr = buf;
}

static void charbuf_push(char** buf_ptr, char character) {
	buf_push((void**)buf_ptr, &character, sizeof(character));
}

static void buf_test(void) {
	size_t* buffer = NULL;
	enum { N = 1024 };
	for (size_t i = 0; i < N; i++) {
		buf_push((void**)&buffer, &i, sizeof(size_t));
	}

	for (size_t i = 0; i < N; i++) {
		assert(buffer[i] == i);
	}

	buf_free(&buffer);
}

#define ARENA_BLOCK_SIZE (1024 * 1024)

typedef struct {
	char* ptr;
	char* end;
	char** blocks;
} Arena;

static void arena_grow(Arena* arena, size_t min_size) {
	size_t size = MAX(min_size, ARENA_BLOCK_SIZE);
	arena->ptr = xmalloc(size);
	arena->end = arena->ptr + size;
	buf_push((void**)&arena->blocks, &arena->ptr, sizeof(char*));
}

static void arena_free(Arena* arena) {
	for (size_t i = 0; i < buf_len(arena->blocks); i++) {
		free(arena->blocks[i]);
	}

	arena->ptr = NULL;
	arena->end = NULL;
	buf_free(&arena->blocks);
}

static void* arena_alloc(Arena* arena, size_t size) {
	// TODO(wkns37): align allocations
	assert(size);
	if (size > (size_t)(arena->end - arena->ptr)) {
		arena_grow(arena, size);
	}

	void* ptr = arena->ptr;
	arena->ptr += size;
	return ptr;
}

static void arena_test(void) {
	Arena arena = { 0 };
	char* str1 = (char*)arena_alloc(&arena, 5);
	str1[0] = '1';
	str1[1] = '2';
	str1[2] = '3';
	str1[3] = '4';
	str1[4] = '\0';
	assert(strcmp(str1, "1234") == 0);

	char* str2 = (char*)arena_alloc(&arena, 9);
	str2[0] = 'a';
	str2[1] = 'b';
	str2[2] = 'c';
	str2[3] = 'd';
	str2[4] = 'e';
	str2[5] = 'f';
	str2[6] = 'g';
	str2[7] = 'h';
	str2[8] = '\0';
	assert(strcmp(str2, "abcdefgh") == 0);

	arena_free(&arena);
}

typedef struct {
	size_t len;
	char* str;
} InternString;

static Arena interns_arena;
static InternString* interns;

static char* str_intern_range(char* start, char* end) {
	size_t len = end - start;
	for (size_t i = 0; i < buf_len(interns); i++) {
		InternString* current = interns + i;
		if ((current->len == len) && !strncmp(current->str, start, len)) {
			return current->str;
		}
	}

	char* str = arena_alloc(&interns_arena, len + 1);
	memcpy(str, start, len);
	str[len] = '\0';
	InternString intern = { len, str };
	buf_push((void**)&interns, &intern, sizeof(InternString));
	return str;
}

static char* str_intern(char* str) {
	return str_intern_range(str, str + strlen(str));
}

static void str_intern_test(void) {
	char a[] = "asdf";
	assert(strcmp(a, str_intern(a)) == 0);
	assert(str_intern(a) == str_intern(a));
	assert(str_intern(str_intern(a)) == str_intern(a));

	char b[] = "asdf";
	assert(a != b);
	assert(str_intern(a) == str_intern(b));

	char c[] = "asdf!";
	assert(str_intern(a) != str_intern(c));

	char d[] = "asd";
	assert(str_intern(a) != str_intern(d));
}

static void common_test(void) {
	buf_test();
	arena_test();
	str_intern_test();
}
