#ifndef SCANTABLE_H
#define SCANTABLE_H

#include <iostream>
#include <vector>

typedef std::string string;

class ScanTable {
public:
	ScanTable(string txt);
	void printStates();
private:
	void processInfo(string line);
	void processTable(string line);
	struct action;
	std::vector<char> states; // container
	std::vector<char> symbols; // container
	char blanckSym;
	std::vector<char> inpSymbols; // container
	// Trans Function
	char inState;
	char haltState;
};

#endif // SCANTABLE_H