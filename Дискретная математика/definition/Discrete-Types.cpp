#include <set>

module Discrete:Types;



discrete::BasicTypes::Number::Number(const std::string& name, const std::string& value)
{

	this->_name = name;
	this->SetValue(value);
}

void discrete::BasicTypes::Number::SetValue(const std::string& value)
{
	if (!prs::isNumber(value))
		return std::cout << '\n' << value << " is not a valid value for " << \
			this->_name << std::endl, void();

	this->value = atof(value.c_str());
}

void discrete::BasicTypes::Number::PrintValue(std::ostream& os)
{
	os << this->_name << " = " << this->value;
}

discrete::BasicTypes::String::String(const std::string& name, const std::string& value)
{
	this->_name = name;
	this->SetValue(value);
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
	this->_name = name;
	this->SetValue(value);
}

void discrete::BasicTypes::Array::SetValue(const std::string& value)
{
}

void discrete::BasicTypes::Array::PrintValue(std::ostream& os)
{
}

discrete::Set::Set(const std::string& name, const std::string& value)
{
	this->_name = name;
	this->SetValue(value);
}

void discrete::Set::SetValue(const std::string& value)
{
}

void discrete::Set::PrintValue(std::ostream& os)
{

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
