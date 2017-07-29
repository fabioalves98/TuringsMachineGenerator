#include <iostream>
#include "Machine.h"

using namespace std;

int main() {
	cout << "Turring's Machine Generator\n";
	Machine table;
	table.createTable();
	table.scanTable();
	table.printStates();
	table.printSymbols();
	table.printTable();
	cout << "Do you wish to simulate the above Machine? (y/n): ";
	char opt;
	cin >> opt;
	if (opt == 'y') {
		table.start();
	}
	else {
		cout << "GoodBye!!!\n";
	}
	return 0;
}

