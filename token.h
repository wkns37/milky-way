#pragma once

typedef uint32_t Position;

struct Range {
	Position start;
	Position end;
};

enum TokenKind {
	TOKEN_EOF,
	TOKEN_INT,
	TOKEN_FLOAT,
	// ...
};

static char* kind_names[] = {
	[TOKEN_EOF] = "EOF",
	[TOKEN_INT] = "INT",
	[TOKEN_FLOAT] = "FLOAT",
	// ...
};

char* token_kind_name(enum TokenKind kind) {
	if (kind < ARRAY_SIZE(kind_names)) {
		return kind_names[kind];
	} else {
		return "<unknown>";
	}
}

enum TokenFlags {
	TOKEN_NONE,
	TOKEN_D,
	// ...
};

static char* suffix_names[] = {
	[TOKEN_NONE] = "",
	[TOKEN_D] = "d",
	// ...
};

struct Token {
	enum TokenKind kind;
	enum TokenFlags flags;
	struct Range range;
	union {
		char* tname;
		char* tstr;
		uint64_t tint;
		double tfloat;
	};
};

char* token_repr(struct Token token) {
	return token_kind_name(token.kind);
}
