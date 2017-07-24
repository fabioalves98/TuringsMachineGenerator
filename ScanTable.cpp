#include "ScanTable.h"
#include <fstream>

using namespace std;

bool changeState(string line, bool *i, bool *t);

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
				//process info
			}
			else if (table) {
				//process table
			}
			else {
				break;
			}
		}
	}
	scanner.close();
}

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
