#include "Opt.h"

Opt::Opt(void) {

}

Opt::~Opt(void) {

}

void Opt::process(int argc, char* argv[]) {
	for(int i = 0; i < argc; i++) {
		argumentsInString.push_back(std::string(argv[i]));
	}

	std::map<std::string, Option*>::iterator iter;
	// TODO: map
	for(iter = this->argumentMap.begin(); iter != this->argumentMap.end(); iter++) {
		std::vector<std::string>::iterator argIter = std::find(argumentsInString.begin(), argumentsInString.end(), iter->first);
		if(argIter != argumentsInString.end()) {
			try{
				processValueByType(iter, argIter);
			} catch(StandardError* exception) {
				std::cerr << exception->message << std::endl;
				printOptions();
			}
		}
	}
}

void Opt::printOptions() {
	std::map<std::string, Option*>::iterator iter;

	std::cerr << "Choices are:" << std::endl;
	for(iter = this->argumentMap.begin(); iter != this->argumentMap.end(); iter++) {
		std::string option = iter->first;
		std::string description = iter->second->description;

		// display the current option
		std::cerr << option << " : " << description;
		std::cerr << " ";
		std::cerr << "[" << iter->second->getTypeString() << "]";
		std::cerr << " ";
		std::cerr << iter->second->stringValue;
		std::cerr << std::endl;
	}
}

void Opt::processValueByType(std::map<std::string, Option*>::iterator iter, std::vector<std::string>::iterator argIter) {
	if(iter->second->getType() == TypeGeneric) {
		throw new StandardError("FATAL ERROR 1");
	} else if(iter->second->getType() == TypeSwitch) {
		Option* switchOption = this->argumentMap.find(iter->first)->second;
		static_cast<SwitchOption*>(switchOption)->value = true;
	} else if(iter->second->getType() == TypeInteger) {
		Option* integerOption = this->argumentMap.find(iter->first)->second;

		// take the next option for the value of the argument
		argIter++;
		if(argIter == argumentsInString.end()) {
			throw new StandardError("Expected Arguments to Option " + iter->second->option);
		}

		std::istringstream iss(argIter->c_str());
		int value;
		iss >> value;
		if(!iss.eof()) {
			throw new StandardError("Invalid Arguments to Option " + iter->second->option);
		}

		static_cast<IntegerOption*>(integerOption)->value = value;
	} else if(iter->second->getType() == TypeDouble) {
		Option* doubleOption = this->argumentMap.find(iter->first)->second;

		// take the next argument
		argIter++;
		if(argIter == argumentsInString.end()) {
			throw new StandardError("Expected Arguments to Option " + iter->second->option);
		}

		std::istringstream iss(argIter->c_str());
		double value;
		iss >> value;
		if(!iss.eof()) {
			throw new StandardError("Invalid Arguments to Option " + iter->second->option);
		}
		static_cast<DoubleOption*>(doubleOption)->value = value;
	} else if(iter->second->getType() == TypeString) {
		Option* stringOption = this->argumentMap.find(iter->first)->second;

		// take the next argument
		argIter++;
		if(argIter == argumentsInString.end()) {
			throw new StandardError("Expected Arguments to Option " + iter->second->option);
		}

		std::string value = *argIter;
		static_cast<StringOption*>(stringOption)->value = value;
	} else if(iter->second->getType() == TypeBoolean) {
		Option* boolOption = this->argumentMap.find(iter->first)->second;

		// take the next argument
		argIter++;
		if(argIter == argumentsInString.end()) {
			throw new StandardError("Expected Arguments to Option " + iter->second->option);
		}

		int value = atoi(argIter->c_str());
		if(value != 1 && value != 0) {
			throw new StandardError("Invalid Arguments to Option " + iter->second->option);
		}
		static_cast<BoolOption*>(boolOption)->value = value;
	} else {
		throw new StandardError("FATAL ERROR 2");
	}
}

void Opt::add_switch(std::string option, std::string description) {
	SwitchOption* switchOption = new SwitchOption;
	switchOption->option = option;
	switchOption->description = description;
	switchOption->value = false;
	switchOption->stringValue = "";
	this->argumentMap.insert(std::pair<std::string, Option*>(option, switchOption));
}

void Opt::add_bool(std::string option, std::string description, bool value) {
	BoolOption* boolOption = new BoolOption;
	boolOption->option = option;
	boolOption->description = description;
	boolOption->value = value;
	
	std::stringstream ss;
	ss << value;
	boolOption->stringValue = ss.str();
	this->argumentMap.insert(std::pair<std::string, Option*>(option, boolOption));
}

void Opt::add_int(std::string option, std::string description, int value) {
	IntegerOption* integerOption = new IntegerOption;
	integerOption->option = option;
	integerOption->description = description;
	integerOption->value = value;

	std::stringstream ss;
	ss << value;
	integerOption->stringValue = ss.str();
	this->argumentMap.insert(std::pair<std::string, Option*>(option, integerOption));
}

void Opt::add_double(std::string option, std::string description, double value) {
	DoubleOption* doubleOption = new DoubleOption;
	doubleOption->option = option;
	doubleOption->description = description;
	doubleOption->value = value;

	std::stringstream ss;
	ss << value;
	doubleOption->stringValue = ss.str();
	this->argumentMap.insert(std::pair<std::string, Option*>(option, doubleOption));
}

void Opt::add_string(std::string option, std::string description, std::string value) {
	StringOption* strOption = new StringOption;
	strOption->option = option;
	strOption->description = description;
	strOption->value = value;
	strOption->stringValue = value;
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
	Option* boolOption = this->argumentMap.find(option)->second;
	return static_cast<BoolOption*>(boolOption)->value;
}

double Opt::get_double(std::string option) {
	Option* doubleOption = this->argumentMap.find(option)->second;
	return static_cast<DoubleOption*>(doubleOption)->value;
}

std::string Opt::get_string(std::string option) {
	Option* stringOption = this->argumentMap.find(option)->second;
	return static_cast<StringOption*>(stringOption)->value;
}