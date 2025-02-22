export module Discrete:ParseExpression;

import "set";
import "string";
import "vector";

export namespace prs
{
	std::set<std::string> getNames(std::string expression);
	std::vector<std::string> parseExpression(const std::string& expression);
	bool isNumber(const std::string& value);
	bool isName(const std::string& value);
	bool isSet(const std::string& value);
	std::string deleteWhitespace(const std::string& str);
}