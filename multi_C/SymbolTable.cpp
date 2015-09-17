#include "SymbolTable.h"


//for debug
#include <iostream>
using std::cout;
using std::cin;
using std::endl;




SymTabEntry::SymTabEntry(unsigned long long key) : key(key)
{
}

SymTabEntry::~SymTabEntry(void)
{
}

unsigned long long SymTabEntry::getKey(void)
{
	return key;
}

VarEntry::VarEntry(unsigned long long varKey, SYM_TYPE type, int initValue)
	: SymTabEntry(varKey), type(type), initValue(initValue)
{
}

VarEntry::~VarEntry(void)
{
}

FuncEntry::FuncEntry(unsigned long long funcKey) : SymTabEntry(funcKey)
{
	retValList = new std::vector<SYM_TYPE>;
	paramList = new std::vector<Param>;
}

FuncEntry::~FuncEntry(void)
{
	retValList->clear();
	delete retValList;
	paramList->clear();
	delete paramList;
}

void FuncEntry::addRetVal(SYM_TYPE type)
{
	retValList->push_back(type);
}

void FuncEntry::addParam(SYM_TYPE type, unsigned long long key)
{
	paramList->push_back(Param(type, key));
}

SingleScopeSymTab::~SingleScopeSymTab(void)
{
	entry.clear();
}

bool SingleScopeSymTab::isInScope(unsigned long long key) const
{
	if(entry.empty())
		return false;
	for(unsigned int i=0; i<entry.size(); i++)
		if(entry[i]->getKey() == key)
			return true;
	return false;
}

void SingleScopeSymTab::addEntry(SymTabEntry *newEntry)
{
	entry.push_back(newEntry);
}

SymTabEntry* SingleScopeSymTab::getEntry(unsigned long long key)
{
	for(unsigned int i=0; i<entry.size(); i++)
		if(entry[i]->getKey() == key)
			return entry[i];
	return 0;
}

unsigned long long SymbolTable::hash(const char *str)
{
	unsigned long long value = 0;
	int i = 0;

	value += (unsigned long long)str[0];
	for(i=1; i<10 && str[i]; i++)
	{
		value *= 67;
		value += (unsigned long long)str[i];
	}

	return value;
}

void SymbolTable::openNewScope(void)
{
	symTab.push_back(new SingleScopeSymTab);
}

void SymbolTable::closeLastScope(void)
{
	symTab.pop_back();
}

bool SymbolTable::isInThisScope(unsigned long long key) const
{
	return symTab.back()->isInScope(key);
}

bool SymbolTable::isInScopes(unsigned long long key) const
{
	if(symTab.empty())
		return false;

	for(unsigned int i=symTab.size()-1; i>0; i--)
	{
		if(symTab[i]->isInScope(key))
			return true;
	}
	return symTab[0]->isInScope(key);
}

void SymbolTable::addEntry(SymTabEntry *symEntry)
{
	symTab.back()->addEntry(symEntry);
}

SymTabEntry* SymbolTable::getEntry(unsigned long long key)
{
	SymTabEntry *e;
	for(unsigned i=symTab.size()-1; i>=0; i--)
	{
		e = symTab[i]->getEntry(key);
		if(e)
			return e;
	}
	return 0;
}

//void SymbolTable::printAll(void)
//{
//	for(unsigned int i=0; i<symTab.size(); i++)
//		for(unsigned int j=0; j<symTab[i]->entry.size(); j++)
//			cout << i << " : " << j << " : " << symTab[i]->entry[j]->getKey() << endl;
//}
//
//int main(void)
//{
//	SymbolTable st;
//	st.openNewScope();
//	st.addEntry(new VarEntry(1, tINT, 0));
//	st.openNewScope();
//	st.addEntry(new VarEntry(2, tCHAR, 0));
//	st.addEntry(new VarEntry(3, tCHAR, 0));
//
//st.closeLastScope();
//st.printAll();
//
//	cout << st.isInThisScope(1) << ' ' << st.isInThisScope(2) << endl;
//	cout << st.isInScopes(1) << endl;
//	cout << st.isInScopes(0) << endl;
//	return 0;
//}
