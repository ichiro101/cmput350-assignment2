#include "Opt.h"

Opt::Opt(void) {

}

Opt::~Opt(void) {
}

void Opt::process(int argc, char* argv[]) {
	std::vector<std::string> argumentsInString;
	for(int i = 0; i < argc; i++) {
		argumentsInString.push_back(std::string(argv[i]));
	}

	std::map<std::string, Option*>::iterator iter;
	for(iter = this->argumentMap.begin(); iter != this->argumentMap.end(); iter++) {
		std::vector<std::string>::iterator argIter = std::find(argumentsInString.begin(), argumentsInString.end(), iter->first);
		if(argIter != argumentsInString.end()) {
			if(iter->second->getType() == TypeGeneric) {
				throw "FATAL ERROR 1";
			} else if(iter->second->getType() == TypeSwitch) {
				Option* switchOption = this->argumentMap.find(iter->first)->second;
				static_cast<SwitchOption*>(switchOption)->value = true;
			} else if(iter->second->getType() == TypeInteger) {
				Option* integerOption = this->argumentMap.find(iter->first)->second;

				// take the next option for the value of the argument
				argIter++;
				int value = atoi(argIter->c_str());
				static_cast<IntegerOption*>(integerOption)->value = value;
			} else {
				throw "FATAL ERROR 2";
			}
		}
	}
}

void Opt::add_switch(std::string option, std::string description) {
	SwitchOption* switchOption = new SwitchOption;
	switchOption->option = option;
	switchOption->description = description;
	switchOption->value = false;
	this->argumentMap.insert(std::pair<std::string, Option*>(option, switchOption));
}

void Opt::add_bool(std::string option, std::string description, bool value) {
	BoolOption* boolOption = new BoolOption;
	boolOption->option = option;
	boolOption->description = description;
	boolOption->value = value;
	this->argumentMap.insert(std::pair<std::string, Option*>(option, boolOption));
}

void Opt::add_int(std::string option, std::string description, int value) {
	IntegerOption* integerOption = new IntegerOption;
	integerOption->option = option;
	integerOption->description = description;
	integerOption->value = value;
	this->argumentMap.insert(std::pair<std::string, Option*>(option, integerOption));
}

void Opt::add_double(std::string option, std::string description, double value) {
	DoubleOption* doubleOption = new DoubleOption;
	doubleOption->option = option;
	doubleOption->description = description;
	doubleOption->value = value;
	this->argumentMap.insert(std::pair<std::string, Option*>(option, doubleOption));
}

void Opt::add_string(std::string option, std::string description, std::string value) {
	StringOption* strOption = new StringOption;
	strOption->option = option;
	strOption->description = description;
	strOption->value = value;
	this->argumentMap.insert(std::pair<std::string, Option*>(option, strOption));
}

bool Opt::get_switch(std::string option) {
	Option* switchOption = this->argumentMap.find(option)->second;
	return static_cast<BoolOption*>(switchOption)->value;
}

int Opt::get_int(std::string option) {
	Option* intOption = this->argumentMap.find(option)->second;
	return static_cast<IntegerOption*>(intOption)->value;
}

bool Opt::get_bool(std::string option) {
	return false;
}

double Opt::get_double(std::string option) {
	return 2.0;
}

std::string Opt::get_string(std::string option) {

	return "test";
}