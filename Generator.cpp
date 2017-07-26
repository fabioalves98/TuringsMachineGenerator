#include <iostream>
#include "ScanTable.h"
#include <unordered_map>

using namespace std;

int main() {
	ScanTable table("table.txt");
	table.printStates();
	table.printSymbols();
	table.printElems();
	return 0;
}