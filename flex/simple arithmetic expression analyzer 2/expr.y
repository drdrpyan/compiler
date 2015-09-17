%{
#include <stdio.h>
#include <math.h>
%}

%token num

%%

Line	: Expr				{ printf(" = %d\n", $1); }
		;
		
Expr	: Expr '+' Term		{ $$ = $1 + $3; }
		| Expr '-' Term		{ $$ = $1 - $3; }
		| Term				{ $$ = $1; }
		;
		
Term	: Term '*' Factor	{ $$ = $1 * $3; }
		| Term '/' Factor	{ $$ = $1 / $3; }
		| Term '%' Factor	{ $$ = $1 % $3; }
		| Factor			{ $$ = $1; }
		;
		
Factor	: Num '^' Factor	{ $$ = pow($1, $3); /*printf("%d -> %d ^ %d\n", $$, $1, $3);*/}
		| Num				{ $$ = $1; /*printf("Power -> Num\n");*/ }
		;

Num		: '(' Expr ')'		{ $$ = $2; /*printf("Num -> ( Expr )\n");*/ }
		| num				{ $$ = $1; /*printf("Num -> %d\n", $1);*/ }
		;

%%

int main() { yyparse(); return 0; }
int yyerror(const char *msg) { fputs(msg, stderr); }