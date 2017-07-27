#include <iostream>
#include "Machine.h"

using namespace std;

int main() {
	Machine table;
	table.scanTable("table.txt");
	table.printStates();
	table.printSymbols();
	table.printElems();
	table.start();
	return 0;
}