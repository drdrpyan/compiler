#include "ast.h"
#include <stdlib.h>

node* mknode(char kind, int val, node *son, node *broOfSon)
{
	node *n = (node*)malloc(sizeof(node));
	
	n->kind = kind;
	n->val = val;

	n->son = son;
	n->bro = 0;
	n->son->bro = broOfSon;
	
	return n;
}

node* mkleaf(char kind, int val)
{
	node *n = (node*)malloc(sizeof(node));
	
	n->kind = kind;
	n->val = val;
	n->son = 0;
	n->bro = 0;
	
	return n;
}

void prtree(FILE *out, node *root, int indent)
{
	int i;
	node *broCursor;
	
	if(!root)
		return;
		
	for(i=0; i<indent; i++)
		printf("\t");
		
	switch(root->kind)
	{
	case INT:
		printf("INT(%d)\n", root->val);
		break;
	case ADD_OP:
		printf("ADD_OP\n");
		break;
	case SUB_OP:
		printf("SUB_OP\n");
		break;
	case MUL_OP:
		printf("MUL_OP\n");
		break;
	case DIV_OP:
		printf("DIV_OP\n");
		break;
	case REM_OP:
		printf("REM_OP\n");
		break;
	}
	
	prtree(out, root->son, indent+1);	
	
	broCursor = root->bro;
	while(broCursor)
	{
		prtree(out, broCursor, indent);
		broCursor = broCursor->bro;
	}	
}