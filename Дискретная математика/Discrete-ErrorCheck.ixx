export module Discrete:ErrorCheck;

import "string";
import "vector";
import "iostream";

import :ParseExpression;

//error check
export namespace er
{
	bool checkBrackets(const std::string& str, std::ostream& os = std::cout);
	bool checkNames(const std::vector<std::string>& tokens, std::ostream& os = std::cout);
}