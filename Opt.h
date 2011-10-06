#pragma once

#include "Option.h"

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
	void processValueByType(std::map<std::string, Option*>::iterator iter, std::vector<std::string>::iterator argIter);
	void printOptions();

	// ivars
	std::map<std::string, Option*> argumentMap;
	std::vector<std::string> argumentsInString;
};

class StandardError
{
public:
	StandardError() { }

	StandardError(std::string message) {
		this->message = message;
	}

	std::string message;
};

class InvalidArgumentError: public StandardError
{
public:
	InvalidArgumentError(std::string argument) {
		this->message = "Invalid argument to option " + argument;
	}
};