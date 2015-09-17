#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <vector>
#include <utility>

enum SYM_TYPE {tINT, tCHAR, tSTRING};

typedef std::pair<SYM_TYPE, unsigned long long> Param;

class SymbolTable;

class SymTabEntry
{
	friend SymbolTable;
private:
	unsigned long long key;
public:
	SymTabEntry(unsigned long long key);
	virtual ~SymTabEntry(void);
	unsigned long long getKey();
};

class VarEntry : public SymTabEntry
{
	friend SymbolTable;
private:
	SYM_TYPE type;
	int initValue;
public:
	VarEntry(unsigned long long varKey, SYM_TYPE type, int initValue=0);
	~VarEntry(void);
};

class FuncEntry : public SymTabEntry
{
	friend SymbolTable;
private:
	std::vector<SYM_TYPE> *retValList;
	std::vector<Param> *paramList;
public:
	FuncEntry(unsigned long long funcKey);
	~FuncEntry(void);
	void addRetVal(SYM_TYPE type);
	void addParam(SYM_TYPE type, unsigned long long key);
};

class SingleScopeSymTab
{
	friend SymbolTable;
private:
	std::vector<SymTabEntry*> entry;
public:
	~SingleScopeSymTab(void);
	bool isInScope(unsigned long long key) const;
	void addEntry(SymTabEntry *newEntry);
	SymTabEntry* getEntry(unsigned long long key);
};

class SymbolTable
{
private:
	std::vector<SingleScopeSymTab*> symTab;
public:
	static unsigned long long hash(const char *str);
	void openNewScope(void);
	void closeLastScope(void);
	bool isInThisScope(unsigned long long key) const;
	bool isInScopes(unsigned long long key) const;
	void addEntry(SymTabEntry *symEntry);
	SymTabEntry* getEntry(unsigned long long key);
	//void printAll();
};
#endif
