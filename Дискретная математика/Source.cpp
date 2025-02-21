#include <string>
#include <iostream>

import Discrete;

int main()
{
	while (true)
	{
		std::string str;
		std::getline(std::cin, str);
		std::cout << prs::isSet(str) << std::endl;
		//er::checkBrackets(str);
	}
}