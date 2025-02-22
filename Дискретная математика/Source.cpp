#include <string>
#include <iostream>

import Discrete;

int main()
{
	while (true)
	{
		std::string str;
		str = cli::ReadLine();
		for (const auto& x : prs::parseExpression(str))
		{
			std::cout << "\"" << x << "\" ";
		}
		std::cout << std::endl;
		//std::cout << str << std::endl;
		//std::cout << prs::isSet(str) << std::endl;
		//er::checkBrackets(str);
	}
}