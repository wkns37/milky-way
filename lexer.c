#define KEYWORD(x) x##_keyword = str_intern(#x)

static char* first_keyword;
static char* last_keyword;

static char* var_keyword;
static char* struct_keyword;
static char* union_keyword;
static char* func_keyword;
static char* if_keyword;
static char* else_keyword;
static char* do_keyword;
static char* while_keyword;
static char* for_keyword;
static char* switch_keyword;
static char* case_keyword;
static char* default_keyword;
static char* cast_keyword;

static void init_keywords(void) {
	static bool inited = false;
	if (inited) {
		return;
	}

	KEYWORD(var);
	KEYWORD(struct);
	KEYWORD(union);
	KEYWORD(func);
	KEYWORD(if);
	KEYWORD(else);
	KEYWORD(do);
	KEYWORD(while);
	KEYWORD(for);
	KEYWORD(switch);
	KEYWORD(case);
	KEYWORD(default);
	KEYWORD(cast);
	first_keyword = var_keyword;
	last_keyword = cast_keyword;

	inited = true;
}

static bool is_keyword_name(char* name) {
	return (first_keyword <= name) && (name <= last_keyword);
}

typedef enum {
	TOKEN_EOF,
	TOKEN_INT,
	TOKEN_FLOAT,
	TOKEN_STR,
	TOKEN_NAME,
	TOKEN_KEYWORD,

	TOKEN_NOT,
	TOKEN_NEG,
	TOKEN_QUESTION,
	TOKEN_COMMA,
	TOKEN_COLON,
	TOKEN_SEMICOLON,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,

	TOKEN_FIRST_MUL,
	TOKEN_MUL = TOKEN_FIRST_MUL,
	TOKEN_DIV,
	TOKEN_MOD,
	TOKEN_AND,
	TOKEN_LSHIFT,
	TOKEN_RSHIFT,
	TOKEN_LAST_MUL = TOKEN_RSHIFT,

	TOKEN_FIRST_ADD,
	TOKEN_PLUS = TOKEN_FIRST_ADD,
	TOKEN_MINUS,
	TOKEN_XOR,
	TOKEN_OR,
	TOKEN_LAST_ADD = TOKEN_OR,

	TOKEN_FIRST_CMP,
	TOKEN_EQ = TOKEN_FIRST_CMP,
	TOKEN_NOTEQ,
	TOKEN_LT,
	TOKEN_GT,
	TOKEN_LTEQ,
	TOKEN_LAST_CMP,
	TOKEN_GTEQ = TOKEN_LAST_CMP,

	TOKEN_AND_AND,
	TOKEN_OR_OR,

	TOKEN_FIRST_ASSIGN,
	TOKEN_ASSIGN = TOKEN_FIRST_ASSIGN,
	TOKEN_MUL_ASSIGN,
	TOKEN_DIV_ASSIGN,
	TOKEN_MOD_ASSIGN,
	TOKEN_AND_ASSIGN,
	TOKEN_LSHIFT_ASSIGN,
	TOKEN_RSHIFT_ASSIGN,
	TOKEN_PLUS_ASSIGN,
	TOKEN_MINUS_ASSIGN,
	TOKEN_XOR_ASSIGN,
	TOKEN_OR_ASSIGN,
	TOKEN_LAST_ASSIGN = TOKEN_OR_ASSIGN,

	TOKEN_INC,
	TOKEN_DEC
} TokenKind;

typedef enum {
	TOKENMOD_NONE,
	TOKENMOD_BIN,
	TOKENMOD_OCT,
	TOKENMOD_HEX,
	TOKENMOD_CHAR
} TokenMod;

typedef struct {
	TokenKind kind;
	TokenMod mod;
	union {
		uint64_t int_val;
		double float_val;
		char* str_val;
		char* name;
	};
} Token;

static char* token_kind_names[] = {
	[TOKEN_EOF] = "<eof>",
	[TOKEN_INT] = "int",
	[TOKEN_FLOAT] = "float",
	[TOKEN_STR] = "string",
	[TOKEN_NAME] = "name",
	[TOKEN_KEYWORD] = "keyword",
	[TOKEN_NOT] = "!",
	[TOKEN_NEG] = "~",
	[TOKEN_QUESTION] = "?",
	[TOKEN_COMMA] = ",",
	[TOKEN_COLON] = ":",
	[TOKEN_SEMICOLON] = ";",
	[TOKEN_LPAREN] = "(",
	[TOKEN_RPAREN] = ")",
	[TOKEN_LBRACE] = "{",
	[TOKEN_RBRACE] = "}",
	[TOKEN_MUL] = "*",
	[TOKEN_DIV] = "/",
	[TOKEN_MOD] = "%",
	[TOKEN_AND] = "&",
	[TOKEN_LSHIFT] = "<<",
	[TOKEN_RSHIFT] = ">>",
	[TOKEN_PLUS] = "+",
	[TOKEN_MINUS] = "-",
	[TOKEN_XOR] = "^",
	[TOKEN_OR] = "|",
	[TOKEN_EQ] = "==",
	[TOKEN_NOTEQ] = "!=",
	[TOKEN_LT] = "<",
	[TOKEN_GT] = ">",
	[TOKEN_LTEQ] = "<=",
	[TOKEN_GTEQ] = ">=",
	[TOKEN_AND_AND] = "&&",
	[TOKEN_OR_OR] = "||",
	[TOKEN_ASSIGN] = "=",
	[TOKEN_MUL_ASSIGN] = "*=",
	[TOKEN_DIV_ASSIGN] = "/=",
	[TOKEN_MOD_ASSIGN] = "%=",
	[TOKEN_AND_ASSIGN] = "&=",
	[TOKEN_LSHIFT_ASSIGN] = "<<=",
	[TOKEN_RSHIFT_ASSIGN] = ">>=",
	[TOKEN_PLUS_ASSIGN] = "+=",
	[TOKEN_MINUS_ASSIGN] = "-=",
	[TOKEN_XOR_ASSIGN] = "^=",
	[TOKEN_OR_ASSIGN] = "|=",
	[TOKEN_INC] = "++",
	[TOKEN_DEC] = "--"
};

static char* token_kind_name(TokenKind kind) {
	if (kind < sizeof(token_kind_names) / sizeof(token_kind_names[0])) {
		return token_kind_names[kind];
	} else {
		return "<unknown>";
	}
}

static char* stream;
static Token token;

static char char_to_escape[256] = {
	['r'] = '\r',
	['n'] = '\n',
	['t'] = '\t',
	['v'] = '\v',
	['a'] = '\a',
	['b'] = '\b',
};

static uint8_t char_to_digit[256] = {
	['0'] = 0,
	['1'] = 1,
	['2'] = 2,
	['3'] = 3,
	['4'] = 4,
	['5'] = 5,
	['6'] = 6,
	['7'] = 7,
	['8'] = 8,
	['9'] = 9,
	['a'] = 10,['A'] = 10,
	['b'] = 11,['B'] = 11,
	['c'] = 12,['C'] = 12,
	['d'] = 13,['D'] = 13,
	['e'] = 14,['E'] = 14,
	['f'] = 15,['F'] = 15
};

static void scan_char(void) {
	stream++;
	char value = '\0';
	if (*stream == '\'') {
		fatal_error("char literal cannot be empty");
	} else if (*stream == '\n') {
		fatal_error("char literal cannot contain newline");
	} else if (*stream == '\\') {
		stream++;
		value = char_to_escape[(unsigned char)*stream];
		if ((value == '\0') && (*stream != '0')) {
			fatal_error("invalid char literal escape '\\%c'", *stream);
		}

		stream++;
	} else {
		value = *stream++;
	}

	if (*stream != '\'') {
		fatal_error("expected closing char quote, got '%c'", *stream);
	} else {
		stream++;
	}

	token.kind = TOKEN_INT;
	token.mod = TOKENMOD_CHAR;
	token.int_val = value;
}

static void scan_str(void) {
	stream++;
	char* str = NULL; // TODO(wkns37): causes a memory leak
	while (*stream && (*stream != '"')) {
		char value = *stream;
		if (*stream == '\n') {
			fatal_error("char literal cannot contain newline");
		} else if (*stream == '\\') {
			stream++;
			value = char_to_escape[(unsigned char)*stream];
			if ((value == '\0') && (*stream != '0')) {
				error("invalid string literal escape '\\%c'", *stream);
			}
		}

		charbuf_push(&str, value);
		stream++;
	}

	if (*stream) {
		if (*stream != '"') {
			fatal_error("expected closing string quote, got '%c'", *stream);
		} else {
			stream++;
		}
	} else {
		error("unexpected end of file within quoted string literal");
	}

	charbuf_push(&str, '\0');
	token.kind = TOKEN_STR;
	token.str_val = str;
}

static void scan_float(void) {
	char* scan = stream;
	while (isdigit(*stream)) {
		stream++;
	}

	if (*stream == '.') {
		stream++;
	}

	while (isdigit(*stream)) {
		stream++;
	}

	if (tolower(*stream) == 'e') {
		stream++;
		if ((*stream == '+') || (*stream == '-')) {
			stream++;
		}

		if (!isdigit(*stream)) {
			fatal_error("expected digit after float literal exponent, found '%c'", *stream);
		}

		while (isdigit(*stream)) {
			stream++;
		}
	}

	double value = strtod(scan, NULL);
	if (value == HUGE_VAL) {
		fatal_error("float literal overflow");
	}

	token.kind = TOKEN_FLOAT;
	token.float_val = value;
}

static void scan_int(void) {
	uint64_t base = 10;
	if (*stream == '0') {
		stream++;
		if (tolower(*stream) == 'x') {
			base = 16;
			token.mod = TOKENMOD_HEX;
			stream++;
		} else if (tolower(*stream) == 'b') {
			base = 2;
			token.mod = TOKENMOD_BIN;
			stream++;
		} else if (isdigit(*stream)) {
			base = 8;
			token.mod = TOKENMOD_OCT;
		}
	}

	uint64_t value = 0;
	for (;;) {
		if (*stream == '_') {
			stream++;
		}

		uint8_t digit = char_to_digit[(unsigned char)*stream];
		if ((digit == 0) && (*stream != '0')) {
			break;
		}

		if (digit >= base) {
			fatal_error("digit '%c' is out of range for base %" PRIu64, *stream, base);
		}

		if (value > (UINT64_MAX - digit) / base) {
			fatal_error("integer literal overflow");
		}

		value = value * base + digit;
		stream++;
	}

	token.kind = TOKEN_INT;
	token.int_val = value;
}

static void next_case1(TokenKind k1) {
	token.kind = k1;
	stream++;
}

static void next_case2(TokenKind k1, char c2, TokenKind k2) {
	token.kind = k1;
	stream++;
	if (*stream == c2) {
		token.kind = k2;
		stream++;
	}
}

static void next_case3(TokenKind k1, char c2, TokenKind k2, char c3, TokenKind k3) {
	token.kind = k1;
	stream++;
	if (*stream == c2) {
		token.kind = k2;
		stream++;
	} else if (*stream == c3) {
		token.kind = k3;
		stream++;
	}
}

static void next_token(void) {
retry:
	switch (*stream) {
		case '\0': {
			token.kind = TOKEN_EOF;
		} break;

		case ' ': case '\r': case '\n': case '\t': case '\v': {
			while (isspace(*stream)) {
				stream++;
			}

			goto retry;
		} break;

		case '\'': {
			scan_char();
		} break;

		case '"': {
			scan_str();
		} break;

		case '.': {
			scan_float();
		} break;

		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
			char* scan = stream;
			while (isdigit(*scan)) {
				scan++;
			}

			if ((*scan == '.') || (tolower(*scan) == 'e')) {
				scan_float();
			} else {
				scan_int();
			}
		} break;

		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
		case '_': {
			char* start = stream;
			while (isalnum(*stream) || (*stream == '_')) {
				stream++;
			}

			char* name = str_intern_range(start, stream);
			token.kind = is_keyword_name(name) ? TOKEN_KEYWORD : TOKEN_NAME;
			token.name = name;
		} break;

		case '!': { next_case2(TOKEN_NOT, '=', TOKEN_NOTEQ); } break;
		case '~': { next_case1(TOKEN_NEG); } break;
		case '?': { next_case1(TOKEN_QUESTION); } break;
		case ',': { next_case1(TOKEN_COMMA); } break;
		case ':': { next_case1(TOKEN_COLON); } break;
		case ';': { next_case1(TOKEN_SEMICOLON); } break;
		case '(': { next_case1(TOKEN_LPAREN); } break;
		case ')': { next_case1(TOKEN_RPAREN); } break;
		case '{': { next_case1(TOKEN_LBRACE); } break;
		case '}': { next_case1(TOKEN_RBRACE); } break;
		case '*': { next_case2(TOKEN_MUL, '=', TOKEN_MUL_ASSIGN); } break;
		case '/': { next_case2(TOKEN_DIV, '=', TOKEN_DIV_ASSIGN); } break;
		case '%': { next_case2(TOKEN_MOD, '=', TOKEN_MOD_ASSIGN); } break;
		case '&': { next_case3(TOKEN_AND, '=', TOKEN_AND_ASSIGN, '&', TOKEN_AND_AND); } break;
		case '+': { next_case3(TOKEN_PLUS, '=', TOKEN_PLUS_ASSIGN, '+', TOKEN_INC); } break;
		case '-': { next_case3(TOKEN_MINUS, '=', TOKEN_MINUS_ASSIGN, '-', TOKEN_DEC); } break;
		case '^': { next_case2(TOKEN_XOR, '=', TOKEN_XOR_ASSIGN); } break;
		case '|': { next_case3(TOKEN_OR, '=', TOKEN_OR_ASSIGN, '|', TOKEN_OR_OR); } break;
		case '=': { next_case2(TOKEN_ASSIGN, '=', TOKEN_EQ); } break;

		case '<': {
			token.kind = TOKEN_LT;
			stream++;
			if (*stream == '=') {
				token.kind = TOKEN_LTEQ;
				stream++;
			} else if (*stream == '<') {
				token.kind = TOKEN_LSHIFT;
				stream++;
				if (*stream == '=') {
					token.kind = TOKEN_LSHIFT_ASSIGN;
					stream++;
				}
			}
		} break;

		case '>': {
			token.kind = TOKEN_GT;
			stream++;
			if (*stream == '=') {
				token.kind = TOKEN_GTEQ;
				stream++;
			} else if (*stream == '>') {
				token.kind = TOKEN_RSHIFT;
				stream++;
				if (*stream == '=') {
					token.kind = TOKEN_RSHIFT_ASSIGN;
					stream++;
				}
			}
		} break;

		default: {
			error("invalid '%c' token, skipping", *stream);
			stream++;
			goto retry;
		} break;
	}
}

static void init_stream(char* source) {
	stream = source;
	next_token();
}

static bool is_token(TokenKind kind) {
	return token.kind == kind;
}

static bool is_token_eof(void) {
	return is_token(TOKEN_EOF);
}

static bool match_token(TokenKind kind) {
	if (is_token(kind)) {
		next_token();
		return true;
	} else {
		return false;
	}
}

static bool is_keyword(char* name) {
	return is_token(TOKEN_KEYWORD) && (token.name == name);
}

static bool match_keyword(char* name) {
	if (is_keyword(name)) {
		next_token();
		return true;
	} else {
		return false;
	}
}

static void expect_token(TokenKind kind) {
	if (!match_token(kind)) {
		fatal_error("expected token %s, got %s\n", token_kind_name(kind), token_kind_name(token.kind));
	}
}

#define assert_token(x) assert(match_token(x))
#define assert_token_int(x) assert((token.int_val == (x)) && match_token(TOKEN_INT))
#define assert_token_float(x) assert((token.float_val == (x)) && match_token(TOKEN_FLOAT))
#define assert_token_str(x) assert(!strcmp(token.str_val, (x)) && match_token(TOKEN_STR))
#define assert_token_name(x) assert(!strcmp(token.name, (x)) && match_token(TOKEN_NAME))
#define assert_token_keyword(x) assert(match_keyword(x))
#define assert_token_eof() assert(is_token(TOKEN_EOF))

static void lexer_test(void) {
	init_stream("18446744073709551615 0xffffffffffffffff 1_000_000 033");
	assert_token_int(UINT64_MAX);
	assert_token_int(UINT64_MAX);
	assert_token_int(1000000);
	assert_token_int(033);
	assert_token_eof();

	init_stream("3.14 .123 3e10");
	assert_token_float(3.14);
	assert_token_float(.123);
	assert_token_float(3e10);
	assert_token_eof();

	init_stream("'a' '\\n'");
	assert_token_int('a');
	assert_token_int('\n');
	assert_token_eof();

	init_stream("\"asdfasdf\" \"adsf123\\r\\nxcv\"");
	assert_token_str("asdfasdf");
	assert_token_str("adsf123\r\nxcv");
	assert_token_eof();

	init_stream("a b c d");
	assert_token_name("a");
	assert_token_name("b");
	assert_token_name("c");
	assert_token_name("d");
	assert_token_eof();

	init_stream("! ~ ? , : ; ( ) { } * / % & << >> + - ^ | == != < > <= >= && || = *= /= %= &= <<= >>= += -= ^= |= ++ --");
	assert_token(TOKEN_NOT);
	assert_token(TOKEN_NEG);
	assert_token(TOKEN_QUESTION);
	assert_token(TOKEN_COMMA);
	assert_token(TOKEN_COLON);
	assert_token(TOKEN_SEMICOLON);
	assert_token(TOKEN_LPAREN);
	assert_token(TOKEN_RPAREN);
	assert_token(TOKEN_LBRACE);
	assert_token(TOKEN_RBRACE);
	assert_token(TOKEN_MUL);
	assert_token(TOKEN_DIV);
	assert_token(TOKEN_MOD);
	assert_token(TOKEN_AND);
	assert_token(TOKEN_LSHIFT);
	assert_token(TOKEN_RSHIFT);
	assert_token(TOKEN_PLUS);
	assert_token(TOKEN_MINUS);
	assert_token(TOKEN_XOR);
	assert_token(TOKEN_OR);
	assert_token(TOKEN_EQ);
	assert_token(TOKEN_NOTEQ);
	assert_token(TOKEN_LT);
	assert_token(TOKEN_GT);
	assert_token(TOKEN_LTEQ);
	assert_token(TOKEN_GTEQ);
	assert_token(TOKEN_AND_AND);
	assert_token(TOKEN_OR_OR);
	assert_token(TOKEN_ASSIGN);
	assert_token(TOKEN_MUL_ASSIGN);
	assert_token(TOKEN_DIV_ASSIGN);
	assert_token(TOKEN_MOD_ASSIGN);
	assert_token(TOKEN_AND_ASSIGN);
	assert_token(TOKEN_LSHIFT_ASSIGN);
	assert_token(TOKEN_RSHIFT_ASSIGN);
	assert_token(TOKEN_PLUS_ASSIGN);
	assert_token(TOKEN_MINUS_ASSIGN);
	assert_token(TOKEN_XOR_ASSIGN);
	assert_token(TOKEN_OR_ASSIGN);
	assert_token(TOKEN_INC);
	assert_token(TOKEN_DEC);
	assert_token_eof();

	init_stream("var struct union func if else do while for switch case default cast");
	assert_token_keyword(var_keyword);
	assert_token_keyword(struct_keyword);
	assert_token_keyword(union_keyword);
	assert_token_keyword(func_keyword);
	assert_token_keyword(if_keyword);
	assert_token_keyword(else_keyword);
	assert_token_keyword(do_keyword);
	assert_token_keyword(while_keyword);
	assert_token_keyword(for_keyword);
	assert_token_keyword(switch_keyword);
	assert_token_keyword(case_keyword);
	assert_token_keyword(default_keyword);
	assert_token_keyword(cast_keyword);
	assert_token_eof();
}

#undef assert_token
#undef assert_token_int
#undef assert_token_float
#undef assert_token_str
#undef assert_token_name
#undef assert_token_keyword
#undef assert_token_eof
