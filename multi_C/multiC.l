%{
//=======================================================================
//���� ������ 2014.10.10
//-----------------------------------------------------------------------
////���� ���
////2014.10.10 ��Ģ����
////2014.10.12 ����, ��, ���� ������ �߰�, ���Ƿ� '\n'�� �ڵ��� ������ ����
////			[[, ]] �߰�
////2014.10.13 if, else, while, for, do �߰�
////2014.11.18 comment("//") �߰�
////2014.11.24 comment ����
////2014.11.24 acc ����ȭ
////2014.11.30 c++ ���� (y.tab.h -> y.tab.hpp)
//=======================================================================
#include "y.tab.hpp"
%}

%%

"if"						return _if;
"else"						return _else;
"while"						return _while;
"for"						return _for;
"do"						return _do;

"return"					return _return;

"int"						return tInt;
"char"						return tChar;
"void"						return tVoid;
\"([a-zA-Z_0-9]*)\"			return tStr;

"0"							{ yylval.iVal = 0; return num; }
[1-9]([0-9]*)			{ yylval.iVal = atoi(yytext); return num; }
0[bB]([01]{1,32})			{ yylval.iVal = atoi(yytext); return num; }
[a-zA-Z_][0-9a-zA-Z_]*			{ yylval.sVal = strdup(yytext); return id; }

\(							return '(';
\)							return ')';

\&							return '&';
\|							return '|';
\^							return '^';
"<<"						return shiftL;
">>"						return shiftR;

\*							return '*';
\/							return '/';
\+							return '+';
\-							return '-';

"=="						return equal;
"!="						return nEqual;
"<"							return '<';
">"							return '>';
"<="						return lEqual;
">="						return gEqual;

"="							return '=';

"+="						return addAcc;
"-="						return subAcc;
"*="						return mulAcc;
"/="						return divAcc;
"%="						return modAcc;
"&="						return bAndAcc;
"|="						return bOrAcc;
"^="						return bXOrAcc;
"<<="						return shlAcc;
">>="						return shrAcc;

"&&"						return _and;
"||"						return _or;

";"							return ';';
","							return ',';
"{"							return '{';
"}"							return '}';
"["							return '[';
"]"							return ']';

"[["						return bOpen;
"]]"						return bClose;


[ \t\n\r]						;
<<EOF>>						return 0;

.							{ printf("error near '%s'\n", yytext); exit(-1); }

%%

int yywrap() { return 1; }