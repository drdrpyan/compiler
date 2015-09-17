#ifndef ___BGM__AST_NODE__H___
#define ___BGM__AST_NODE__H___

#include <stdio.h>


union value{
    int iVal;
    char cVal;
    char* sVal;
};
typedef enum _nodeKind { OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
				OP_EQUAL, OP_NEQUAL, OP_GREAT, OP_LESS, OP_GREAT_EQUAL, OP_LESS_EQUAL,
				OP_L_AND, OP_L_OR,
				OP_B_AND, OP_B_OR, OP_B_XOR, OP_SHL, OP_SHR,
				OP_ADD_ACC, OP_SUB_ACC, OP_MUL_ACC, OP_DIV_ACC, OP_MOD_ACC,
				OP_BAND_ACC, OP_BOR_ACC, OP_BXOR_ACC, OP_SHL_ACC, OP_SHR_ACC,
				OP_ASSIGN,
				INT, CHAR, STRING, VOID, VAR, VAR_LIST,
				NIL, RETURN, INPUT, OUTPUT, DO, WHILE, FOR, IF, STMT,
				TYPE, TYPE_LIST, VAR_DEC, VAR_DEC_LIST,
				PARAM, ID, FUNCTION, FUNC_DEC, FUNC_LIST, 
				PROGRAM} nodeKind;
				
typedef struct _node{
    nodeKind kind;
    union value val;
    struct _node *bro, *son;
} Node;

Node* mkleaf(nodeKind kind, int val);
Node* mknode(nodeKind kind, int val, int numOfSons, ...);
//Node* mknode(enum nodeKind kind, int val, Node *son, Node *broOfSon);
void addBro(Node *target, Node *newBro);
void addSon(Node *target, Node *newSon);
void setKind(Node *target, nodeKind kind);
void prtree(FILE *out, Node *root, int indent);

#endif