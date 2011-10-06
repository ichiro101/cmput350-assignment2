#pragma once

#include "Option.h"
#include "StandardError.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

class Opt
{
public:
	Opt(void);
	~Opt(void);

	void process(int argc, char* argv[]);

	void add_switch(std::string option, std::string description);
	void add_bool(std::string option, std::string description, bool value);
	void add_int(std::string option, std::string description, int value);
	void add_double(std::string option, std::string description, double value);
	void add_string(std::string option, std::string description, std::string value);

	bool get_switch(std::string option);
	bool get_bool(std::string option);
	double get_double(std::string option);
	std::string get_string(std::string option);
	int get_int(std::string option);

private:
	std::map<std::string, Option*> argumentMap;
	void processValueByType(std::map<std::string, Option*>::iterator iter, std::vector<std::string>::iterator argIter);

	std::vector<std::string> argumentsInString;
};
