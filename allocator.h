#pragma once

#define MAX(x, y) ((x) >= (y) ? (x) : (y))
#define KiB(x) ((x) << 10)
#define MiB(x) ((x) << 20)
#define GiB(x) ((x) << 30)

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

uint64_t next_pow2(uint64_t v) {
	if (!v) {
		return 1;
	}
	v -= 1;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	return v + 1;
}

typedef void allocator_t;
typedef void* alloc_t(allocator_t*, size_t);
typedef void free_t(allocator_t*, void*);

allocator_t* runtime_allocator(unsigned i);

struct Allocator {
	alloc_t* alloc;
	free_t* free;
};

struct Allocator allocator_base(alloc_t* alloc, free_t* free) {
	struct Allocator self = { 0 };
	self.alloc = alloc;
	self.free = free;
	return self;
}

void* xalloc(allocator_t* allocator, size_t size) {
	if (!size || !allocator) {
		return NULL;
	}
	struct Allocator* self = allocator;
	return self->alloc(self, size);
}

void xfree(allocator_t* allocator, void* block) {
	if (!block || !allocator) {
		return;
	}
	struct Allocator* self = allocator;
	self->free(self, block);
}

#define pallocator (runtime_allocator(0))
#define tallocator (runtime_allocator(1))

void* palloc(size_t size) {
	return xalloc(pallocator, size);
}

void pfree(void* block) {
	xfree(pallocator, block);
}

void* talloc(size_t size) {
	return xalloc(tallocator, size);
}

struct BumpAllocator {
	struct Allocator base;
	char* ptr;
	char* end;
};

void* bump_alloc(struct BumpAllocator* self, size_t size) {
	assert(self != NULL);
	assert(size > 0);
	if (size > (size_t)(self->end - self->ptr)) {
		return NULL;
	}
	void* ptr = self->ptr;
	self->ptr += size;
	return ptr;
}

void bump_free(struct BumpAllocator* self, void* block) {
	assert(self != NULL);
	return;
}

struct BumpAllocator bump_allocator(void* block, size_t block_size) {
	struct BumpAllocator self = { 0 };
	self.base = allocator_base(bump_alloc, bump_free);
	self.ptr = block;
	self.end = self.ptr + block_size;
	return self;
}

struct StackAllocator {
	struct Allocator base;
	char* start;
	char* ptr;
	char* end;
	allocator_t* allocator;
};

struct StackBlockHeader {
	size_t block_size;
};

void stack_alloc_init(struct StackAllocator* self) {
	assert(self != NULL);
	size_t block_size = self->end - self->start;
	self->start = xalloc(self->allocator, block_size);
	assert(self->start != NULL);
	self->ptr = self->start;
	self->end = self->start + block_size;
}

void* stack_alloc(struct StackAllocator* self, size_t size) {
	assert(self != NULL);
	assert(size > 0);
	if (!self->start) {
		stack_alloc_init(self);
	}
	size_t extra = sizeof(struct StackBlockHeader);
	if (size + extra > (size_t)(self->end - self->ptr)) {
		return NULL;
	}
	struct StackBlockHeader* header = (void*)self->ptr;
	header->block_size = size;
	self->ptr += size + extra;
	return header + 1;
}

void stack_free(struct StackAllocator* self, void* block) {
	assert(self != NULL);
	char* ptr = block;
	if ((self->start < ptr) && (ptr < self->end)) {
		struct StackBlockHeader* header = (void*)(ptr - sizeof(*header));
		if (ptr + header->block_size == self->ptr) {
			self->ptr = (char*)header;
		}
	}
}

struct StackAllocator stack_allocator(allocator_t* allocator, size_t block_size) {
	struct StackAllocator self = { 0 };
	self.base = allocator_base(stack_alloc, stack_free);
	self.start = NULL;
	self.ptr = self.start;
	self.end = self.start + block_size;
	self.allocator = allocator;
	return self;
}

void stack_alloc_free(struct StackAllocator* self) {
	assert(self != NULL);
	xfree(self->allocator, self->start);
}

void stack_alloc_dump(struct StackAllocator* self) {
	assert(self != NULL);
	size_t block_size = self->end - self->start;
	size_t bytes_in_usage = self->ptr - self->start;
	double usage_percent = 100. * bytes_in_usage / block_size;
	fprintf(stderr, "Stack 0x%p, block size %zu bytes:\n", self, block_size);

	char* ptr = self->start;
	if (ptr < self->ptr) {
		while (ptr < self->ptr) {
			struct StackBlockHeader* header = (void*)ptr;
			fprintf(stderr, "  Block at 0x%p: %zu bytes\n", header + 1, header->block_size);
			ptr += sizeof(*header) + header->block_size;
		}
		assert(ptr == self->ptr);
		fprintf(stderr, "  Total: %zu bytes allocated (%.1f%% usage)\n", bytes_in_usage, usage_percent);
	} else {
		fprintf(stderr, "  No allocations\n");
	}
}
