#include <iostream>
#include "Opt.h"

using namespace std;

void optExample(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	cout << "What do you want to test?" << endl;
	cout << "1. Opt object" << endl;
	cout << "2. Stack" << endl;

	int value;
	cin >> value;
	
	if(value == 1) {
		optExample(argc, argv);
	}
	return EXIT_SUCCESS;
}

void optExample(int argc, char* argv[]) {
	Opt o;

	o.add_int("-i", "Test integer", 3);
	o.add_bool("-b", "Test boolean", false);
	o.add_string("-s", "Test string", "default");
	o.add_switch("-a", "a generic switch");

	o.process(argc, argv);
}