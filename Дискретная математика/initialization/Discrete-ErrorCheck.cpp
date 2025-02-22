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
	// ���� ����������� ������, �� ������������ 1, � �������� ������ ���������� 1
}

void bracketsError(std::pair<char, int> bracket, std::ostream& os);

bool er::checkBrackets(const std::string& expression, std::ostream& os)
{
	// ( ); [ ]; { }; < >
	std::deque<std::pair<char, int>> brackets; // type, pos
	for (int i = 0; i < expression.size(); ++i)
	{
		char c = expression[i];
		if (!isBracket(c))
			continue;
		// ����������� ������
		if (isOpeningBracket(c))
		{
			brackets.push_back({ c, i });
			continue;
		}
		// ����������� ������
		if (brackets.empty()) // ��� ������� ������
			return bracketsError({c, i}, os), false;
		if (c != oppositeBracket(brackets.back().first)) // ���������� ������ - �� ���������� �����������
			return bracketsError(brackets.back(), os), false;
		else
			brackets.pop_back();
	}

	if (!brackets.empty())
		return bracketsError(brackets.back(), os), false;

	return true;
}

bool er::checkNames(const std::vector<std::string>& tokens, std::ostream& os)
{
	for (const auto tk : tokens)
	{

	}
	return true;
}

void bracketsError(std::pair<char, int> bracket, std::ostream& os)
{
	for (int i = 0; i < bracket.second; ++i) std::cout << ' '; // �������� ������ �� ������ �������
	
	std::cout << "^\n";

	std::cout << "No " << ((isOpeningBracket(bracket.first)) ? "closing" : "opening") << " bracket '" \
		<< oppositeBracket(bracket.first) << '\'' << std::endl;
}