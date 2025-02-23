export module Discrete:ParseExpression;

import :Types;

import "set";
import "string";
import "vector";
import "map";

export inline bool is_operator(const char c);
export inline bool is_bracket(const char c);
export inline bool is_opening_bracket(const char c);
export inline char opposite_bracket(const char bracket);

export namespace prs
{
	std::vector<std::string> parseExpression(const std::string& expression);
	std::vector<std::string> convertParsed(const std::vector<std::string>& expression);
	std::vector<std::string> SolveExpression(const std::vector<std::string>& expression);
	bool isNumber(const std::string& value);
	bool isName(const std::string& value);
	bool isSet(const std::vector<std::string>& tokens);
	std::string deleteWhitespace(const std::string& str);
}