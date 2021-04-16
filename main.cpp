#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>


using std::cout;
using std::endl;


class ROT13
{
public:
	ROT13();
	~ROT13();

	std::string process(const std::string& string);
	
protected:
	std::map<std::string, std::string> charmap;
};


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


ROT13::~ROT13()
{
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


int main(int argc, char* argv[])
{
	std::string m_string("This is a string to encode");

	if (argc == 2)
		m_string = argc[1];

	ROT13 r13;

	std::string result = r13.process(m_string);

	cout << "Result: " << result << endl;
	cout << "Original: " << r13.process(result) << endl;

	cout << "Hello World" << endl;

	return 0;
}
