

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
	prs::isSet(value);
	//this->value = prs::ParseSet
}

void discrete::Set::PrintValue(std::ostream& os)
{

}
