#include <string>
#include <iostream>

import Discrete;

int main()
{
	while (true)
	{
		std::string str;
		str = cli::ReadLine();
		std::cout << str << std::endl;
		//std::cout << prs::isSet(str) << std::endl;
		//er::checkBrackets(str);
	}
}