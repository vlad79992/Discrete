#include <sstream>

module Discrete:ParseExpression;

inline bool is_operator(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '^' || c == '<' || c == '>' || c == '='
		|| c == '%' || c == '!' || c == '\\';
}

inline bool is_bracket(const char c)
{
	return c == '(' || c == ')'
		|| c == '{' || c == '}'
		|| c == '[' || c == ']';
}

inline bool is_opening_bracket(const char c)
{
	return (c == '(' || c == '[' || c == '{');
}

inline char opposite_bracket(const char bracket)
{
	const std::vector<char> brackets = { '(', ')', '[', ']', '{', '}' };
	return *(std::find(brackets.begin(), brackets.end(), bracket) + (2 * (int) is_opening_bracket(bracket)) - 1);
	// ���� ����������� ������, �� ������������ 1, � �������� ������ ���������� 1
}	

std::vector<std::string> prs::parseExpression(const std::string& expression)
{
	//��������� ������ �� ���������, ��������� �� �����, ���, ����������
	std::vector<std::string> tokens;

	std::string cur_token;

	for (char c : expression)
	{
		if (std::isspace(c) || is_operator(c) || is_bracket(c) || c == ',')
		{
			if (!cur_token.empty())
			{
				tokens.push_back(prs::deleteWhitespace(cur_token));
				cur_token = "";
			}
			if (is_operator(c) || is_bracket(c) || c == ',')
				tokens.push_back({ c });
		}
		else
		{
			cur_token.push_back(c);
		}
	}
	if (!cur_token.empty())
		tokens.push_back(prs::deleteWhitespace(cur_token));

	return tokens;
}

std::vector<std::string> prs::convertParsed(const std::vector<std::string>& expression)
{
	// ����������� ��� �������� ">" � "=" � ">=" � �.�.
	std::vector<std::string> converted;

	for (int i = 1; i < expression.size(); ++i)
	{
		if (expression[i] == "=" && is_operator(expression[i - 1][0]))
		{
			converted.back().append(expression[i]);
			continue;
		}
		converted.push_back(expression[i]);
	}

	return converted;
}

std::vector<std::string> prs::SolveExpression(const std::vector<std::string>& expression)
{
	std::vector<std::string> opened_brackets;


	while (true)
	{
		std::vector<std::string> in_brackets; // ������ ��� �������� ����������� ������
		int brackets_count = 0;
		bool found_bracket = false;

		for (const auto& str : expression)
		{
			if (is_bracket(str[0]))
			{
				found_bracket = true;
				if (!is_opening_bracket(str[0]))
				{
					brackets_count--;
					if (brackets_count != 0)
						in_brackets.push_back(str);
					else
					{
						for (const auto& solved_str : SolveExpression(in_brackets))
							opened_brackets.push_back(solved_str);
					}
				}
				else
				{
					if (brackets_count != 0)
						in_brackets.push_back(str);
					brackets_count++;
				}
			}
			else if (brackets_count != 0)
			{
				in_brackets.push_back(str);
			}
			else
			{
				opened_brackets.push_back(str);
			}
		}

		if (!found_bracket)
			break;
	}

	std::vector<std::string> solved_expression;

	// ������

	return solved_expression;
}

bool prs::isNumber(const std::string& value)
{
	//��������� ������������ ��������� �����
	if (value.empty())
		return false;

	bool have_point = false;

	for (const char c : value)
	{
		if (!isdigit(c) && c != '.')
			return false; // �� ����� � �� �����
		if (c == '.')
		{
			if (have_point)
				return false; // ������ ����� �����
			else
				have_point = 1;
		}
	}

	return true;
}

bool prs::isName(const std::string& value)
{
	//��������� ������������ ��������� �����
	// ��� ������ ���������� ������ � ����� ��� �������������,
	// ��������� �����, ����� � �������������
	if (value.empty())
		return false;

	if (isdigit(value[0]))
		return false;

	for (const char c : value)
	{
		if (!isalpha(c) && !isdigit(c) && c != '_')
			return false;
	}

	return true;
}

bool isValidSubset(const std::vector<std::string>& subset);

bool prs::isSet(const std::vector<std::string>& tokens)
{
	//��������� ������������ ��������� ���������
	//{(x, y), (u, v)}
	//{}
	std::vector<std::string> subset;
	
	if (tokens.empty() 
		|| tokens.front() != "{" || tokens.back() != "}")
		return false;

	for (int i = 1; i < tokens.size() - 1; ++i)
	{
		if (tokens[i] == "}")
		{
			// ����������� ������ �� ��������� ���������
			// �������� � ������� �������� �������� ��������� ��������, ��������� �� ��������
			// �������� ��� ���������� �������, �������� ������ ���������� ������ ��������� ��
			return false;
		}
		if (tokens[i] != ",")
			subset.push_back(tokens[i]);
		
		if (subset.empty())
		{
			if (tokens[i] == ",")
				continue;
			else
				// ����� �������������� ��� �������
				return false;
		}

		if (tokens[i] == ")")
		{
			isValidSubset(subset);
			subset.clear();
			continue;
		}

	}

	return true;
}

std::string prs::deleteWhitespace(const std::string& str)
{
	//������� ������� � ������ � ����� ������
	int first_symbol = -1, last_symbol = -1;
	for (int i = 0; i < str.size(); ++i)
		if (!std::isspace(str[i]))
		{
			first_symbol = i;
			break;
		}

	for (int i = str.size() - 1; i >= 0; --i)
		if (!std::isspace(str[i]))
		{
			last_symbol = i;
			break;
		}

	if (first_symbol == -1 && last_symbol == -1)
		// ������ ������
		return "";

	return str.substr(first_symbol, last_symbol - first_symbol + 1);
}

bool isValidElement(const std::string& elem);

bool isValidSubset(const std::vector<std::string>& subset)
{
	//��������� ������������ ��������� ������������
	//(x, y, z)
	bool has_value = false;

	if (subset.empty())
		return false;

	if (subset[0] != "(" || subset.back() != ")")
		return false;

	for (int i = 1; i < subset.size() - 1; ++i)
	{
		if (subset[i] != "," && has_value)
			// ��� �������� ������ ��� �������
			return false;
		if (subset[i] != "," && !isValidElement(subset[i]))
			// ������� �� �������� �������, ������, ��� ������
			return false;
		if (subset[i] == ",")
			has_value = false;
		else
			has_value = true;
	}
	return true;
}

bool isValidElement(const std::string& elem)
{
	//��������� ������������ ��������� �������� ���������
	//	(�� ������ ���� ���� ������, ���� ���������� ������)
	return prs::isName(prs::deleteWhitespace(elem)) || \
		prs::isNumber(prs::deleteWhitespace(elem));
}