flex -o lex.yy.cpp multiC.l
bison -dy -o y.tab.cpp multiC.y
g++ -o multiC lex.yy.cpp y.tab.cpp y.tab.hpp AST.h AST.c SymbolTable.h SymbolTable.cpp CodeGenerator.h CodeGenerator.cpp -fpermissive -std=gnu++0x