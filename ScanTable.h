#ifndef SCANTABLE_H
#define SCANTABLE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

typedef std::string string;

class ScanTable {
public:
	ScanTable(string txt);
	void printStates();
	void printSymbols();
	void printElems();
private:
	void processInfo(string line);
	void processTable(string line);
	struct action {
		char wSymbol;
		char mTape;
		char nState;
	};
	std::vector<char> states; // container
	std::vector<char> symbols; // container
	char blanckSym;
	std::vector<char> inpSymbols; // container
	std::unordered_map<string, action> transFunct;
	char inState;
	char haltState;
};

#endif // SCANTABLE_H