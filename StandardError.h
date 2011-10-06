#pragma once

#include <string>

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