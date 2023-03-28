static Arena ast_arena;

#define AST_DUP(x) ast_dup(x, num_##x * sizeof(*x))

static void* ast_dup(void* src, size_t size) {
	if (size == 0) {
		return NULL;
	}

	// NOTE(wkns37): hardcode ast_arena here?
	void* ptr = arena_alloc(&ast_arena, size);
	memcpy(ptr, src, size);
	return ptr;
}

static Typespec* new_typespec(TypespecKind kind) {
	Typespec* typespec = arena_alloc(&ast_arena, sizeof(Typespec));
	typespec->kind = kind;
	return typespec;
}

static Typespec* new_typespec_name(char* name) {
	Typespec* typespec = new_typespec(TYPESPEC_NAME);
	typespec->name = name;
	return typespec;
}

static Expr* new_expr(ExprKind kind) {
	Expr* expr = arena_alloc(&ast_arena, sizeof(Expr));
	expr->kind = kind;
	return expr;
}

static Expr* new_expr_int(uint64_t val) {
	Expr* expr = new_expr(EXPR_INT);
	expr->int_val = val;
	return expr;
}

static Expr* new_expr_float(double val) {
	Expr* expr = new_expr(EXPR_FLOAT);
	expr->float_val = val;
	return expr;
}

static Expr* new_expr_str(char* val) {
	Expr* expr = new_expr(EXPR_STR);
	expr->str_val = val;
	return expr;
}

static Expr* new_expr_name(char* name) {
	Expr* expr = new_expr(EXPR_NAME);
	expr->name = name;
	return expr;
}

static Expr* new_expr_unary(TokenKind op, Expr* e) {
	Expr* expr = new_expr(EXPR_UNARY);
	expr->unary.op = op;
	expr->unary.expr = e;
	return expr;
}

static Expr* new_expr_binary(TokenKind op, Expr* left, Expr* right) {
	Expr* expr = new_expr(EXPR_BINARY);
	expr->binary.op = op;
	expr->binary.left = left;
	expr->binary.right = right;
	return expr;
}

static Expr* new_expr_ternary(Expr* cond, Expr* then_expr, Expr* else_expr) {
	Expr* expr = new_expr(EXPR_TERNARY);
	expr->ternary.cond = cond;
	expr->ternary.then_expr = then_expr;
	expr->ternary.else_expr = else_expr;
	return expr;
}

static Expr* new_expr_cast(Typespec* typespec, Expr* e) {
	Expr* expr = new_expr(EXPR_CAST);
	expr->cast.typespec = typespec;
	expr->cast.expr = e;
	return expr;
}

static Expr* new_expr_call(Expr* e, Expr** args, size_t num_args) {
	Expr* expr = new_expr(EXPR_CALL);
	expr->call.expr = e;
	expr->call.args = AST_DUP(args);
	expr->call.num_args = num_args;
	return expr;
}

static Decl* new_decl(DeclKind kind, char* name) {
	Decl* decl = arena_alloc(&ast_arena, sizeof(Decl));
	decl->kind = kind;
	decl->name = name;
	return decl;
}

static Decl* new_decl_var(char* name, Typespec* typespec, Expr* expr) {
	Decl* decl = new_decl(DECL_VAR, name);
	decl->var.typespec = typespec;
	decl->var.expr = expr;
	return decl;
}

static Aggregate* new_aggregate(AggregateKind kind, AggregateItem* items, size_t num_items) {
	Aggregate* aggregate = arena_alloc(&ast_arena, sizeof(Aggregate));
	aggregate->kind = kind;
	aggregate->items = AST_DUP(items);
	aggregate->num_items = num_items;
	return aggregate;
}

static Decl* new_decl_aggregate(char* name, Aggregate* aggregate) {
	Decl* decl = new_decl(DECL_AGGREGATE, name);
	decl->aggregate = aggregate;
	return decl;
}

static Decl* new_decl_func(char* name, FuncParam* params, size_t num_params, Typespec* ret_typespec, StmtList* block) {
	Decl* decl = new_decl(DECL_FUNC, name);
	decl->func.params = AST_DUP(params);
	decl->func.num_params = num_params;
	decl->func.ret_typespec = ret_typespec;
	decl->func.block = block;
	return decl;
}

static Decls* new_decls(Decl** decls, size_t num_decls) {
	Decls* d = arena_alloc(&ast_arena, sizeof(Decls));
	d->decls = AST_DUP(decls);
	d->num_decls = num_decls;
	return d;
}

static Stmt* new_stmt(StmtKind kind) {
	Stmt* stmt = arena_alloc(&ast_arena, sizeof(Stmt));
	stmt->kind = kind;
	return stmt;
}

static Stmt* new_stmt_expr(Expr* expr) {
	Stmt* stmt = new_stmt(STMT_EXPR);
	stmt->expr = expr;
	return stmt;
}

static Stmt* new_stmt_modify(TokenKind op, bool post, Expr* expr) {
	Stmt* stmt = new_stmt(STMT_MODIFY);
	stmt->modify.op = op;
	stmt->modify.post = post;
	stmt->modify.expr = expr;
	return stmt;
}

static StmtList* new_stmt_list(Stmt** stmts, size_t num_stmts) {
	StmtList* stmt = arena_alloc(&ast_arena, sizeof(StmtList));
	stmt->stmts = AST_DUP(stmts);
	stmt->num_stmts = num_stmts;
	return stmt;
}

static Stmt* new_stmt_block(StmtList* block) {
	Stmt* stmt = new_stmt(STMT_BLOCK);
	stmt->block = block;
	return stmt;
}

static Stmt* new_stmt_init(char* name, Typespec* typespec, Expr* expr) {
	Stmt* stmt = new_stmt(STMT_INIT);
	stmt->init.name = name;
	stmt->init.typespec = typespec;
	stmt->init.expr = expr;
	return stmt;
}

static Stmt* new_stmt_assign(TokenKind op, Expr* left, Expr* right) {
	Stmt* stmt = new_stmt(STMT_ASSIGN);
	stmt->assign.op = op;
	stmt->assign.left = left;
	stmt->assign.right = right;
	return stmt;
}

static Stmt* new_stmt_if(Expr* cond, StmtList* then_block, ElseIf* elseifs, size_t num_elseifs, StmtList* else_block) {
	Stmt* stmt = new_stmt(STMT_IF);
	stmt->if_stmt.cond = cond;
	stmt->if_stmt.then_block = then_block;
	stmt->if_stmt.elseifs = AST_DUP(elseifs);
	stmt->if_stmt.num_elseifs = num_elseifs;
	stmt->if_stmt.else_block = else_block;
	return stmt;
}

static Stmt* new_stmt_while(Expr* cond, StmtList* block) {
	Stmt* stmt = new_stmt(STMT_WHILE);
	stmt->while_stmt.cond = cond;
	stmt->while_stmt.block = block;
	return stmt;
}

static Stmt* new_stmt_do_while(StmtList* block, Expr* cond) {
	Stmt* stmt = new_stmt(STMT_DO_WHILE);
	stmt->while_stmt.block = block;
	stmt->while_stmt.cond = cond;
	return stmt;
}

static Stmt* new_stmt_for(Stmt* init, Expr* cond, Expr* next, StmtList* block) {
	Stmt* stmt = new_stmt(STMT_FOR);
	stmt->for_stmt.init = init;
	stmt->for_stmt.cond = cond;
	stmt->for_stmt.next = next;
	stmt->for_stmt.block = block;
	return stmt;
}

static Stmt* new_stmt_switch(Expr* expr, SwitchCase* cases, size_t num_cases) {
	Stmt* stmt = new_stmt(STMT_SWITCH);
	stmt->switch_stmt.expr = expr;
	stmt->switch_stmt.cases = AST_DUP(cases);
	stmt->switch_stmt.num_cases = num_cases;
	return stmt;
}
