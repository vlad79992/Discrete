export module Discrete:Interpreter;

import :ParseExpression;
import :Types;

import "map";
import "string";
import "iostream";
import "vector";

export namespace cli
{
	std::string ReadLine(std::istream& is = std::cin);
}
