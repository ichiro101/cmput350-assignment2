#pragma once

#include <string>

enum DataType {
	TypeGeneric,
	TypeInteger,
	TypeBoolean,
	TypeSwitch,
	TypeDouble,
	TypeString
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

class DoubleOption : public Option
{
public:
	double value;

	DataType getType() {
		return TypeDouble;
	}
};

class StringOption : public Option
{
public:
	std::string value;

	DataType getType() {
		return TypeString;
	}
};