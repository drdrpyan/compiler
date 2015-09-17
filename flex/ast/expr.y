%{
#include <stdio.h>
#include "ast.h"
%}
%union {
	struct _node *ptrVal;
	int intVal;
	char *strVal;
}

%token <intVal> NUM

%type <ptrVal> Exp
%type <ptrVal> Term
%type <ptrVal> Factor

%%
Prog	: Exp				{ prtree(stdout, $1, 0); }
		;

Exp		: Exp '+' Term		{ $$ = mknode(ADD_OP, 0, $1, $3); }
		| Exp '-' Term		{ $$ = mknode(SUB_OP, 0, $1, $3); }
		| Term				{ $$ = $1; }
		;

Term	: Term '*' Factor	{ $$ = mknode(MUL_OP, 0, $1, $3); }
		| Term '/' Factor	{ $$ = mknode(DIV_OP, 0, $1, $3); }
		| Term '%' Factor	{ $$ = mknode(REM_OP, 0, $1, $3); }
		| Factor			{ $$ = $1; }
		;

Factor	: '(' Exp ')'		{ $$ = $2; }
		| NUM				{ $$ = mkleaf(INT, $1); }
		;

%%

int main(){ yyparse(); return 0; }
int yyerror(const char *m){ fputs(m, stderr); }
