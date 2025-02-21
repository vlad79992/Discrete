export module Discrete:Interpreter;

import :ParseExpression;

import "set";
import "string";
import "iostream";

std::set<std::string> type_names, function_names, variable_names;

export namespace cli
{
	std::string ReadLine(std::istream& is = std::cin);
}
