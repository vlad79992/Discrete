#include <string>
#include <iostream>

import Discrete;

int main()
{
	while (true)
	{
		std::string str;
		str = cli::ReadLine();
		for (const auto& x : prs::convertParsed(prs::parseExpression(str)))
		{
			std::cout << "\"" << x << "\" ";
		}
		std::cout << " - is " << (!(prs::isSet(prs::parseExpression(str))) ? ("not") : ("")) << " a set";
		std::cout << std::endl;
		//std::cout << prs::isSet(str) << std::endl;
		//er::checkBrackets(str);
	}
}