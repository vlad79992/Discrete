#include <sstream>

module Discrete:ParseExpression;

std::set<std::string> prs::getNames(std::string expression)
{
	//��� �� ��������
	std::set<std::string> names;
	return names;
}

inline bool is_operator(const char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '^' || c == '(' || c == ')' || c == '='
		|| c == '{' || c == '}' || c == ',';
}

std::vector<std::string> prs::parseExpression(const std::string& expression)
{
	//��������� ������ �� ���������, ��������� �� �����, ���, ����������
	std::vector<std::string> tokens;

	std::string cur_token;

	for (char c : expression)
	{
		if (std::isspace(c) || is_operator(c))
		{
			if (!cur_token.empty())
			{
				tokens.push_back(prs::deleteWhitespace(cur_token));
				cur_token = "";
			}
			if (is_operator(c))
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

bool isValidSubset(const std::string& subset);

bool prs::isSet(const std::string& value)
{
	//��������� ������������ ��������� ���������
	//{(x, y), (u, v)}
	//{}
	bool completed = false;
	std::stringstream sstr{ value };
	char cur;
	std::string subset;
	
	sstr >> cur;
	if (cur != '{')
		return false;

	sstr >> cur; // ������ ������ ������ ���������
	subset.push_back(cur);

	while (sstr.get(cur))
	{
		if (cur != sstr.eof() && completed)
			return false;

		if (cur == '}')
		{
			if (subset.empty())
				completed = true;
			else
				return false;

			continue;
		}
		if (!std::isspace(cur))
			subset.push_back(cur);
		
		if (cur == ')')
		{
			if (isValidSubset(subset))
				subset = "";
			else
				return false;
		}
	}

	return completed;
}

std::string prs::deleteWhitespace(const std::string& str)
{
	//������� ������� � ������ � ����� ������
	int first_symbol, last_symbol;
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
	return str.substr(first_symbol, last_symbol - first_symbol + 1);
}

bool isValidElement(const std::string& elem);

bool isValidSubset(const std::string& subset)
{
	//��������� ������������ ��������� ������������
	//(x, y, z)
	std::string elem;

	if (subset.empty())
		return false;

	if (subset[0] != '(')
		return false;

	if (subset.back() != ')')
		return false;

	for (int i = 1; i < subset.size() - 1; ++i)
	{
		if (subset[i] != ',')
			elem.push_back(subset[i]);
		else
		{
			if (isValidElement(elem))
				elem = "";
			else
				return false;
		}
	}
}

bool isValidElement(const std::string& elem)
{
	//��������� ������������ ��������� �������� ���������
	//	(�� ������ ���� ���� ������, ���� ���������� ������)
	return prs::isName(prs::deleteWhitespace(elem)) || \
		prs::isNumber(prs::deleteWhitespace(elem));
}
