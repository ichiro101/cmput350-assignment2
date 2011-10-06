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
	std::string stringValue;

	virtual DataType getType() {
		return TypeGeneric;
	}

	virtual std::string getTypeString() {
		return "generic";
	}
};

class SwitchOption: public Option
{
public:
	bool value;

	DataType getType() {
		return TypeSwitch;
	}

	std::string getTypeString() {
		return "switch";
	}
};

class BoolOption : public Option
{
public:
	bool value;

	DataType getType() {
		return TypeBoolean;
	}

	std::string getTypeString() {
		return "boolean";
	}
};

class IntegerOption : public Option
{
public:
	int value;

	DataType getType() {
		return TypeInteger;
	}

	std::string getTypeString() {
		return "integer";
	}
};

class DoubleOption : public Option
{
public:
	double value;

	DataType getType() {
		return TypeDouble;
	}

	std::string getTypeString() {
		return "double";
	}
};

class StringOption : public Option
{
public:
	std::string value;

	DataType getType() {
		return TypeString;
	}

	std::string getTypeString() {
		return "string";
	}
};