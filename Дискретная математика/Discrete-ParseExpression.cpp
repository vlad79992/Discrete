#include <sstream>

module Discrete:ParseExpression;

std::set<std::string> prs::getNames(std::string expression)
{
	//ещё не придумал
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
	//разделяет строку на подстроки, состоящие из чисел, имён, операторов
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
	//проверяет правильность написания числа
	if (value.empty())
		return false;

	bool have_point = false;

	for (const char c : value)
	{
		if (!isdigit(c) && c != '.')
			return false; // не число и не точка
		if (c == '.')
		{
			if (have_point)
				return false; // больше одной точки
			else
				have_point = 1;
		}
	}

	return true;
}

bool prs::isName(const std::string& value)
{
	//проверяет правильность написания имени
	// имя должно начинаться только с буквы или подчеркивания,
	// содержать буквы, цифры и подчеркивания
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
	//проверяет правильность написания множества
	//{(x, y), (u, v)}
	//{}
	bool completed = false;
	std::stringstream sstr{ value };
	char cur;
	std::string subset;
	
	sstr >> cur;
	if (cur != '{')
		return false;

	sstr >> cur; // первый символ внутри множества
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
	//удаляет пробелы в начале и конце строки
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
	//проверяет правильность написания подмножества
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
	//проверяет правильность написания элемента множества
	//	(он должен быть либо числом, либо правильным именем)
	return prs::isName(prs::deleteWhitespace(elem)) || \
		prs::isNumber(prs::deleteWhitespace(elem));
}
