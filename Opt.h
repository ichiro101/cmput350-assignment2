#pragma once

#include <iostream>

class Opt
{
	public:
		Opt(void);
		~Opt(void);

		void add_switch(std::string option, std::string description);
		void add_bool(std::string option, std::string description, bool value);
		void add_int(std::string option, std::string description, int value);
		void add_double(std::string option, std::string description, double value);
		void add_string(std::string option, std::string description, std::string value);

		bool get_swtich(std::string option);
		int get_int(std::string option);
};
