#include <iostream>
#include "Opt.h"

using namespace std;

void optExample(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	cout << "What do you want to test?" << endl;
	cout << "1. Opt object" << endl;
	cout << "2. Stack" << endl;

	optExample(argc, argv);
	return EXIT_SUCCESS;
}

void optExample(int argc, char* argv[]) {
	Opt o;

	o.add_int("-i", "Test integer, default value 3", 3);

	o.process(argc, argv);
}