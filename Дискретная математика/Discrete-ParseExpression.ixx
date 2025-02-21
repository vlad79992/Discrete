export module Discrete:ParseExpression;

import "set";
import "string";


export namespace prs
{
	std::set<std::string> getNames(std::string expression);
	bool isNumber(const std::string& value);
	bool isName(const std::string& value);
	bool isSet(const std::string& value);
}