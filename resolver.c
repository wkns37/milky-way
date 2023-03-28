static Arena symbols_arena;
static Sym** symbols;

static Sym* resolve_name(char* name);
static Operand resolve_expr(Expr* expr);

static Type* resolve_typespec(Typespec* typespec) {
	switch (typespec->kind) {
		case TYPESPEC_NAME: {
			Sym* sym = resolve_name(typespec->name);
			if (sym->kind != SYM_TYPE) {
				fatal_error("%s must denote a type", sym->name);
			}

			return sym->type;
		} break;

		default: assert(0); break;
	}

	return NULL;
}

static Sym* new_sym(SymKind kind, char* name, Decl* decl) {
	Sym* sym = arena_alloc(&symbols_arena, sizeof(Sym));
	sym->kind = kind;
	sym->state = SYM_UNRESOLVED;
	sym->name = name;
	sym->type = NULL;
	sym->decl = decl;
	return sym;
}

static Sym* get_sym(char* name) {
	for (size_t i = 0; i < buf_len(symbols); i++) {
		Sym* sym = symbols[i];
		if (sym->name == name) {
			return sym;
		}
	}

	return NULL;
}

static Sym* new_sym_decl(Decl* decl) {
	SymKind kind = SYM_NONE;
	switch (decl->kind) {
		case DECL_VAR: { kind = SYM_VAR; } break;
		case DECL_AGGREGATE: { kind = SYM_TYPE; } break;
		case DECL_FUNC: { kind = SYM_FUNC; } break;

		default: assert(0); break;
	}

	return new_sym(kind, decl->name, decl);
}

static Sym* new_sym_type(char* name, Type* type) {
	Sym* sym = new_sym(SYM_TYPE, name, NULL);
	sym->state = SYM_RESOLVED;
	sym->type = type;
	return sym;
}

static void install_decl(Decl* decl) {
	Sym* sym = new_sym_decl(decl);
	buf_push((void**)&symbols, &sym, sizeof(Sym*));
}

static void install_type(char* name, Type* type) {
	Sym* sym = new_sym_type(name, type);
	buf_push((void**)&symbols, &sym, sizeof(Sym*));
}

static Type* resolve_decl_var(Decl* decl) {
	assert(decl->kind == DECL_VAR);
	Type* type = NULL;
	if (decl->var.typespec) {
		type = resolve_typespec(decl->var.typespec);
	}

	if (decl->var.expr) {
		Operand operand = resolve_expr(decl->var.expr);
		if (type && (operand.type != type)) {
			fatal_error("initializer type mismatch");
		}

		type = operand.type;
	}

	return type;
}

static Type* resolve_decl_type(Decl* decl) {
	assert(decl->kind == DECL_AGGREGATE);
	return NULL;
}

static void resolve_sym(Sym* sym) {
	if (sym->state == SYM_RESOLVED) {
		return;
	} else if (sym->state == SYM_RESOLVING) {
		fatal_error("cyclic dependency");
	}

	sym->state = SYM_RESOLVING;
	switch (sym->kind) {
		case SYM_VAR: { sym->type = resolve_decl_var(sym->decl); } break;
		case SYM_TYPE: { sym->type = resolve_decl_type(sym->decl); } break;

		default: assert(0); break;
	}

	sym->state = SYM_RESOLVED;
}

static Sym* resolve_name(char* name) {
	Sym* sym = get_sym(name);
	if (!sym) {
		fatal_error("unknown symbol %s", name);
	}

	resolve_sym(sym);
	return sym;
}

static Operand resolve_expr(Expr* expr) {
	Operand operand = { NULL, false };
	switch (expr->kind) {

		default: assert(0); break;
	}

	return operand;
}

static void resolver_test(void) {
	install_type(str_intern("int"), type_int);

	char* code = "var x: int = 123;"
		"struct S {}"
		"func f() {}";

	init_stream(code);
	Decls* decls = parse_decls();
	for (size_t i = 0; i < decls->num_decls; i++) {
		Decl* decl = decls->decls[i];
		install_decl(decl);
		print_decl(decl);
		printf("\n");
	}

	for (size_t i = 0; i < buf_len(symbols); i++) {
		Sym* sym = symbols[i];
		resolve_sym(sym);
	}
}
