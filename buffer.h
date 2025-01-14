#pragma once

struct BufHdr {
	size_t len;
	size_t cap;
	allocator_t* allocator;
};

struct BufHdr* buf_hdr(void* buf) {
	return buf ? (struct BufHdr*)buf - 1 : NULL;
}

size_t buf_len(void* buf) {
	return buf ? buf_hdr(buf)->len : 0;
}

size_t buf_cap(void* buf) {
	return buf ? buf_hdr(buf)->cap : 0;
}

allocator_t* buf_allocator(void* buf) {
	return buf ? buf_hdr(buf)->allocator : pallocator;
}

void* buf_new(allocator_t* allocator) {
	struct BufHdr* new_hdr = xalloc(allocator, sizeof(*new_hdr));
	assert(new_hdr != NULL);
	new_hdr->len = 0;
	new_hdr->cap = 0;
	new_hdr->allocator = allocator;
	return new_hdr + 1;
}

void buf_grow(void** buf_ptr, size_t new_len, size_t elem_size) {
	assert(buf_ptr != NULL);
	void* buf = *buf_ptr;
	if (new_len < 16) {
		new_len = 16;
	}
	new_len = (size_t)next_pow2(new_len);
	size_t new_cap = MAX(2 * buf_cap(buf), new_len);
	size_t new_size = new_cap * elem_size + sizeof(struct BufHdr);
	struct BufHdr* new_hdr = xalloc(buf_allocator(buf), new_size);
	assert(new_hdr != NULL);
	new_hdr->len = buf_len(buf);
	new_hdr->cap = new_cap;
	new_hdr->allocator = buf_allocator(buf);
	if (buf) {
		memcpy(new_hdr + 1, buf, buf_len(buf) * elem_size);
		xfree(buf_allocator(buf), buf_hdr(buf));
	}
	*buf_ptr = new_hdr + 1;
}

void buf_free(void* buf_ptr) {
	assert(buf_ptr != NULL);
	void* buf = *(void**)buf_ptr;
	xfree(buf_allocator(buf), buf_hdr(buf));
	*(void**)buf_ptr = NULL;
}

void buf_push(void** buf_ptr, void* elem, size_t elem_size) {
	assert(buf_ptr != NULL);
	void* buf = *buf_ptr;
	if (buf_len(buf) == buf_cap(buf)) {
		buf_grow(&buf, buf_len(buf) + 1, elem_size);
	}
	assert(elem != NULL);
	memcpy((char*)buf + buf_len(buf) * elem_size, elem, elem_size);
	buf_hdr(buf)->len++;
	*buf_ptr = buf;
}

#define buf_push_val(buf_ptr, type, val) buf_push((void**)(buf_ptr), &(type){(val)}, sizeof(type))
#define buf_push_ptr(buf_ptr, type, ptr) buf_push((void**)(buf_ptr), (type*)(ptr), sizeof(type))
#define buf_reserve(buf_ptr, type, count) buf_grow((void**)(buf_ptr), (count), sizeof(type))
