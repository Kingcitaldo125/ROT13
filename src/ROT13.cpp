#include <sstream>
#include <vector>

#include "ROT13.hpp"


ROT13::ROT13()
{
	std::vector<std::string> chars;
	// fill the charmap, use a vector to store temporaries
	for (int i = 'A'; i < 'N'; ++i)
	{
		char item = static_cast<char>(i);
		char item_pair = static_cast<char>(i + 13);

		std::string item_str(1, item);
		std::string item_pair_str(1, item_pair);
		chars.push_back(item_str);

		charmap.insert(std::make_pair(item_str, item_pair_str));
	}

	int j = 0;
	for (int i = 'N'; i <= 'Z'; ++i)
	{
		char item = static_cast<char>(i);

		std::string item_str(1, item);
		std::string item_pair_str = chars[j];

		charmap.insert(std::make_pair(item_str, item_pair_str));
		++j;
	}

	// insert lowercase letters
	std::map<std::string, std::string>::iterator it;
	for (it = charmap.begin(); it != charmap.end(); ++it)
	{
		char first_char = static_cast<char>(it->first.at(0));
		char second_char = static_cast<char>(it->second.at(0));

		std::string first_converted(1, tolower(first_char));
		std::string second_converted(1, tolower(second_char));

		charmap.insert(std::make_pair(first_converted, second_converted));
	}

	// insert a space for space
	charmap.insert(std::make_pair(" "," "));
}


std::string ROT13::process(const std::string& string)
{
	std::stringstream ss;

	for (auto& i : string)
	{
		std::string x_str(1, i);
		ss << charmap[x_str];
	}

	return ss.str();
}

