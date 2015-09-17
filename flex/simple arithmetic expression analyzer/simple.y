%{
#include <stdio.h>
%}
%token NUMBER ID
%%
Exp     :   Exp '+' Term    	{printf("Exp -> Exp + Term\n");}
        |   Exp '-' Term    	{printf("Exp -> Exp - Term\n");}
        |   Term            	{printf("Exp -> Term\n");}
        ;

Term    :   Term '*' Factor 	{printf("Term -> Term * Factor\n");}
        |   Term '/' Factor 	{printf("Term -> Term / Factor\n");}
        |   Factor          	{printf("Term -> Factor\n");}
        ;

Factor  :   '(' Exp ')'       	{printf("Factor -> (Exp)\n");}
        |   NUMBER				{printf("Factor -> NUMBER\n");}
        |   ID					{printf("Factor -> ID\n");}
        ;
%%
int printrules() {
    printf("--------------------------------\n");
    printf("Rule 1: Exp -> Exp + NUMBER\n");
    printf("Rule 2: Exp -> Exp - NUMBER\n");
    printf("Rule 3: Exp -> Term\n");
	printf("Role 4: Term -> Term * Factor\n");
	printf("Role 5: Term -> Term / Factor\n");
	printf("Role 6: Term -> Factor\n");
	printf("Role 7: Factor -> (Exp)\n");
	printf("Role 8: Factor -> NUMBER\n");
	printf("Role 9: Factor -> ID\n");
    printf("--------------------------------\n");
}

int main() { printrules(); yyparse(); return 0;}
int yyerror(const char* msg) {fputs(msg, stderr); }

