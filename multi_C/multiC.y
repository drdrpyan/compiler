%{
//=======================================================================
//최종 갱신일 2014.11.24
//-----------------------------------------------------------------------
////갱신 기록
////2014.10.10
////2014.10.12 treeDrawer적용(추가 수정 필요), 비교연산 적용중
////2014.10.13 비교 연산 완료. statement, statmentlist 제작, 서브루틴 중첩 구성중
////2014.10.31 treeDrawer 제거, expression 계층구소 완성
////2014.11.1  변수 선언문 90%완성. 함수부분 완성 후 VarList초기화 수정할 것
////2014.11.2  루프문 완성. if문 dangling else 문제 해결할 것
////2014.11.23 수 연산 부분에 AST 구현.
////2014.11.24 dangling else 해결, IOStmt추가, FuncDefine 수정
////2014 11.24 SYMTAB 구성중(변수명은 10자까지 가능)
////2014.11.24 if-else 충돌 재발생 <- 해결
////2014.11.30 c++적용(전방 선언), ast완성, 함수 문법 추가
//=======================================================================
#include <stdio.h>
#include "CodeGenerator.h"
#include "AST.h"

//시작 SCOPE
int scope = 0;

int yylex();
int yyparse();
int yywrap();
int yyerror(const char *msg) { fputs(msg, stderr); return -1; }

struct _node* ASTRoot;

%}

%union {
	struct _node* pVal;
	char cVal;
	int iVal;
	char *sVal;
}

%type <pVal> Variable Function Factor Term ArithExpr ShiftExpr CmpExpr EqualExpr BitOrExpr BitExOrExpr BitAndExpr LAndExpr LOrExpr AssignExpr Expr
%type <pVal> OutStmtBeg OutStmt InStmtBeg InStmt IOStmt LoopStmt CompStmt CondStmt ExprStmt MAssignStmt Stmt StmtList
%type <pVal> VarList VarListBeg VarForDec VarDecList VarDeclare
%type <pVal> Type TypeList TypeListBeg Parameter ParamList
%type <pVal> FuncHeader FuncDefine FuncDeclare FuncList
%type <pVal> Program
%token <iVal> num
%token <sVal> id
%token shiftL shiftR equal nEqual lEqual gEqual _and _or
%token addAcc subAcc mulAcc divAcc modAcc bAndAcc bOrAcc bXOrAcc shlAcc shrAcc
%token tInt tChar tVoid tStr 
%token _if _else _for _while _do _return bOpen bClose

%nonassoc _ifx
%nonassoc _else
%%
Program		:	VarDecList FuncList				{ $$ = mknode(PROGRAM, 0, 2, $1, $2); ASTRoot = $$; }
			|	VarDecList						{ $$ = mknode(PROGRAM, 0, 1, $1); ASTRoot = $$;}
			|	FuncList						{ $$ = mknode(PROGRAM, 0, 1, $1); ASTRoot = $$;}
			;
			
FuncList	:	FuncList FuncDeclare			{ addSon($1, $2); $$ = $1; }
			|	FuncList FuncDefine				{ addSon($1, $2); $$ = $1; }
			|	FuncDeclare						{ $$ = mknode(FUNC_LIST, 0, 1, $1); }
			|	FuncDefine						{ $$ = mknode(FUNC_LIST, 0, 1, $1); }
			;

FuncDeclare	:	FuncHeader ';'					{ $$ = $1; }
			;

FuncDefine	:	FuncHeader CompStmt				{ addSon($1, $2); $$ = $1; }
			;
			
FuncHeader	:	tVoid id '(' ParamList ')'		{ $$ = mknode(FUNC_DEC, 0, 3, mkleaf(VOID, VOID), mkleaf(ID, (int)$2), $4); }
			|	Type id '(' ParamList ')'		{ $$ = mknode(FUNC_DEC, 0, 3, $1, mkleaf(ID, (int)$2), $4); }
			|	TypeList id '(' ParamList ')'	{ $$ = mknode(FUNC_DEC, 0, 3, $1, mkleaf(ID, (int)$2), $4); }
			;
						
ParamList	:	ParamList ',' Parameter			{ addBro($1, $3); $$ = $1; }
			|	Parameter						{ $$ = $1; }
			;
			
Parameter	:	Type id							{ $$ = mknode(PARAM, 0, 2, $1, mkleaf(ID, (int)$2)); }
			;
			
TypeList	:	TypeListBeg '}'					{ $$ = $1; }
			;
			
TypeListBeg	:	TypeListBeg ',' Type			{ addSon($1, $3); $$ = $1; }
			|	'{' Type ',' Type				{ $$ = mknode(TYPE_LIST, 0, 2, $2, $4); }
			
Type		:	tInt							{ $$ = mkleaf(TYPE, INT); }
			|	tChar							{ $$ = mkleaf(TYPE, CHAR); }
			|	tStr							{ $$ = mkleaf(TYPE, STRING); }
			;
			
StmtList	:	StmtList Stmt					{ addBro($1, $2); $$ = $1; }
			|	Stmt							{ $$ = $1; }
			;
			
Stmt		:	ExprStmt						{ $$ = $1; }
			|	CompStmt						{ $$ = $1; }
			|	CondStmt						{ $$ = $1; }
			|	LoopStmt						{ $$ = $1; }
			|	IOStmt							{ $$ = $1; }
			|	_return ExprStmt				{ $$ = mknode(RETURN, 0, 1, $2); }
			|	'(' MAssignStmt ')' 			{ $$ = $2; }
			;
			
ExprStmt	:	Expr ';'						{ $$ = $1; }
			|	';'								{ $$ = mkleaf(NIL, 0); }
			;
			
CompStmt	:	'{' '}'							{ $$ = mknode(STMT, 0, 1, mkleaf(NIL, 0)); }
			|	'{' VarDecList '}'				{ $$ = mknode(STMT, 0, 1, $2); }
			|	'{' StmtList '}'				{ $$ = mknode(STMT, 0, 1, $2); }
			|	'{' VarDecList StmtList '}'		{ $$ = mknode(STMT, 0, 2, $2, $3); }
			;
			
CondStmt	:	_if '(' Expr ')' Stmt %prec _ifx	{ $$ = mknode(IF, 0, 2, $3, $5); }
			|	_if '(' Expr ')' Stmt _else Stmt	{ $$ = mknode(IF, 0, 3, $3, $5, $7); } 
			;
			
LoopStmt	:	_for '(' ExprStmt ExprStmt Expr ')' Stmt	{ $$ = mknode(FOR, 0, 4, $3, $4, $5, $7); }
			|	_while '(' Expr ')' Stmt			{ $$ = mknode(WHILE, 0, 2, $3, $5); }
			|	_do Stmt _while '(' Expr ')' ';'	{ $$ = mknode(DO, 0, 2, $2, $5); }
			;
			
IOStmt		:	InStmt							{ $$ = $1; }
			|	OutStmt							{ $$ = $1; }
			;
			
InStmt		:	InStmtBeg bOpen					{ $$ = $1; }
			;

InStmtBeg	:	InStmtBeg Expr					{ addSon($1, $2); $$ = $1; }
			|	bClose Expr						{ $$ = mknode(INPUT, 0, 1, $2); }
			;

OutStmt		:	OutStmtBeg bClose				{ $$ = $1; }
			;
			
OutStmtBeg	:	OutStmtBeg Expr					{ addSon($1, $2); $$ = $1; }
			|	bOpen Expr						{ $$ = mknode(OUTPUT, 0, 1, $2); }
			;

VarDecList	:	VarDecList VarDeclare			{ addSon($1, $2); $$ = $1; }
			|	VarDeclare						{ $$ = mknode(VAR_DEC_LIST, 0, 1, $1); }
			;
			
VarDeclare	:	Type VarForDec ';'				{ $$ = mknode(VAR_DEC, 0, 2, $1, $2); }
			;
			
VarForDec	:	VarForDec ',' id '=' AssignExpr	{ addBro($1, mknode(OP_ASSIGN, 0, 2, mkleaf(VAR, (int)$3), $5)); $$ = $1; }
			|	VarForDec ',' id				{ addBro($1, mkleaf(VAR, (int)$3)); $$ = $1; }
			|	id '=' AssignExpr				{ $$ = mknode(OP_ASSIGN, 0, 2, mkleaf(VAR, (int)$1), $3); }
			|	id								{ $$ = mkleaf(VAR, (int)$1); }
			;
			
MAssignStmt	:	VarList '=' Function ';'		{ $$ = mknode(OP_ASSIGN, 0, 2, $1, $3); }
			;
			
VarList		:	VarListBeg '}'					{ $$ = $1; }
			;

VarListBeg	:	VarListBeg ',' id				{ addSon($1, mkleaf(VAR, (int)$3)); $$ = $1; }
			|	'{' id							{ $$ = mknode(VAR_LIST, 0, 1, mkleaf(VAR, (int)$2)); }
			;		
			
Expr		:	Expr ',' AssignExpr				{ addBro($1, $3); $$ = $1; }
			|	AssignExpr						{ $$ = $1; }
			;		
			
AssignExpr	:	Variable '=' AssignExpr			{ $$ = mknode(OP_ASSIGN, 0, 2, $1, $3); }
			|	Variable addAcc AssignExpr		{ $$ = mknode(OP_ADD_ACC, 0, 2, $1, $3); }
			|	Variable subAcc AssignExpr		{ $$ = mknode(OP_SUB_ACC, 0, 2, $1, $3); }
			|	Variable mulAcc AssignExpr		{ $$ = mknode(OP_MUL_ACC, 0, 2, $1, $3); }
			|	Variable divAcc AssignExpr		{ $$ = mknode(OP_DIV_ACC, 0, 2, $1, $3); }
			|	Variable modAcc AssignExpr		{ $$ = mknode(OP_MOD_ACC, 0, 2, $1, $3); }
			|	Variable bAndAcc AssignExpr		{ $$ = mknode(OP_BAND_ACC, 0, 2, $1, $3); }
			|	Variable bOrAcc AssignExpr		{ $$ = mknode(OP_BOR_ACC, 0, 2, $1, $3); }
			|	Variable bXOrAcc AssignExpr		{ $$ = mknode(OP_BXOR_ACC, 0, 2, $1, $3); }
			|	Variable shlAcc AssignExpr		{ $$ = mknode(OP_SHL_ACC, 0, 2, $1, $3); }
			|	Variable shrAcc AssignExpr		{ $$ = mknode(OP_SHR_ACC, 0, 2, $1, $3); }
			|	LOrExpr							{ $$ = $1; }
			;

LOrExpr		:	LOrExpr _or LAndExpr			{ $$ = mknode(OP_L_OR, 0, 2, $1, $3); }
			|	LAndExpr						{ $$ = $1; }
			;

LAndExpr	:	LAndExpr _and BitOrExpr			{ $$ = mknode(OP_L_AND, 0, 2, $1, $3); }
			|	BitOrExpr						{ $$ = $1; }
			;

BitOrExpr	:	BitOrExpr '|' BitExOrExpr		{ $$ = mknode(OP_B_OR, 0, 2, $1, $3); }
			|	BitExOrExpr						{ $$ = $1; }
			;

BitExOrExpr	:	BitExOrExpr '^' BitAndExpr		{ $$ = mknode(OP_B_XOR, 0, 2, $1, $3); }
			|	BitAndExpr						{ $$ = $1; }
			;

BitAndExpr	:	BitAndExpr '&' EqualExpr		{ $$ = mknode(OP_B_AND, 0, 2, $1, $3); }
			|	EqualExpr						{ $$ = $1; }
			;

EqualExpr	:	EqualExpr equal CmpExpr			{ $$ = mknode(OP_EQUAL, 0, 2, $1, $3); }
			|	EqualExpr nEqual CmpExpr		{ $$ = mknode(OP_NEQUAL, 0, 2, $1, $3); }
			|	CmpExpr							{ $$ = $1; }
			;
			
CmpExpr		:	CmpExpr '<' ShiftExpr			{ $$ = mknode(OP_LESS, 0, 2, $1, $3); }
			|	CmpExpr lEqual ShiftExpr		{ $$ = mknode(OP_LESS_EQUAL, 0, 2, $1, $3); }
			|	CmpExpr '>' ShiftExpr			{ $$ = mknode(OP_GREAT, 0, 2, $1, $3); }
			|	CmpExpr gEqual ShiftExpr		{ $$ = mknode(OP_GREAT_EQUAL, 0, 2, $1, $3); }
			|	ShiftExpr						{ $$ = $1; }
			;
			
ShiftExpr	:	ShiftExpr shiftL ArithExpr		{ $$ = mknode(OP_SHL, 0, 2, $1, $3);}
			|	ShiftExpr shiftR ArithExpr		{ $$ = mknode(OP_SHR, 0, 2, $1, $3); }
			|	ArithExpr						{ $$ = $1;}
			;
			
ArithExpr	:	ArithExpr '+' Term				{ $$ = mknode(OP_ADD, 0, 2, $1, $3); }
			|	ArithExpr '-' Term				{ $$ = mknode(OP_SUB, 0, 2, $1, $3); }
			|	Term							{ $$ = $1; }
			;
		
Term		:	Term '*' Factor					{ $$ = mknode(OP_MUL, 0, 2, $1, $3); }
			|	Term '/' Factor					{ $$ = mknode(OP_DIV, 0, 2, $1, $3); }
			|	Term '%' Factor					{ $$ = mknode(OP_MOD, 0, 2, $1, $3); }
			|	Factor							{ $$ = $1; }
			;

Factor		:	num								{ $$ = mkleaf(INT, $1); }
			|	'(' Expr ')'					{ $$ = $2; }
			|	Function						{ $$ = $1; }
			;
			
Function	:	Function '(' Expr ')'			{ setKind($1, ID); $$ = mknode(FUNCTION, 0, 2, $1, $3); }
			|	Function '(' ')'				{ setKind($1, ID); $$ = mknode(FUNCTION, 0, 1, $1); }
			|	Variable						{ $$ = $1; }
			;
			
Variable	:	id 								{ $$ = mkleaf(VAR, (int)$1); }
			;
%%

int main() {
	CodeGenerator cg;
	yyparse();
	prtree(0, ASTRoot, 0);
	cg.generateCode("outCode.txt", *ASTRoot);
	printf("compile end\n");
	return 0;
}