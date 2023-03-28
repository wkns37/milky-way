typedef struct Expr Expr;
typedef struct Decl Decl;
typedef struct Stmt Stmt;

typedef enum {
	TYPESPEC_NONE,
	TYPESPEC_NAME
} TypespecKind;

typedef struct {
	TypespecKind kind;
	union {
		char* name;
	};
} Typespec;

typedef enum {
	EXPR_NONE,
	EXPR_INT,
	EXPR_FLOAT,
	EXPR_STR,
	EXPR_NAME,
	EXPR_UNARY,
	EXPR_BINARY,
	EXPR_TERNARY,
	EXPR_CAST,
	EXPR_CALL
} ExprKind;

struct Expr {
	ExprKind kind;
	union {
		uint64_t int_val;
		double float_val;
		char* str_val;
		char* name;
		struct {
			TokenKind op;
			Expr* expr;
		} unary;
		struct {
			TokenKind op;
			Expr* left;
			Expr* right;
		} binary;
		struct {
			Expr* cond;
			Expr* then_expr;
			Expr* else_expr;
		} ternary;
		struct {
			Typespec* typespec;
			Expr* expr;
		} cast;
		struct {
			Expr* expr;
			Expr** args;
			size_t num_args;
		} call;
	};
};

typedef enum {
	DECL_NONE,
	DECL_VAR,
	DECL_AGGREGATE,
	DECL_FUNC
} DeclKind;

typedef enum {
	AGGREGATE_ITEM_NONE,
	AGGREGATE_ITEM_FIELD,
	AGGREGATE_ITEM_SUBAGGREGATE
} AggregateItemKind;

typedef struct {
	AggregateItemKind kind;
	union {
		struct {
			char* name;
			Typespec* typespec;
		} field;
		struct Aggregate* subaggregate;
	};
} AggregateItem;

typedef enum {
	AGGREGATE_NONE,
	AGGREGATE_STRUCT,
	AGGREGATE_UNION
} AggregateKind;

typedef struct Aggregate {
	AggregateKind kind;
	AggregateItem* items;
	size_t num_items;
} Aggregate;

typedef struct {
	char* name;
	Typespec* typespec;
} FuncParam;

struct Decl {
	DeclKind kind;
	char* name;
	union {
		struct {
			Typespec* typespec;
			Expr* expr;
		} var;
		Aggregate* aggregate;
		struct {
			FuncParam* params;
			size_t num_params;
			Typespec* ret_typespec;
			struct StmtList* block;
		} func;
	};
};

typedef struct {
	Decl** decls;
	size_t num_decls;
} Decls;

typedef enum {
	STMT_NONE,
	STMT_EXPR,
	STMT_MODIFY,
	STMT_BLOCK,
	STMT_INIT, // NOTE(wkns37): use STMT_DECL instead?
	STMT_ASSIGN,
	STMT_IF,
	STMT_WHILE,
	STMT_DO_WHILE,
	STMT_FOR,
	STMT_SWITCH
} StmtKind;

typedef struct StmtList {
	Stmt** stmts;
	size_t num_stmts;
} StmtList;

typedef struct {
	Expr* cond;
	StmtList* block;
} ElseIf;

typedef struct {
	Expr* pattern;
	StmtList* block;
	bool is_default;
} SwitchCase;

struct Stmt {
	StmtKind kind;
	union {
		Expr* expr;
		struct {
			TokenKind op;
			bool post;
			Expr* expr;
		} modify;
		StmtList* block;
		struct {
			char* name;
			Typespec* typespec;
			Expr* expr;
		} init;
		struct {
			TokenKind op;
			Expr* left;
			Expr* right;
		} assign;
		struct {
			Expr* cond;
			StmtList* then_block;
			ElseIf* elseifs;
			size_t num_elseifs;
			StmtList* else_block;
		} if_stmt;
		struct {
			Expr* cond;
			StmtList* block;
		} while_stmt;
		struct {
			Stmt* init;
			Expr* cond;
			Expr* next;
			StmtList* block;
		} for_stmt;
		struct {
			Expr* expr;
			SwitchCase* cases;
			size_t num_cases;
		} switch_stmt;
	};
};
