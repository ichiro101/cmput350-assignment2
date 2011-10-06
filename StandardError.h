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