#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iterator>
#include <dirent.h>
#include <sys/stat.h>
#include <boost/algorithm/string.hpp>

using namespace std;

class Machine {
public:
	void scanTable();
	void printStates();
	void printSymbols();
	void printTable();
	void start();
	struct action {
		char wSymbol;
		char mTape;
		char nState;
	};
private:
	void processInfo(string line);
	void processTable(string line);
	void printTape(char state, int begin, int end);
	vector<char> states;
	vector<char> symbols;
	list<char> tape;
	unordered_map<string, action> transFunct;
	char blanckSym;
	char inState;
	char haltState;
};

#endif // MACHINE_H