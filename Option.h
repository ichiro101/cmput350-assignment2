#pragma once

#include <string>

class Option
{
public:
	Option(void);
	~Option(void);

	std::string option;
	std::string description;
};

class SwitchOption : public Option
{
public:
	bool value;
};