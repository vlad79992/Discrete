#include <set>

module Discrete:Types;
import :ParseExpression;


discrete::BasicTypes::Number::Number(const std::string& name, const std::string& value)
{
	this->type = "Number";
	this->_name = name;
	this->SetValue(value);
}

std::vector<std::string> discrete::BasicTypes::Number::toStringVec()
{
	return { this->str_value };
}

void discrete::BasicTypes::Number::SetValue(const std::string& value)
{
	if (!prs::isNumber(value))
		return std::cout << '\n' << value << " is not a valid value for " << \
			this->_name << std::endl, void();

	this->value = atof(value.c_str());
	this->str_value = value;
}

void discrete::BasicTypes::Number::PrintValue(std::ostream& os)
{
	os << this->_name << " = " << this->value;
}

discrete::BasicTypes::String::String(const std::string& name, const std::string& value)
{
	this->type = "String";
	this->_name = name;
	this->SetValue(value);
}

std::vector<std::string> discrete::BasicTypes::String::toStringVec()
{
	return { this->value };
}

void discrete::BasicTypes::String::SetValue(const std::string& value)
{
	this->value = value;
}

void discrete::BasicTypes::String::PrintValue(std::ostream& os)
{
	os << this->_name << " = " << this->value;
}

discrete::BasicTypes::Array::Array(const std::string& name, const std::string& value)
{
	this->type = "Array";
	this->_name = name;
	this->SetValue(value);
}

std::vector<std::string> discrete::BasicTypes::Array::toStringVec()
{
	std::vector<std::string> string_vec;
	string_vec.push_back(this->opening_bracket);

	for (auto elem : this->value)
	{
		for (const auto& elem_string : elem.toStringVec())
		{
			string_vec.push_back(elem_string);
		}
		string_vec.push_back(",");
	}

	string_vec.pop_back(); // удаляет последнюю запятую (надо ли ставить запятые?)
	string_vec.push_back(this->closing_bracket);
	return string_vec;
}

void discrete::BasicTypes::Array::SetValue(const std::string& value)
{
}

void discrete::BasicTypes::Array::PrintValue(std::ostream& os)
{
}

discrete::Set::Set(const std::string& name, const std::string& value)
{
	this->type = "Set";
	this->_name = name;
	this->SetValue(value);
}

std::vector<std::string> discrete::Set::toStringVec()
{
	return std::vector<std::string>();
}

void discrete::Set::SetValue(const std::string& value)
{
}

void discrete::Set::PrintValue(std::ostream& os)
{

}

discrete::BasicTypes::Operator::Operator(std::string type)
{
	this->type = "Operator";
	this->value = type;
}

void discrete::Set::Reverse()
{
	for (int i = 0; i < this->value.size(); i++) 
	{
		std::reverse(this->value[i].begin(), this->value[i].end());
	}
}

std::vector<std::vector<std::string>> discrete::Set::Composition(const discrete::Set& other)
{
	// композиция
	std::vector<std::vector<std::string>> composition;
	std::set<std::vector<std::string>> used;
	for (const auto& str1 : this->value) 
	{
		for (const auto& str2 : other.value) 
		{
			if (!used.contains({ str1[0], str2[1]}))
			{
				used.insert({ str1[0], str2[1]});
				composition.push_back({ str1[0], str2[1]});
			}
		}
	}

	return composition;
}
