#include "ast.h"
#include <stdlib.h>
#include <stdarg.h>

Node* mknode(nodeKind kind, int val, int numOfSons, ...)
{
	va_list ap;
	int i;
	
	Node *n = (Node*)malloc(sizeof(Node));	
	n->kind = kind;
	n->val.iVal = val;	
	n->son = 0;
	n->bro = 0;
	
	va_start(ap, numOfSons);
	for(i=0; i<numOfSons; i++)
		addSon(n, (Node*)va_arg(ap, int));
	va_end(ap);
	
	return n;
}

//Node* mknode(enum nodeKind kind, int val, Node *son, Node *broOfSon)
//{
//	Node *n = (Node*)malloc(sizeof(Node));
//	
//	n->kind = kind;
//	n->val.iVal = val;
//
//	n->son = son;
//	n->bro = 0;
//	n->son->bro = broOfSon;
//	
//	return n;
//}

Node* mkleaf(nodeKind kind, int val)
{
	Node *n = (Node*)malloc(sizeof(Node));
	
	n->kind = kind;
	n->val.iVal = val;
	n->son = 0;
	n->bro = 0;
	
	return n;
}

void addBro(Node *target, Node *newBro)
{
	Node *cursor = target;
	while(cursor->bro)
		cursor = cursor->bro;
	cursor->bro = newBro;
}

void addSon(Node *target, Node *newSon)
{
	if(!target->son)
		target->son = newSon;
	else
		addBro(target->son, newSon);
}

void setKind(Node *target, nodeKind kind)
{
	target->kind = kind;
}

void prtree(FILE *out, Node *root, int indent)
{
	int i;
	
	if(!root)
		return;
		
	for(i=0; i<indent; i++)
		printf("\t");
		
	switch(root->kind)
	{
	case INT:
		printf("INT(%d)\n", root->val);
		break;
	case CHAR:
		printf("CHAR(%c)\n", root->val);
		break;
	case STRING:
		printf("STRING(%s)\n", root->val);
		break;
	case VOID:
		printf("VOID\n");
		break;
	case VAR:
		printf("VAR(%s)\n", root->val);
		break;
	case VAR_LIST:
		printf("VAR_LIST\n");
		break;
	case OP_ADD:
		printf("OP_ADD\n");
		break;
	case OP_SUB:
		printf("OP_SUB\n");
		break;
	case OP_MUL:
		printf("OP_MUL\n");
		break;
	case OP_DIV:
		printf("OP_DIV\n");
		break;
	case OP_MOD:
		printf("OP_MOD\n");
		break;
	case OP_EQUAL:
		printf("OP_EQUAL\n");
		break;
	case OP_NEQUAL:
		printf("OP_NEQUAL\n");
		break;
	case OP_GREAT:
		printf("OP_GREAT\n");
		break;
	case OP_LESS:
		printf("OP_LESS\n");
		break;
	case OP_GREAT_EQUAL:
		printf("OP_GREAT_EQUAL\n");
		break;
	case OP_LESS_EQUAL:
		printf("OP_LESS_EQUAL\n");
		break;
	case OP_L_AND:
		printf("OP_L_AND\n");
		break;
	case OP_L_OR:
		printf("OP_L_OR\n");
		break;
	case OP_B_AND:
		printf("OP_B_AND\n");
		break;
	case OP_B_OR:
		printf("OP_B_OR\n");
		break;
	case OP_B_XOR:
		printf("OP_B_XOR\n");
		break;
	case OP_SHL:
		printf("OP_SHL\n");
		break;
	case OP_SHR:
		printf("OP_SHR\n");
		break;
	case OP_ADD_ACC:
		printf("OP_ADD_ACC\n");
		break;
	case OP_SUB_ACC:
		printf("OP_SUB_ACC\n");
		break;
	case OP_MUL_ACC:
		printf("OP_MUL_ACC\n");
		break;
	case OP_DIV_ACC:
		printf("OP_DIV_ACC\n");
		break;
	case OP_MOD_ACC:
		printf("OP_MOD_ACC\n");
		break;
	case OP_BAND_ACC:
		printf("OP_BAND_ACC\n");
		break;
	case OP_BOR_ACC:
		printf("OP_BOR_ACC\n");
		break;
	case OP_BXOR_ACC:
		printf("OP_BXOR_ACC\n");
		break;
	case OP_SHL_ACC:
		printf("OP_SHL_ACC\n");
		break;
	case OP_SHR_ACC:
		printf("OP_SHR_ACC\n");
		break;
	case OP_ASSIGN:
		printf("OP_ASSIGN\n");
		break;
	case NIL:
		printf("NIL\n");
		break;
	case RETURN:
		printf("RETURN\n");
		break;
	case INPUT:
		printf("INPUT\n");
		break;
	case OUTPUT:
		printf("OUTPUT\n");
		break;
	case DO:
		printf("DO\n");
		break;
	case WHILE:
		printf("WHILE\n");
		break;
	case FOR:
		printf("FOR\n");
		break;
	case IF:
		printf("IF\n");
		break;
	case STMT:
		printf("STMT\n");
		break;
	case TYPE:
		printf("TYPE(");
		switch(root->val.iVal) {
		case INT:
			printf("int)\n");
			break;
		case CHAR:
			printf("char)\n");
			break;
		case STRING:
			printf("string)\n");
			break;
		}
		break;
	case TYPE_LIST:
		printf("TYPE_LIST\n");
		break;
	case VAR_DEC:
		printf("VAR_DEC\n");
		break;
	case VAR_DEC_LIST:
		printf("VAR_DEC_LIST\n");
		break;
	case PARAM:
		printf("PARAM\n");
		break;
	case ID:
		printf("ID(%s)\n", root->val);
		break;
	case FUNCTION:
		printf("FUNCTION\n");
		break;
	case FUNC_DEC:
		printf("FUNC_DEC\n");
		break;
	case FUNC_LIST:
		printf("FUNC_LIST\n");
		break;
	case PROGRAM:
		printf("PROGRAM\n");
		break;
	}
	
	prtree(out, root->son, indent+1);	
	prtree(out, root->bro, indent);
}