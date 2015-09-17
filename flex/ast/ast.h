#ifndef __MKNODE__
#define __MKNODE__

#include <stdio.h>

#define INT 0
#define STR 1
#define ADD_OP 2
#define SUB_OP 3
#define MUL_OP 4
#define DIV_OP 5
#define REM_OP 6

typedef struct _node {
	char kind;
	//union {int; char*;} val;
	int val;
	struct _node *bro, *son;
} node;

node* mknode(char kind, int val, node *son, node *broOfSon);
node* mkleaf(char kind, int val);
void prtree(FILE *out, node *root, int indent);

#endif