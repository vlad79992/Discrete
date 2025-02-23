#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

module Discrete:ErrorCheck;


void bracketsError(std::pair<char, int> bracket, std::ostream& os);

bool er::checkBrackets(const std::string& expression, std::ostream& os)
{
	// ( ); [ ]; { }
	std::deque<std::pair<char, int>> brackets; // type, pos
	for (int i = 0; i < expression.size(); ++i)
	{
		char c = expression[i];
		if (!is_bracket(c))
			continue;
		// ����������� ������
		if (is_opening_bracket(c))
		{
			brackets.push_back({ c, i });
			continue;
		}
		// ����������� ������
		if (brackets.empty()) // ��� ������� ������
			return bracketsError({c, i}, os), false;
		if (c != opposite_bracket(brackets.back().first)) // ���������� ������ - �� ���������� �����������
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

	std::cout << "No " << ((is_opening_bracket(bracket.first)) ? "closing" : "opening") << " bracket '" \
		<< opposite_bracket(bracket.first) << '\'' << std::endl;
}