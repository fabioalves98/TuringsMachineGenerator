#include "ScanTable.h"
#include <fstream>

using namespace std;

bool changeState(string line, bool *i, bool *t);
void removeSpaces(string *line);

ScanTable::ScanTable(string file) {
	ifstream scanner(file);
	string line;
	bool info = false, table = false;
	while (getline(scanner, line)) {
		if (changeState(line, &info, &table)) {
			continue;
		}
		else {
			if (info) {
				removeSpaces(&line);
				cout << line << endl;
				processInfo(line);
			}
			else if (table) {
				removeSpaces(&line);
				cout << line << endl;
				processTable(line);
			}
			else {
				break;
			}
		}
	}
	scanner.close();
}
void ScanTable::printStates() {
	for(auto it = states.begin(); it != states.end(); it++) {
		cout << *it << endl;
	}
}

void ScanTable::processInfo(string line) {
	string type = line.substr(0, 2);
	if (type == "bs") {
		blanckSym = line[3];
	}
	else if (type == "is") {
		inState = line[3];
	}
	else if (type == "fs") {
		haltState = line[3];
	}
	else {
		cout << "ERROR" << endl;
	}
}

void ScanTable::processTable(string line){
	if (line[0] == '\\') {
		line = line.substr(1);
		for (int i = 0; i < line.length(); ++i) {
			states.push_back(line[i]);
		}
	}
	else {
		symbols.push_back(line[0]);
		line = line.substr(1);
		cout << line << endl;
	}
}

struct action {
	int yolo;
	string test;
};

bool changeState(string line, bool *i, bool *t) {
	if (line == "begin_info") {
		*i = true;
		return true;
	}
	else if (line == "begin_table") {
		*i = false;
		*t = true;
		return true;
	}
	else if (line == "end_table") {
		*t = false;
		return true;
	}
}

void removeSpaces(string *line) {
	while(true){
		size_t pos = line->find(" ");
		if (pos != string::npos) {
			line->erase(pos, 1);
		}
		else {
			cout << "Done!" << endl;
			break;
		}
	}
}


