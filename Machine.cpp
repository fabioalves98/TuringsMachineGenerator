#include "Machine.h"

using namespace std;

string getIndex(unordered_map<string, string> table, int sy, int st);
string chooseTable();
bool changeState(string line, bool *i, bool *t);
void removeSpaces(string *line);
void drawTable(unordered_map<string, string> table, int sy, int st);
void wait(double seconds);
template <class T> string makeKey(T st, T sy);

void Machine::scanTable() {
	string file = "tables/" + chooseTable();
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
	scanner.close();
}

void Machine::createTable() {
	string name;
	cout << "Table Name: ";
	cin >> name;
	int nSt, nSy;
	cout << "Number os States: ";
	cin >> nSt;
	cout << "Number os Symbols: ";
	cin >> nSy;
	unordered_map<string, string> table;
	table["00"] = "\\";
	drawTable(table, nSy, nSt);
    for (int i = 0; i <= nSy; i++) {
    	for (int j = 0; j <= nSt; j++) {
    		if ((i == 0) && (j == 0)) continue;
    		string key =  makeKey(j, i);
    		if (i == 0) {
				cout << "Enter State(" << j << "/" << nSt << "): ";
				string state;
				cin >> state;
				table[key] = state;
    		}
    		else {
    			if (j == 0) {
    				cout << "Enter Symbol: ";
    				string symbol;
    				cin >> symbol;
    				table[key] = symbol;
    			}
    			else {
    				cout << "Enter " << getIndex(table, i, j) << ":\n";
    				cout << "Write Symbol: "; 
    				string symbol;
    				cin >> symbol;
    				cout << "Move Tape(R/L): ";
    				string move; 
    				cin >> move;
    				cout << "Change State: ";
    				string state;
    				cin >> state;
    				table[key] = symbol + move + state;
    			}
    		}
    	}
    	drawTable(table, nSy, nSt);
    }
	//ofstream create("tables/" + name);
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

void Machine::printTable() {
	cout << "Table:\n";
	int numHifen = 5 + states.size()*6;
	string strHifen = "";
	for (int i = numHifen; i > 0; i--) strHifen += "-";
	cout << strHifen << endl;
	cout << "| \\ |";
	for (int i = 0; i < states.size(); i++) cout << "  " << states[i] << "  |";
	cout << endl << strHifen << endl;
	for (int i = 0; i < symbols.size(); i++) {
		cout << "| " << symbols[i] << " |";
		for (int j = 0; j < states.size(); j++) {
			string key = makeKey(states[j], symbols[i]);
			action move = transFunct[key];
			cout << " " << move.wSymbol << move.mTape << move.nState << " |";
		}
		cout << endl << strHifen << endl;
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
	cout << "Simulation: \n";
	int tapeSize = 21;
	tape.assign(21, blanckSym);
	char pState = inState;
	list<char>::iterator head = tape.begin();
	advance(head, tapeSize/2);
	int start = 0, end = tapeSize;
	int count = 0;
	printTape(pState, start, end);
	do {
		wait(0.2);
		char symbol = *head;
		string key = makeKey(pState, symbol);
		action move = transFunct[key];
		*head = move.wSymbol;
		if (move.mTape == 'R') {
			if (start == 0){
				tape.push_front(blanckSym);
			}
			else{
				start--;
				end--;
			}
			head = prev(head);
		}
		else {
			start++;
			end++;
			head = next(head);
			if (tape.size() < end) {
				tape.push_back(blanckSym);
			}
		}
		pState = move.nState;
		count++;
		//cout << " " << count << "  ";
		printTape(pState, start, end);
	} while (pState != haltState);
	cout << "Tape Size: " << tape.size() << endl;
	cout << "Machine Halted after " << count << " moves\n";
}

void Machine::printTape(char state, int begin, int end) {
	auto begin_it = tape.begin();
	auto end_it = tape.begin();
	advance(begin_it, begin);
	advance(end_it, end);
	cout << " " << state << "  ";
	for (begin_it; begin_it != end_it; begin_it++) {
		if (*begin_it == blanckSym){
			cout << "[" << *begin_it << "]";
		}
		else {
			cout << "\e[1m[" << *begin_it << "]\e[0m";
		}
		
	}
	cout << endl;
}

string getIndex(unordered_map<string, string> table, int sy, int st) {
	string state = table[makeKey(st, 0)];
	string symbol = table[makeKey(0, sy)];
	return state + symbol;
}

string chooseTable() {
	DIR *dir;
	struct dirent *entry;
	string dir_name = "tables";
	dir = opendir((char*)dir_name.c_str());
	int count = -1;
	vector<string> listOfTables;
	while ( (entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.') {
			string file = string(entry->d_name);
			listOfTables.push_back(file);
			count++;
			cout << "[" << count << "]" << " - " << file << endl;
		}
	}
	closedir(dir);
	cout << "Choose the table you would like to simulate (0-" << count << "): ";
	int table;
	cin >> table;
	return listOfTables[table];
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

void drawTable(unordered_map <string, string> table, int sy, int st){
	cout << "Table:\n";
	int numHifen = 5 + st*6;
	string sep = "";
	for (int i = numHifen; i > 0; i--) sep += "-";
	cout << sep << endl;
	for (int i = 0; i <= sy; i++) {
		cout << "|";
		for (int j = 0; j <= st; j++) {
			string key = makeKey(j, i);
			if ((i == 0) && (j != 0)) {
				if (table.find(key) != table.end()) {
					cout << "  " << table[key] << "  |";
				}
				else {
					cout << "     |";
				}
			}
			else {
				if (table.find(key) != table.end()) {
					cout << " " << table[key] << " |";
				}
				else {
					if (j == 0) {
						cout << "   |";
					}
					else {
						cout << "     |";
					}
				}
			}
		}
		cout << endl << sep << endl;
	}
}

void wait(double seconds) {
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

template <class T> string makeKey(T st, T sy) {
	string key;
	stringstream ss;
	ss << st << sy;
	ss >> key;
	return key;
}