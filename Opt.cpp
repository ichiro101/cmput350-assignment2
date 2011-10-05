#include "Opt.h"

Opt::Opt(void) {

}

Opt::~Opt(void) {

}

void process(int argc, std::string argv[]) {
	std::vector<std::string> argumentsInString;
	for(int i = 0; i < argc; i++) {
		argumentsInString.push_back(std::string(argv[i]));
	}

	for(int i = 0; i < argc; i++) {
	}
}

void Opt::add_switch(std::string option, std::string description) {

}

void Opt::add_int(std::string option, std::string description, int value) {

}

bool Opt::get_swtich(std::string option) {
	return true;
}

int Opt::get_int(std::string option) {
	return 2;
}