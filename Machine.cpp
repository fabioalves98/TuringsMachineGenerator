#include "Machine.h"

string chooseTable();
void createTable();
bool changeState(string line, bool *i, bool *t);
void removeSpaces(string *line);
void drawTable(unordered_map<string, string> table, vector<string> states, vector<string> symbols);
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
	cout << "\nList of Tables\n";
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
	do {
		cout << "Choose the table to simulated (0-" << count << ") os create a new one (C): ";
		string table;
		getline(cin, table);
		boost::to_upper(table);
		if (table.length() == 1) {
			if (isdigit(table[0])) {
				int index = stoi(table);
				if ((index >= 0) && (index <= count)) {
					return listOfTables[index];
				}
				else {
					cout << "Insert numbers between 0-" << count << endl;
				}
			}
			else if (table == "C") {
				createTable();
				return chooseTable();
			}
			else{
				cout << "Wrong Input\n";
			}
		}
		else {
			cout << "Wrong Input\n";
		}
	}
	while (true);
}

void createTable() {
	string name;
	cout << "Table Name: ";
	getline(cin, name);
	int nSt, nSy;
	bool wrong = true;
	do {
		string s_nSt, s_nSy;
		cout << "Number os States: ";
		getline(cin, s_nSt);
		cout << "Number os Symbols: ";
		getline(cin, s_nSy);
		if ((s_nSt.length() == 1) && (s_nSy.length() == 1)) {
			if ((isdigit(s_nSt[0])) && isdigit(s_nSy[0])) {
				if ((stoi(s_nSt) != 0) && (stoi(s_nSy) != 0)) {
					nSt = stoi(s_nSt);
					nSy = stoi(s_nSy);
					wrong = false;
				}
				else {
					cout << "Number must be higher than 0\n";
				}
			}
			else {
				cout << "Please enter numbers between 0-9\n";
			}
		}
		else {
			cout << "Please enter numbers between 0-9\n";
		}
	}
	while (wrong);
	unordered_map<string, string> table;
	vector<string> sts(nSt, " ");
	vector<string> sybs(nSy, " ");
	string bs;
	string is;
	string fs;
    drawTable(table, sts, sybs);
    for (int i = 0; i < nSt; i++) {
    	wrong = true;
    	do {
    		cout << "Enter State(" << i+1 << "/" << nSt << "): ";
			string state;
			getline(cin, state);
			if (state.length() == 1) {
				if (isalpha(state[0])) {
					if (find(sts.begin(), sts.end(), state) == sts.end()) {
						boost::to_upper(state);
						sts[i] = state;
						wrong = false;
					}
					else {
						cout << "That state already exists\n";
					}
				}
				else {
					cout << "Please enter an alphabetic character\n";
				}
			}
			else {
				cout << "Please enter an alphabetic character\n";
			}
    	}
    	while (wrong);
    }
    wrong = true;
	do {
	    cout << "Final State: ";
	    getline(cin, fs);
	    if (fs.length() == 1) {
			if (isalpha(fs[0])) {
				wrong = false;
			}
			else {
				cout << "Please enter an alphabetic character\n";
			}
		}
		else {
			cout << "Please enter an alphabetic character\n";
		}
    }
    while (wrong);
    drawTable(table, sts, sybs);
    for (int i = 0; i < nSy; i++) {
    	wrong = true;
    	do {
    		cout << "Enter Symbol(" << i+1 << "/" << nSy << "): ";
			string symbol;
			getline(cin, symbol);
	    	if (symbol.length() == 1) {
				if (isalnum(symbol[0])) {
					if (find(sybs.begin(), sybs.end(), symbol) == sybs.end()) {
						boost::to_lower(symbol);
						sybs[i] = symbol;
						wrong = false;
					}
					else {
						cout << "That symbol already exists\n";
					}
				}
				else {
					cout << "Please enter an alphanumeric character\n";
				}
			}
			else {
				cout << "Please enter an alphanumeric character\n";
			}
    	}
    	while (wrong);	
    }
    drawTable(table, sts, sybs);
	while (wrong);
    for (int i = 0; i < nSy; i++) {
    	for (int j = 0; j < nSt; j++) {
    		string index = sts[j] + sybs[i];
    		string symbol, move, state;
    		cout << "Enter " << index << ":\n";
    		wrong = true;
    		do {
	    		cout << "Write Symbol: "; 
				getline(cin, symbol);
				boost::to_lower(symbol);
				if (symbol.length() == 1) {
					if (find(sybs.begin(), sybs.end(), symbol) != sybs.end()) {
						wrong = false;
					}
					else {
						cout << "That symbol is not specified in the table\n";
					}
				}
				else {
					cout << "Please enter an alphanumeric character\n";
				}
			}
			while (wrong);
			wrong = true;
			do {
				cout << "Move Tape(R/L): "; 
				getline(cin, move);
				boost::to_upper(move);
				if ((move == "R") || (move == "L")) {
					wrong = false;
				}
				else {
					cout << "Pleas enter either R or L\n";
				}
			}
			while (wrong);
			wrong = true;
			do {
				cout << "Change State: ";
				getline(cin, state);
				boost::to_upper(state);
				if (state.length() == 1) {
					if ((find(sts.begin(), sts.end(), state) != sts.end()) || (state == fs)) {
						wrong = false;
					}
					else {
						cout << "That state is not specified in the table\n";
					}
				}
				else {
					cout << "Please enter an alphabetic character\n";
				}
			
			}
			while (wrong);
			table[index] = symbol + move + state;
    	}
    	drawTable(table, sts, sybs);
    }
    wrong = true;
    do {
	    cout << "Blanck Symbol: ";
   		getline(cin, bs);
   		boost::to_lower(bs);
		if (bs.length() == 1) {
			if (find(sybs.begin(), sybs.end(), bs) != sybs.end()) {
				wrong = false;
			}
			else {
				cout << "That symbol is not specified in the table\n";
			}
		}
		else {
			cout << "Please enter an alphanumeric character\n";
		}
    }
	while (wrong);
	wrong = true;
	do {
	    cout << "Initial State: ";
	    getline(cin, is);
		if (is.length() == 1) {
			if (find(sts.begin(), sts.end(), is) != sts.end()) {
				wrong = false;
			}
			else {
				cout << "That state is not specified in the table\n";
			}
		}
		else {
			cout << "Please enter an alphabetic character\n";
		}
    }
	while (wrong);
	ofstream create("tables/" + name + ".txt");
	create << "begin_info\n";
	create << "bs: " + bs << endl;
	create << "is: " + is << endl;
	create << "fs: " + fs << endl;
	create << "begin_table\n";
	create << "  \\  ";
	for (int i = 0; i < sts.size(); ++i) {
		create << "  " + sts[i] + "  ";
	}
	create << endl;
	for (int i = 0; i < sybs.size(); i++) {
		create << "  "  + sybs[i] + "  ";
		for (int j = 0; j < sts.size(); j++) {
			string index = sts[j] + sybs[i];
			create << " " << table[index] << " ";
		}
		create << endl;
	}
	create << "end_table";
	create.close();
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

void drawTable(unordered_map<string, string> table, vector<string> states, vector<string> symbols){
	cout << "\nTable:\n";
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
			string index = states[j] + symbols[i];
			if (table.find(index) != table.end()) {
				cout << " " << table[index] << " |";
			}
			else {
				cout << "     |";
			}
		}
		cout << endl << strHifen << endl;
	}
	cout << endl;
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
