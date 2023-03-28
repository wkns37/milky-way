static void print_aggregate(char* name, Aggregate* aggregate);
static void print_stmt_block(StmtList* block);
static void print_stmt(Stmt* stmt);

static uint32_t identation;

static void println(void) {
	printf("\n%.*s", identation * 2, "                          ");
}

static void print_typespec(Typespec* typespec) {
	assert(typespec);
	switch (typespec->kind) {
		case TYPESPEC_NAME: {
			printf("%s", typespec->name);
		} break;

		default: assert(0); break;
	}
}

static void print_expr(Expr* expr) {
	assert(expr);
	switch (expr->kind) {
		case EXPR_INT: {
			printf("%" PRIu64, expr->int_val);
		} break;

		case EXPR_FLOAT: {
			printf("%f", expr->float_val);
		} break;

		case EXPR_STR: {
			printf("\"%s\"", expr->str_val);
		} break;

		case EXPR_NAME: {
			printf("%s", expr->name);
		} break;

		case EXPR_UNARY: {
			printf("(%s ", token_kind_name(expr->unary.op));
			print_expr(expr->unary.expr);
			printf(")");
		} break;

		case EXPR_BINARY: {
			printf("(%s ", token_kind_name(expr->binary.op));
			print_expr(expr->binary.left);
			printf(" ");
			print_expr(expr->binary.right);
			printf(")");
		} break;

		case EXPR_TERNARY: {
			printf("(? ");
			print_expr(expr->ternary.cond);
			printf(" ");
			print_expr(expr->ternary.then_expr);
			printf(" ");
			print_expr(expr->ternary.else_expr);
			printf(")");
		} break;

		case EXPR_CAST: {
			printf("(cast ");
			print_typespec(expr->cast.typespec);
			printf(" ");
			print_expr(expr->cast.expr);
			printf(")");
		} break;

		case EXPR_CALL: {
			printf("(");
			print_expr(expr->call.expr);
			for (size_t i = 0; i < expr->call.num_args; i++) {
				Expr* arg = expr->call.args[i];
				printf(" ");
				print_expr(arg);
			}

			printf(")");
		} break;

		default: assert(0); break;
	}
}

static void print_aggregate_item(AggregateItem item) {
	switch (item.kind) {
		case AGGREGATE_ITEM_FIELD: {
			printf("(");
			print_typespec(item.field.typespec);
			printf(" %s", item.field.name);
			printf(")");
		} break;

		case AGGREGATE_ITEM_SUBAGGREGATE: {
			print_aggregate(NULL, item.subaggregate);
		} break;

		default: assert(0); break;
	}
}

static void print_aggregate(char* name, Aggregate* aggregate) {
	assert(aggregate);
	switch (aggregate->kind) {
		case AGGREGATE_STRUCT:
		case AGGREGATE_UNION: {
			if (aggregate->kind == AGGREGATE_STRUCT) {
				printf("(struct");
			} else if (aggregate->kind == AGGREGATE_UNION) {
				printf("(union");
			}

			if (name) {
				printf(" %s", name);
			}

			identation++;
			for (size_t i = 0; i < aggregate->num_items; i++) {
				println();
				print_aggregate_item(aggregate->items[i]);
			}

			identation--;
			printf(")");
		} break;

		default: assert(0); break;
	}
}

static void print_decl(Decl* decl) {
	assert(decl);
	switch (decl->kind) {
		case DECL_VAR: {
			printf("(var %s", decl->name);
			if (decl->var.typespec) {
				printf(" ");
				print_typespec(decl->var.typespec);
			} else {
				printf(" <no-typespec>");
			}

			if (decl->var.expr) {
				printf(" ");
				print_expr(decl->var.expr);
			} else {
				printf(" <no-expr>");
			}

			printf(")");
		} break;

		case DECL_AGGREGATE: {
			print_aggregate(decl->name, decl->aggregate);
		} break;

		case DECL_FUNC: {
			printf("(func %s (", decl->name);
			for (size_t i = 0; i < decl->func.num_params; i++) {
				if (i != 0) {
					printf(", ");
				}
				FuncParam* param = decl->func.params + i;
				printf("%s ", param->name);
				print_typespec(param->typespec);
			}

			printf(") ");
			if (decl->func.ret_typespec) {
				print_typespec(decl->func.ret_typespec);
			} else {
				printf("void");
			}

			identation++;
			println();
			print_stmt_block(decl->func.block);
			identation--;
			printf(")");
		} break;

		default: assert(0); break;
	}
}

static void print_stmt_block(StmtList* block) {
	assert(block);
	printf("(block");
	identation++;
	for (size_t i = 0; i < block->num_stmts; i++) {
		Stmt* stmt = block->stmts[i];
		println();
		print_stmt(stmt);
	}

	identation--;
	printf(")");
}

static void print_stmt(Stmt* stmt) {
	assert(stmt);
	switch (stmt->kind) {
		case STMT_EXPR: {
			print_expr(stmt->expr);
		} break;

		case STMT_MODIFY: {
			printf("(");
			if (!stmt->modify.post) {
				printf("%s ", token_kind_name(stmt->modify.op));
			}

			print_expr(stmt->modify.expr);
			if (stmt->modify.post) {
				printf(" %s", token_kind_name(stmt->modify.op));
			}

			printf(")");
		} break;

		case STMT_BLOCK: {
			print_stmt_block(stmt->block);
		} break;

		case STMT_INIT: {
			printf("(var %s", stmt->init.name);
			if (stmt->init.typespec) {
				printf(" ");
				print_typespec(stmt->init.typespec);
			} else {
				printf(" <no-typespec>");
			}

			if (stmt->init.expr) {
				printf(" ");
				print_expr(stmt->init.expr);
			} else {
				printf(" <no-expr>");
			}

			printf(")");
		} break;

		case STMT_ASSIGN: {
			printf("(%s ", token_kind_name(stmt->assign.op));
			print_expr(stmt->assign.left);
			printf(" ");
			print_expr(stmt->assign.right);
			printf(")");
		} break;

		case STMT_IF: {
			printf("(if ");
			print_expr(stmt->if_stmt.cond);
			identation++;
			println();
			print_stmt_block(stmt->if_stmt.then_block);
			for (size_t i = 0; i < stmt->if_stmt.num_elseifs; i++) {
				ElseIf* elseif = stmt->if_stmt.elseifs + i;
				println();
				printf("elseif ");
				print_expr(elseif->cond);
				println();
				print_stmt_block(elseif->block);
			}

			if (stmt->if_stmt.else_block) {
				println();
				printf("else");
				println();
				print_stmt_block(stmt->if_stmt.else_block);
			}

			identation--;
			printf(")");
		} break;

		case STMT_WHILE: {
			printf("(while ");
			print_expr(stmt->while_stmt.cond);
			identation++;
			println();
			print_stmt_block(stmt->while_stmt.block);
			identation--;
			printf(")");
		} break;

		case STMT_DO_WHILE: {
			printf("(do-while ");
			print_expr(stmt->while_stmt.cond);
			identation++;
			println();
			print_stmt_block(stmt->while_stmt.block);
			identation--;
			printf(")");
		} break;

		case STMT_FOR: {
			printf("(for");
			if (stmt->for_stmt.init) {
				printf(" ");
				print_stmt(stmt->for_stmt.init);
			} else {
				printf(" <no-init>");
			}

			if (stmt->for_stmt.cond) {
				printf(" ");
				print_expr(stmt->for_stmt.cond);
			} else {
				printf(" <no-expr>");
			}

			if (stmt->for_stmt.next) {
				printf(" ");
				print_expr(stmt->for_stmt.next);
			} else {
				printf(" <no-next>");
			}

			identation++;
			println();
			print_stmt_block(stmt->for_stmt.block);
			identation--;
			printf(")");
		} break;

		case STMT_SWITCH: {
			printf("(switch ");
			print_expr(stmt->switch_stmt.expr);
			identation++;
			for (size_t i = 0; i < stmt->switch_stmt.num_cases; i++) {
				SwitchCase* branch = stmt->switch_stmt.cases + i;
				println();
				printf("(%s", branch->is_default ? "default" : "case");
				if (branch->pattern) {
					printf(" ");
					print_expr(branch->pattern);
				}

				identation++;
				println();
				print_stmt_block(branch->block);
				identation--;
				printf(")");
			}

			identation--;
			printf(")");
		} break;

		default: assert(0); break;
	}
}
