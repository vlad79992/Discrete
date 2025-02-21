#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

module Discrete:ErrorCheck;


inline bool isBracket(const char c)
{
	return (c == '(' || c == '[' || c == '{' || c == '<' || c == ')' || c == ']' || c == '}' || c == '>');
}

inline bool isOpeningBracket(const char c)
{
	return (c == '(' || c == '[' || c == '{' || c == '<');
}

inline char oppositeBracket(const char bracket)
{
	const std::vector<char> brackets = { '(', ')', '[', ']', '{', '}', '<', '>' };
	return *(std::find(brackets.begin(), brackets.end(), bracket) + (2 * isOpeningBracket(bracket)) - 1);
	// если открывающая скобка, то прибавляется 1, в обратном случае отнимается 1
}

void bracketsError(std::pair<char, int> bracket);

bool er::checkBrackets(const std::string& expression)
{
	// ( ); [ ]; { }; < >
	std::deque<std::pair<char, int>> brackets; // type, pos
	for (int i = 0; i < expression.size(); ++i)
	{
		char c = expression[i];
		if (!isBracket(c))
			continue;
		// открывающие скобки
		if (isOpeningBracket(c))
		{
			brackets.push_back({ c, i });
			continue;
		}
		// закрывающие скобки
		if (brackets.empty()) // нет никаких скобок
			return bracketsError({c, i}), false;
		if (c != oppositeBracket(brackets.back().first)) // предыдущая скобка - не правильная открывающая
			return bracketsError(brackets.back()), false;
		else
			brackets.pop_back();
	}

	if (!brackets.empty())
		return bracketsError(brackets.back()), false;

	return true;
}

void bracketsError(std::pair<char, int> bracket)
{
	for (int i = 0; i < bracket.second; ++i) std::cout << ' '; // помещаем курсор на нужную позицию
	
	std::cout << "^\n";

	std::cout << "No " << ((isOpeningBracket(bracket.first)) ? "closing" : "opening") << " bracket '" \
		<< oppositeBracket(bracket.first) << '\'' << std::endl;
}