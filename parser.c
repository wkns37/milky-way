static Expr* parse_expr_unary(void);
static Expr* parse_expr(void);
static Aggregate* parse_aggregate(AggregateKind kind);
static StmtList* parse_stmt_block(void);
static Stmt* parse_stmt(void);

static Typespec* parse_typespec(void) {
	if (is_token(TOKEN_NAME)) {
		Typespec* typespec = new_typespec_name(token.name);
		next_token();
		return typespec;
	} else {
		// TODO(wkns37): print type information
		fatal_error("unexpected token %s in type", token_kind_name(token.kind));
	}
}

static Expr* parse_expr_operand(void) {
	if (is_token(TOKEN_INT)) {
		Expr* expr = new_expr_int(token.int_val);
		next_token();
		return expr;
	} else if (is_token(TOKEN_FLOAT)) {
		Expr* expr = new_expr_float(token.float_val);
		next_token();
		return expr;
	} else if (is_token(TOKEN_STR)) {
		Expr* expr = new_expr_str(token.str_val);
		next_token();
		return expr;
	} else if (is_token(TOKEN_NAME)) {
		Expr* expr = new_expr_name(token.name);
		next_token();
		return expr;
	} else if (match_token(TOKEN_LPAREN)) {
		Expr* expr = parse_expr();
		expect_token(TOKEN_RPAREN);
		return expr;
	} else if (match_keyword(cast_keyword)) {
		expect_token(TOKEN_LPAREN);
		Typespec* typespec = parse_typespec();
		expect_token(TOKEN_RPAREN);
		return new_expr_cast(typespec, parse_expr_unary());
	} else {
		fatal_error("unexpected token %s in expression", token_kind_name(token.kind));
	}
}

static Expr* parse_expr_base(void) {
	Expr* expr = parse_expr_operand();
	while (match_token(TOKEN_LPAREN)) {
		Expr** args = NULL;
		if (!is_token(TOKEN_RPAREN)) {
			do {
				Expr* arg = parse_expr();
				buf_push((void**)&args, &arg, sizeof(Expr*));
			} while (!is_token_eof() && match_token(TOKEN_COMMA));
		}

		expect_token(TOKEN_RPAREN);
		expr = new_expr_call(expr, args, buf_len(args));
	}

	return expr;
}

static inline bool is_unary_op(void) {
	return is_token(TOKEN_NOT) ||
		is_token(TOKEN_NEG) ||
		is_token(TOKEN_MUL) ||
		is_token(TOKEN_AND) ||
		is_token(TOKEN_PLUS) ||
		is_token(TOKEN_MINUS);
}

static Expr* parse_expr_unary(void) {
	if (is_unary_op()) {
		TokenKind op = token.kind;
		next_token();
		return new_expr_unary(op, parse_expr_unary());
	} else {
		return parse_expr_base();
	}
}

static inline bool is_mul_op(void) {
	return (TOKEN_FIRST_MUL <= token.kind) && (token.kind <= TOKEN_LAST_MUL);
}

static Expr* parse_expr_mul(void) {
	Expr* expr = parse_expr_unary();
	while (is_mul_op()) {
		TokenKind op = token.kind;
		next_token();
		expr = new_expr_binary(op, expr, parse_expr_unary());
	}

	return expr;
}

static inline bool is_add_op(void) {
	return (TOKEN_FIRST_ADD <= token.kind) && (token.kind <= TOKEN_LAST_ADD);
}

static Expr* parse_expr_add(void) {
	Expr* expr = parse_expr_mul();
	while (is_add_op()) {
		TokenKind op = token.kind;
		next_token();
		expr = new_expr_binary(op, expr, parse_expr_mul());
	}

	return expr;
}

static inline bool is_cmp_op(void) {
	return (TOKEN_FIRST_CMP <= token.kind) && (token.kind <= TOKEN_LAST_CMP);
}

static Expr* parse_expr_cmp(void) {
	Expr* expr = parse_expr_add();
	while (is_cmp_op()) {
		TokenKind op = token.kind;
		next_token();
		expr = new_expr_binary(op, expr, parse_expr_add());
	}

	return expr;
}

static Expr* parse_expr_and(void) {
	Expr* expr = parse_expr_cmp();
	while (match_token(TOKEN_AND_AND)) {
		expr = new_expr_binary(TOKEN_AND_AND, expr, parse_expr_cmp());
	}

	return expr;
}

static Expr* parse_expr_or(void) {
	Expr* expr = parse_expr_and();
	while (match_token(TOKEN_OR_OR)) {
		expr = new_expr_binary(TOKEN_OR_OR, expr, parse_expr_and());
	}

	return expr;
}

static Expr* parse_expr_ternary(void) {
	Expr* expr = parse_expr_or();
	if (match_token(TOKEN_QUESTION)) {
		Expr* then_expr = parse_expr_ternary();
		expect_token(TOKEN_COLON);
		Expr* else_expr = parse_expr_ternary();
		expr = new_expr_ternary(expr, then_expr, else_expr);
	}

	return expr;
}

static Expr* parse_expr(void) {
	return parse_expr_ternary();
}

static Expr* parse_paren_expr(void) {
	expect_token(TOKEN_LPAREN);
	Expr* expr = parse_expr();
	expect_token(TOKEN_RPAREN);
	return expr;
}

static char* parse_name(void) {
	char* name = token.name;
	expect_token(TOKEN_NAME);
	return name;
}

static Decl* parse_decl_var(void) {
	char* name = parse_name();
	Typespec* typespec = NULL;
	Expr* expr = NULL;
	if (match_token(TOKEN_COLON)) {
		typespec = parse_typespec();
	}

	if (match_token(TOKEN_ASSIGN)) {
		expr = parse_expr();
	}

	expect_token(TOKEN_SEMICOLON);
	return new_decl_var(name, typespec, expr);
}

static AggregateItem parse_aggregate_item(void) {
	AggregateItem item = { AGGREGATE_ITEM_NONE };
	if (match_keyword(struct_keyword)) {
		item.kind = AGGREGATE_ITEM_SUBAGGREGATE;
		item.subaggregate = parse_aggregate(AGGREGATE_STRUCT);
	} else if (match_keyword(union_keyword)) {
		item.kind = AGGREGATE_ITEM_SUBAGGREGATE;
		item.subaggregate = parse_aggregate(AGGREGATE_UNION);
	} else {
		item.kind = AGGREGATE_ITEM_FIELD;
		item.field.name = parse_name();
		expect_token(TOKEN_COLON);
		item.field.typespec = parse_typespec();
		expect_token(TOKEN_SEMICOLON);
	}

	assert(item.kind);
	return item;
}

static Aggregate* parse_aggregate(AggregateKind kind) {
	expect_token(TOKEN_LBRACE);
	AggregateItem* items = NULL;
	while (!is_token_eof() && !is_token(TOKEN_RBRACE)) {
		AggregateItem item = parse_aggregate_item();
		buf_push((void**)&items, &item, sizeof(AggregateItem));
	}

	expect_token(TOKEN_RBRACE);
	return new_aggregate(kind, items, buf_len(items));
}

static Decl* parse_decl_aggregate(AggregateKind kind) {
	assert(kind == AGGREGATE_STRUCT || kind == AGGREGATE_UNION);
	char* name = parse_name();
	return new_decl_aggregate(name, parse_aggregate(kind));
}

static FuncParam parse_func_param(void) {
	char* name = parse_name();
	expect_token(TOKEN_COLON);
	Typespec* typespec = parse_typespec();
	return (FuncParam) { name, typespec };
}

static Decl* parse_decl_func(void) {
	char* name = parse_name();
	expect_token(TOKEN_LPAREN);
	FuncParam* params = NULL;
	if (!is_token(TOKEN_RPAREN)) {
		do {
			FuncParam param = parse_func_param();
			buf_push((void**)&params, &param, sizeof(FuncParam));
		} while (!is_token_eof() && match_token(TOKEN_COMMA));
	}

	expect_token(TOKEN_RPAREN);
	Typespec* ret_typespec = NULL;
	if (match_token(TOKEN_COLON)) {
		ret_typespec = parse_typespec();
	}

	return new_decl_func(name, params, buf_len(params), ret_typespec, parse_stmt_block());
}

static Decl* parse_decl(void) {
	if (match_keyword(var_keyword)) {
		return parse_decl_var();
	} else if (match_keyword(struct_keyword)) {
		return parse_decl_aggregate(AGGREGATE_STRUCT);
	} else if (match_keyword(union_keyword)) {
		return parse_decl_aggregate(AGGREGATE_UNION);
	} else if (match_keyword(func_keyword)) {
		return parse_decl_func();
	} else {
		fatal_error("expected declaration heyword, got %s", token_kind_name(token.kind));
	}
}

static Decls* parse_decls(void) {
	Decl** decls = NULL;
	while (!is_token_eof()) {
		Decl* decl = parse_decl();
		buf_push((void**)&decls, &decl, sizeof(Decl*));
	}

	return new_decls(decls, buf_len(decls));
}

static inline bool is_assign_op(void) {
	return (TOKEN_FIRST_ASSIGN <= token.kind) && (token.kind <= TOKEN_LAST_ASSIGN);
}

static Stmt* parse_simple_stmt(void) {
	if (match_keyword(var_keyword)) {
		char* name = parse_name();
		Typespec* typespec = NULL;
		if (match_token(TOKEN_COLON)) {
			typespec = parse_typespec();
		}

		Expr* expr = NULL;
		if (match_token(TOKEN_ASSIGN)) {
			expr = parse_expr();
		}

		return new_stmt_init(name, typespec, expr);
	} else {
		// TODO(wkns37): refactor code duplication
		if (is_token(TOKEN_INC) || is_token(TOKEN_DEC)) {
			TokenKind op = token.kind;
			next_token();
			return new_stmt_modify(op, false, parse_expr());
		}

		Expr* expr = parse_expr();
		if (is_token(TOKEN_INC) || is_token(TOKEN_DEC)) {
			TokenKind op = token.kind;
			next_token();
			return new_stmt_modify(op, true, expr);
		} else if (is_assign_op()) {
			TokenKind op = token.kind;
			next_token();
			return new_stmt_assign(op, expr, parse_expr());
		} else {
			return new_stmt_expr(expr);
		}
	}
}

static StmtList* parse_stmt_block(void) {
	expect_token(TOKEN_LBRACE);
	Stmt** stmts = NULL;
	while (!is_token_eof() && !is_token(TOKEN_RBRACE)) {
		Stmt* stmt = parse_stmt();
		buf_push((void**)&stmts, &stmt, sizeof(Stmt*));
	}

	expect_token(TOKEN_RBRACE);
	return new_stmt_list(stmts, buf_len(stmts));
}

static Stmt* parse_stmt_if(void) {
	Expr* cond = parse_paren_expr();
	StmtList* then_block = parse_stmt_block();
	ElseIf* elseifs = NULL;
	StmtList* else_block = NULL;
	while (!is_token_eof() && match_keyword(else_keyword)) {
		if (!match_keyword(if_keyword)) {
			else_block = parse_stmt_block();
			break;
		}

		Expr* elseif_cond = parse_paren_expr();
		StmtList* elseif_block = parse_stmt_block();
		ElseIf elseif = { elseif_cond, elseif_block };
		buf_push((void**)&elseifs, &elseif, sizeof(ElseIf));
	}

	return new_stmt_if(cond, then_block, elseifs, buf_len(elseifs), else_block);
}

static Stmt* parse_stmt_while(void) {
	Expr* cond = parse_paren_expr();
	return new_stmt_while(cond, parse_stmt_block());
}

static Stmt* parse_stmt_do_while(void) {
	StmtList* block = parse_stmt_block();
	if (!match_keyword(while_keyword)) {
		fatal_error("expected 'while' after 'do' block");
	}

	Stmt* stmt = new_stmt_do_while(block, parse_paren_expr());
	expect_token(TOKEN_SEMICOLON);
	return stmt;
}

static Stmt* parse_stmt_for(void) {
	expect_token(TOKEN_LPAREN);
	Stmt* init = NULL;
	if (!is_token(TOKEN_SEMICOLON)) {
		init = parse_simple_stmt();
	}

	expect_token(TOKEN_SEMICOLON);
	Expr* cond = NULL;
	if (!is_token(TOKEN_SEMICOLON)) {
		cond = parse_expr();
	}

	expect_token(TOKEN_SEMICOLON);
	Expr* next = NULL;
	if (!is_token(TOKEN_RPAREN)) {
		next = parse_expr();
	}

	expect_token(TOKEN_RPAREN);
	return new_stmt_for(init, cond, next, parse_stmt_block());
}

static SwitchCase parse_switch_case(void) {
	Expr* pattern = NULL;
	bool is_default = false;
	if (match_keyword(case_keyword)) {
		pattern = parse_expr();
	} else if (match_keyword(default_keyword)) {
		is_default = true;
	} else {
		fatal_error("unexpected token %s in case", token_kind_name(token.kind));
	}

	expect_token(TOKEN_COLON);
	Stmt** stmts = NULL;
	while (!is_token_eof() && !is_token(TOKEN_RBRACE) && !is_keyword(case_keyword) && !is_keyword(default_keyword)) {
		Stmt* stmt = parse_stmt();
		buf_push((void**)&stmts, &stmt, sizeof(Stmt*));
	}

	return (SwitchCase) { pattern, new_stmt_list(stmts, buf_len(stmts)), is_default };
}

static Stmt* parse_stmt_switch(void) {
	Expr* expr = parse_paren_expr();
	SwitchCase* cases = NULL;
	expect_token(TOKEN_LBRACE);
	while (!is_token_eof() && !is_token(TOKEN_RBRACE)) {
		SwitchCase branch = parse_switch_case();
		buf_push((void**)&cases, &branch, sizeof(SwitchCase));
	}

	expect_token(TOKEN_RBRACE);
	return new_stmt_switch(expr, cases, buf_len(cases));
}

static Stmt* parse_stmt(void) {
	Stmt* stmt = NULL;
	if (is_token(TOKEN_LBRACE)) {
		stmt = new_stmt_block(parse_stmt_block());
	} else if (match_keyword(if_keyword)) {
		stmt = parse_stmt_if();
	} else if (match_keyword(while_keyword)) {
		stmt = parse_stmt_while();
	} else if (match_keyword(do_keyword)) {
		stmt = parse_stmt_do_while();
	} else if (match_keyword(for_keyword)) {
		stmt = parse_stmt_for();
	} else if (match_keyword(switch_keyword)) {
		stmt = parse_stmt_switch();
	} else {
		stmt = parse_simple_stmt();
		expect_token(TOKEN_SEMICOLON);
	}

	return stmt;
}

static void parser_test(void) {
	char* code = "var x: int = 123;"
		"var y = \"str\";"
		"var z: float;"
		"struct X {}"
		"struct Y { f1: int; f2: string; struct { f3: float; union { f4: int; f5: string; } f6: float; } f7: int; }"
		"func f1() {}"
		"func f2(x: int): int { if (0) { 1; } else if (2) { 3; } else { 4; } }"
		"func f3() { while (0) { 1; 2; 3; } do { 4; 5; 6; } while (7); }"
		"func f4() { for (;;) {} for (0; 1; 2) { 3; 4; 5; } }"
		"func f5() { switch(0) { case 1: 2; 3; case 4: { 5; } 6; default: { 7; 8; 9; } } }"
		"func f6(x: int) { !x; ~x; *x; &x; +x; !~*&+-x; }"
		"func f7(x: int) { ++x; --x; x++; x--; }"
		"func f8() { cast(int) 0; var x = 0; 1 + 2 * cast(float) !~*x + 3 / cast(float) (&+-x - 4); }"
		"func f9() { f1(); f2(0); f3(); var x = 1; f6(x); (f7)(x + 2); }";

	init_stream(code);
	Decls* decls = parse_decls();
	for (size_t i = 0; i < decls->num_decls; i++) {
		Decl* decl = decls->decls[i];
		print_decl(decl);
		printf("\n");
	}
}
