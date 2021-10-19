#include <iostream>

#include "ROT13.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	std::string m_string("This is a string to encode");

	if (argc == 2)
		m_string = argv[1];
		
	ROT13 r13;

	std::string result = r13.process(m_string);

	cout << "Result: " << result << endl;
	cout << "Original: " << r13.process(result) << endl;

	return 0;
}

