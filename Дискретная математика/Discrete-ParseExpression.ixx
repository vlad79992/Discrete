export module Discrete:ParseExpression;

import "set";
import "string";
import "vector";

export namespace prs
{
	std::vector<std::string> parseExpression(const std::string& expression);
	bool isNumber(const std::string& value);
	bool isName(const std::string& value);
	bool isSet(const std::vector<std::string>& tokens);
	std::string deleteWhitespace(const std::string& str);
}