#include "Machine.h"

using namespace std;

bool changeState(string line, bool *i, bool *t);
void removeSpaces(string *line);
void wait(double seconds);
string makeKey(char st, char sy);

void Machine::scanTable(string file) {
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
				processInfo(line);
			}
			else if (table) {
				removeSpaces(&line);
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

void Machine::printStates() {
	cout << "States: ";
	for (auto it = states.begin(); it != states.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void Machine::printSymbols() {
	cout << "Symbols: ";
	for (auto it = symbols.begin(); it != symbols.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void Machine::printElems() {
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

void Machine::processInfo(string line) {
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

void Machine::processTable(string line){
	if (line[0] == '\\') {
		line = line.substr(1);
		for (int i = 0; i < line.length(); ++i) {
			states.push_back(line[i]);
		}
	}
	else {
		symbols.push_back(line[0]);
		line = line.substr(1);
		int count = 0 ;
		while (line.length() != 0) {
			string elem = line.substr(0,3);
			line = line.substr(3);
			char state = states[count];
			char symbol = symbols.back();
			string key = makeKey(state, symbol);
			action act;
			act.wSymbol = elem[0];
			act.mTape = elem[1];
			act.nState = elem[2];
			transFunct.emplace(key, act);
			count++;
		}
	}
}

void Machine::start() {
	int tapeSize = 21;
	tape.assign(21, blanckSym);
	char pState = inState;
	list<char>::iterator head = tape.begin();
	advance(head, tapeSize/2);
	do {
		printTape();
		char symbol = *head;
		string key = makeKey(pState, symbol);
		action move = transFunct[key];
		*head = move.wSymbol;
		if (move.mTape == 'R') {
			head = prev(head);
		}
		else {
			head = next(head);
		}
		pState = move.nState;
		wait(1);
	} while (pState != haltState);
}

void Machine::printTape() {
	for (auto it = tape.begin(); it != tape.end(); it++) {
		cout << "[" << *it << "]";
	}
	cout << endl;
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
			break;
		}
	}
}

void wait(double seconds) {
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

string makeKey(char st, char sy) {
	string key;
	stringstream ss;
	ss << st << sy;
	ss >> key;
	return key;
}
