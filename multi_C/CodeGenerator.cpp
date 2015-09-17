#include "CodeGenerator.h"
#include <stdlib.h>

CodeGenerator::~CodeGenerator()
{
	ofs.close();
}

void CodeGenerator::generateCode(const char *outFile, const Node& ASTroot)
{
	ofs.open(outFile, std::ios::out);
	generateCode(&ASTroot);
}

SYM_TYPE CodeGenerator::getType(const Node *typeNode) const
{
	SYM_TYPE type;
	switch((nodeKind)(typeNode->val.iVal))
	{
	case INT:
		type = tINT;
		break;
	case CHAR:
		type = tCHAR;
		break;
	case STRING:
		type = tSTRING;
		break;
	}
	return type;
}

void CodeGenerator::printType(const Node *typeNode)
{
	switch((nodeKind)(typeNode->val.iVal))
	{
	case INT:
		ofs << "int";
		break;
	case CHAR:
		ofs << "char";
		break;
	case STRING:
		ofs << "char*";
		break;
	}
}

void CodeGenerator::printVarDec(const Node *varDecNode)
{
	Node *typeNode = varDecNode->son;
	SYM_TYPE type = getType(typeNode);
	printType(typeNode);
	ofs << ' ';

	Node *restNode = typeNode->bro;
	Node *varNameNode;
	unsigned long long key;
	while(restNode)
	{
		varNameNode = (restNode->kind==OP_ASSIGN) ? restNode->son : restNode;
		key = SymbolTable::hash(varNameNode->val.sVal);
		if(symbolTable.isInThisScope(key))
		{
			std::cerr << "variable is duplicated : " << varNameNode->val.sVal << std::endl;
			exit(-1);
		}
		else
		{
			symbolTable.addEntry(new VarEntry(key, type));
			ofs << varNameNode->val.sVal;
		}

		if(restNode->kind==OP_ASSIGN)
		{
			ofs << '=';
			printExpression(varNameNode->bro);
		}

		restNode = restNode->bro;
		if(restNode)
			ofs << ", ";
	}
	ofs << ';' << std::endl;
}

void CodeGenerator::printFuncDec(const Node *funcDecNode)
{

	Node *typeListNode = funcDecNode->son;
	if(typeListNode->kind == TYPE)
		printSingleFuncDec(funcDecNode);
	else if(typeListNode->kind == TYPE_LIST)
		printMultiFuncDec(funcDecNode);
}

void CodeGenerator::printSingleFuncDec(const Node *funcDecNode)
{
	Node *typeNode = funcDecNode->son;
	SYM_TYPE type = getType(typeNode);
	printType(typeNode);
	ofs << ' ';

	Node *funcNameNode = typeNode->bro;
	Node *paramNode = funcNameNode->bro;
	FuncEntry *funcEntry;
	unsigned long long key = SymbolTable::hash(funcNameNode->val.sVal);
	if(symbolTable.isInThisScope(key))
	{
		std::cerr << "function is duplicated : " << funcNameNode->val.sVal << std::endl;
		exit(-1);
	}
	else
	{
		funcEntry = new FuncEntry(key);
		funcEntry->addRetVal(type);
		symbolTable.addEntry(funcEntry);
		symbolTable.openNewScope();

		ofs << funcNameNode->val.sVal << '(';
		printParamList(paramNode, funcEntry);
		while(paramNode->kind == PARAM)
			paramNode = paramNode->bro;
		ofs << ')' << std::endl;

		ofs << '{' << std::endl;
		printStatement(paramNode);
		ofs << '}' << std::endl;

		symbolTable.closeLastScope();
	}
}

void CodeGenerator::printMultiFuncDec(const Node *funcDecNode)
{

}

void CodeGenerator::printParamList(const Node *firstParamNode, FuncEntry *funcEntry)
{
	Node *paramNode = const_cast<Node*>(firstParamNode);
	Node *paramTypeNode, *paramNameNode;
	unsigned long long key;
	SYM_TYPE type;
	while(paramNode->kind == PARAM)
	{
		paramTypeNode = paramNode->son;
		paramNameNode = paramTypeNode->bro;
		key = SymbolTable::hash(paramNameNode->val.sVal);
		if(symbolTable.isInThisScope(key))
		{
			std::cerr << "parameter is duplicated : " << paramNameNode->val.sVal << std::endl;
			exit(-1);
		}
		else
		{
			type = getType(paramTypeNode);
			funcEntry->addParam(type, key);
			printType(paramTypeNode);
			ofs << ' ' << paramNameNode->val.sVal;
		}
		paramNode = paramNode->bro;
		if(paramNode->kind == PARAM)
			ofs << ", ";
	}
}

void CodeGenerator::printExpression(const Node *operatorNode)
{
	if(!operatorNode)
		return;

	unsigned long long key;
	switch(operatorNode->kind)
	{
	case VAR:
		key = SymbolTable::hash(operatorNode->val.sVal);
		if(symbolTable.isInScopes(key))
			ofs << operatorNode->val.sVal;
		else
		{
			std::cerr << "variable is not declared : " << operatorNode->val.sVal << std::endl;
			exit(-1);
		}
		break;

	case INT:
		ofs << operatorNode->val.iVal;
		break;

	case CHAR:
		ofs << operatorNode->val.cVal;
		break;

	case STRING:
		ofs << '\"' << operatorNode->val.sVal << '\"';
		break;

//	case FUNCTION:
//		break;
	}

	printExpression(operatorNode->son);
	if(operatorNode->son)
		printExpression(operatorNode->son->bro);
}

void CodeGenerator::printFunctionCall(const Node *calledFuncNode)
{

}

void CodeGenerator::printStatement(const Node *statementNode)
{
	Node *son = statementNode->son;
	Node *grandSon = son->son;
	while(son)
	{
		switch(son->kind)
		{
		case VAR_DEC_LIST:
			while(grandSon)
			{
				printVarDec(grandSon);
				grandSon = grandSon->bro;
			}
			break;

		case OUTPUT:
			printOutput(son);
			break;

		///아직 여러가지 남음
		case STMT:
			symbolTable.openNewScope();
			printStatement(son);
			symbolTable.closeLastScope();
			break;
		}
		son = son->bro;
		if(son)
			grandSon = son->son;
	}
}

void CodeGenerator::printOutput(const Node *outputNode)
{
	ofs << "std::cout << ";
	Node *argument = outputNode->son;
	while(argument)
	{
		printExpression(argument);
		argument = argument->bro;
		if(argument)
			ofs << " << ";
	}
	ofs << ';' << std::endl;
}

void CodeGenerator::generateCode(const Node *node)
{
	if(node == 0)
		return;
	switch(node->kind)
	{
	case PROGRAM:
		symbolTable.openNewScope();
		break;

	case VAR_DEC:
		printVarDec(node);
		break;

	case FUNC_DEC:
		printFuncDec(node);
		break;
	}
	generateCode(node->son);
	generateCode(node->bro);
}
