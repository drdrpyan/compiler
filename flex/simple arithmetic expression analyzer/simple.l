%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
[0-9]+      				{return NUMBER;}
[a-zA-Z_]([a-zA-z_0-9]*)  	{return ID;}
[ \t]       				;
\n          				{return(0); /* EOF */}
"+"         				{return '+';}
"-"         				{return '-';}
"*"         				{return '*';}
"/"         				{return '/';}
"("							{return '(';}
")"							{return ')';}
.           				{printf("error near '%s'\n", yytext); exit(-1);}
%%
int yywrap() {return 1;}

