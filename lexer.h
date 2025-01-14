#pragma once

enum Message {
	MESSAGE_NONE,
	MESSAGE_WARNING,
	MESSAGE_ERROR,
};

//static char* keywords[] = {
//	"typedef",
//	// ...
//};
//
//size_t num_keywords = sizeof(keywords) / sizeof(*keywords);

typedef void on_line_callback(void*, Position);
typedef char* on_str_callback(void*, Position, const char*, size_t);
typedef char* on_name_callback(void*, Position, const char*, size_t);
typedef char* on_message_callback(void*, Position, enum Message, const char*);

struct LexerClient {
	void* data;
	on_line_callback* on_line;
	on_str_callback* on_str;
	on_name_callback* on_name;
	on_message_callback* on_msg;
};

struct Lexer {
	char* str;
	char* start_str;
	Position start_pos;
	struct Token token;
	struct LexerClient client;
};

void lexer_init(struct Lexer* self, Position pos, char* str) {
	assert(self != NULL);
	self->str = str;
	self->start_pos = pos;
	self->start_str = str;
	self->token = (struct Token) { 0 };
	self->client = (struct LexerClient) { 0 };
}

Position lexer_pos(struct Lexer* self) {
	assert(self != NULL);
	return self->start_pos + (Position)(self->str - self->start_str);
}

void lexer_on_line(struct Lexer* self) {
	assert(self != NULL);
	if (self->client.on_line) {
		self->client.on_line(self->client.data, lexer_pos(self));
	}
}

char* lexer_on_str(struct Lexer* self, char* str, size_t len) {
	assert(self != NULL);
	if (self->client.on_str) {
		return self->client.on_str(self->client.data, lexer_pos(self), str, len);
	}
	return NULL;
}

char* lexer_on_name(struct Lexer* self, char* str, size_t len) {
	assert(self != NULL);
	if (self->client.on_name) {
		return self->client.on_name(self->client.data, lexer_pos(self), str, len);
	}
	return NULL;
}

void lexer_on_msg(struct Lexer* self, Position pos, enum Message msg, const char* fmt, va_list args) {
	assert(self != NULL);
	if (self->client.on_msg) {
		self->client.on_msg(self->client.data, pos, msg, strfv(tallocator, fmt, args));
	}
}

void lexer_warning(struct Lexer* self, const char* fmt, ...) {
	assert(self != NULL);
	va_list args;
	va_start(args, fmt);
	lexer_on_msg(self, lexer_pos(self), MESSAGE_WARNING, fmt, args);
	va_end(args);
}

void lexer_error(struct Lexer* self, const char* fmt, ...) {
	assert(self != NULL);
	va_list args;
	va_start(args, fmt);
	lexer_on_msg(self, lexer_pos(self), MESSAGE_ERROR, fmt, args);
	va_end(args);
}

//static uint8_t char_to_digit[256] = {
//	['0'] = 0,
//	// ...
//};

struct Token lexer_next_int(struct Lexer* self) {
	assert(self != NULL);
	return (struct Token) { 0 };
}

struct Token lexer_next_float(struct Lexer* self) {
	assert(self != NULL);
	char* start = self->str;
	char* str = start;
	while (isdigit(*str)) {
		str += 1;
	}
	if (*str == '.') {
		str += 1;
	}
	while (isdigit(*str)) {
		str += 1;
	}
	if (tolower(*str) == 'e') {
		str += 1;
		if ((*str == '+') || (*str == '-')) {
			str += 1;
		}
		if (!isdigit(*str)) {
			lexer_error(self, "Expected digit after float literal explonent, found '%c'.", *str);
		}
		while (isdigit(*str)) {
			str += 1;
		}
	}
	double val = strtod(start, 0);
	if (val == HUGE_VAL) {
		lexer_error(self, "Float literal overflow.");
	}
	enum TokenFlags suffix = TOKEN_NONE;
	if (tolower(*str) == 'd') {
		suffix = TOKEN_D;
		str += 1;
	}
	self->str = str;
	return (struct Token) { .kind = TOKEN_FLOAT, .flags = suffix, .tfloat = val };
}

//static char escape_to_char[256] = {
//	['0'] = '\0',
//	// ...
//};

struct Token lexer_next_hex_escape(struct Lexer* self) {
	assert(self != NULL);
	return (struct Token) { 0 };
}

struct Token lexer_next_char(struct Lexer* self) {
	assert(self != NULL);
	return (struct Token) { 0 };
}

struct Token lexer_next_str(struct Lexer* self) {
	assert(self != NULL);
	return (struct Token) { 0 };
}

struct Token lexer_next_case1(struct Lexer* self, enum TokenKind kind) {
	assert(self != NULL);
	self->str += 1;
	return (struct Token) { 0 };
}

struct Token lexer_next_case2(struct Lexer* self, enum TokenKind kind1, char char2, enum TokenKind kind2) {
	assert(self != NULL);
	self->str += 1;
	return (struct Token) { 0 };
}

struct Token lexer_next_case3(struct Lexer* self, enum TokenKind kind1, char char2, enum TokenKind kind2, char char3, enum TokenKind kind3) {
	assert(self != NULL);
	self->str += 1;
	return (struct Token) { 0 };
}

bool lexer_next(struct Lexer* self) {
	assert(self != NULL);
	struct Token token = { 0 };
repeat:
	char* start = self->str;
	switch (*self->str) {
		case ' ': case '\r': case '\n': case '\t': case '\v': {
			while (isspace(*self->str)) {
				if (*self->str++ == '\n') {
					lexer_on_line(self);
				}
			}
			goto repeat;
		}
		case '\'': {
			token = lexer_next_char(self);
			break;
		}
		case '"': {
			token = lexer_next_str(self);
			break;
		}
		case '.': {
			if (isdigit(self->str[1])) {
				token = lexer_next_float(self);
			} else if ((self->str[1] == '.') && (self->str[2] == '.')) {
				//token.kind = TOKEN_ELLIPSIS;
				//self->str += 3;
			} else {
				//token.kind = TOKEN_DOT;
				//self->str += 1;
			}
			break;
		}
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9': {
			while (isdigit(*self->str)) {
				self->str += 1;
			}
			char c = *self->str;
			self->str = start;
			if ((c == '.') || (tolower(c) == 'e')) {
				token = lexer_next_float(self);
			} else {
				token = lexer_next_int(self);
			}
			break;
		}
		case 'a': case 'b': case 'c': case 'd': case 'e':
		case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o':
		case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E':
		case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O':
		case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
		case '_': {
			while (isalnum(*self->str) || (*self->str == '_')) {
				self->str += 1;
			}
			//token.kind = TOKEN_NAME;
			token.tname = lexer_on_name(self, start, self->str - start);
			break;
		}
		case '\0': {
			token.kind = TOKEN_EOF;
			break;
		}
		default: {
			lexer_error(self, "Invalid character '%c'", *self->str);
			self->str += 1;
			goto repeat;
		}
	}
	token.range = (struct Range) {
		(Position)(self->start_pos + (start - self->start_str)),
		lexer_pos(self)
	};
	self->token = token;
	return token.kind != TOKEN_EOF;
}

void test_on_line(void* data, Position pos) {
	printf("[%03d     ] Line\n", pos);
}

char* test_on_str(void* data, Position pos, const char* str, size_t len) {
	printf("[%03d     ] Str: \"%.*s\"\n", pos, (int)len, str);
	return NULL;
}

char* test_on_name(void* data, Position pos, const char* str, size_t len) {
	printf("[%03d     ] Name: %.*s\n", pos, (int)len, str);
	return NULL;
}
