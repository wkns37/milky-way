typedef struct Type Type;
typedef struct Sym Sym;

typedef enum {
	TYPE_NONE,
	TYPE_INT
} TypeKind;

struct Type {
	TypeKind kind;
};

Type* type_int = &(Type) { TYPE_INT };

typedef enum {
	SYM_NONE,
	SYM_VAR,
	SYM_TYPE,
	SYM_FUNC
} SymKind;

typedef enum {
	SYM_UNRESOLVED,
	SYM_RESOLVING,
	SYM_RESOLVED
} SymState;

struct Sym {
	SymKind kind;
	SymState state;
	char* name;
	Type* type;
	Decl* decl;
};

typedef struct {
	Type* type;
	bool is_lvalue;
} Operand;
