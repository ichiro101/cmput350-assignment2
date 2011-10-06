#pragma once

#include <string>

enum DataType {
	TypeGeneric,
	TypeInteger,
	TypeBoolean,
	TypeSwitch
};

class Option
{
public:
	std::string option;
	std::string description;

	virtual DataType getType() {
		return TypeGeneric;
	}
};

class SwitchOption: public Option
{
public:
	bool value;

	DataType getType() {
		return TypeSwitch;
	}
};

class BoolOption : public Option
{
public:
	bool value;

	DataType getType() {
		return TypeBoolean;
	}
};

class IntegerOption : public Option
{
public:
	int value;

	DataType getType() {
		return TypeInteger;
	}
};