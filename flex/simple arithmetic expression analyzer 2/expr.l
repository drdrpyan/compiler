%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+	{ yylval = atoi(yytext); return num; }

"+"		return '+';
"-"		return '-';
"*"		return '*';
"/"		return '/';
"%"		return '%';
"^"		return '^';

"("		return '(';
")"		return ')';

[ \t]	;
\n		return 0;

.		{ puts("Lexical Error"); exit(-1); }

%%

int yywrap() { return 1; }