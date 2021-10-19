#pragma once

#include <map>
#include <string>

class ROT13
{
 public:
 ROT13();

 std::string process(const std::string& string);
	
protected:
 std::map<std::string, std::string> charmap;
};

