%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+	{yylval.intVal = atoi(yytext); return NUM;}
[ \t]	;
eof		return 0;
\n		return 0;
"("		return '(';
")"		return ')';
"+"		return '+';
"-"		return '-';
"*"		return '*';
"/"		return '/';
"%"		return '%';
.		{ printf("lexical error"); exit(-1); }

%%

int yywrap() { return 1; }