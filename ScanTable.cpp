#include "ScanTable.h"

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
				//cout << line << endl;
				processInfo(line);
			}
			else if (table) {
				removeSpaces(&line);
				//cout << line << endl;
				processTable(line);
			}
			else {
				break;
			}
		}
	}
	cout << transFunct.size() << endl;
	scanner.close();
}

void ScanTable::printStates() {
	cout << "States: ";
	for (auto it = states.begin(); it != states.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void ScanTable::printSymbols() {
	cout << "Symbols: ";
	for (auto it = symbols.begin(); it != symbols.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void ScanTable::printElems() {
	for (auto it = states.begin(); it != states.end(); it++) {
		for (auto it2 = symbols.begin(); it2 != symbols.end(); it2++) {
			stringstream ss;
			string key;
			ss << *it << *it2;
			ss >> key;
			cout << key << ": " << endl;
			cout << "  Write " << transFunct[key].wSymbol << endl;
			cout << "  Move Tape " << transFunct[key].mTape << endl;
			cout << "  Go to State " << transFunct[key].nState << endl;
		}
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
		//cout << line << endl;
		int count = 0 ;
		while (line.length() != 0) {
			string elem = line.substr(0,3);
			line = line.substr(3);
			char state = states[count];
			char symbol = symbols.back();
			string key;
			stringstream ss;
			ss << state << symbol;
			ss >> key;
			action act;
			act.wSymbol = elem[0];
			act.mTape = elem[1];
			act.nState = elem[2];
			transFunct.emplace(key, act);
			count++;
		}
	}
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

void removeSpaces(string *line) {
	while(true){
		size_t pos = line->find(" ");
		if (pos != string::npos) {
			line->erase(pos, 1);
		}
		else {
			//cout << "Done!" << endl;
			break;
		}
	}
}


