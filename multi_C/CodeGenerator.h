#ifndef CODEGENERATOR_H_
#define CODEGENERATOR_H_

#include <iostream>
#include <fstream>
#include "SymbolTable.h"
#include "AST.h"

class CodeGenerator
{
private:
	std::ofstream ofs;
	SymbolTable symbolTable;
	SYM_TYPE getType(const Node *typeNode) const;
	void generateCode(const Node *node);
	void printType(const Node *typeNode);
	void printVarDec(const Node *varDecNode);
	void printFuncDec(const Node *funcDecNode);
	void printSingleFuncDec(const Node *funcDecNode);
	void printMultiFuncDec(const Node *funcDecNode);
	void printParamList(const Node *firstParamNode, FuncEntry *funcEntry);
	void printExpression(const Node *operatorNode);
	void printFunctionCall(const Node *calledFuncNode);
	void printStatement(const Node *statementNode);
	void printOutput(const Node *outputNode);
public:
	void generateCode(const char *outFile, const Node& ASTroot);
	~CodeGenerator();
};

//class CodeGenerator {
//
//};

#endif
