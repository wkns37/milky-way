#pragma once

char* strfv(allocator_t* allocator, const char* fmt, va_list args) {
	size_t len = vsnprintf(NULL, 0, fmt, args) + 1;
	char* str = xalloc(allocator, len);
	assert(str != NULL);
	vsnprintf(str, len, fmt, args);
	return str;
}

char* strf(allocator_t* allocator, const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char* str = strfv(allocator, fmt, args);
	va_end(args);
	return str;
}

char* sdup(allocator_t* allocator, const char* str) {
	size_t len = strlen(str);
	char* dup = xalloc(allocator, len + 1);
	assert(dup != NULL);
	memcpy(dup, str, len);
	dup[len] = '\0';
	return dup;
}

char* read_entire_file(allocator_t* allocator, char* path) {
	FILE* file = fopen(path, "rb");
	if (!file) {
		return NULL;
	}
	fseek(file, 0, SEEK_END);
	long len = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = xalloc(allocator, len + 1);
	assert(buffer != NULL);
	if (fread(buffer, len, 1, file) != 1) {
		fclose(file);
		return NULL;
	}
	buffer[len] = '\0';
	fclose(file);
	return buffer;
}
