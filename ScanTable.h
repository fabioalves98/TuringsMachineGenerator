#ifndef SCANTABLE_H
#define SCANTABLE_H

#include <iostream>

typedef std::string string;

class ScanTable {
public:
	ScanTable(string txt);
private:
	char *states;
	char *symbols;
	char blanckSym;
	char *inpSymbols;
	// Trans Function
	char inState;
	char haltState;
};

#endif // SCANTABLE_H