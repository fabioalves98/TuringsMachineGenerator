#include <iostream>
#include "ScanTable.h"

using namespace std;

int main() {
	ScanTable table("table.txt");
	table.printStates();
	return 0;
}