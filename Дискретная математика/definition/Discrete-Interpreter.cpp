#include <algorithm>

module Discrete:Interpreter;

std::string cli::ReadLine(std::istream& is)
{
	//Позволяет делать перенос строки с помощью обратной наклонной черты
	// qwerty == qwe\
					rty

	std::string buf, line;

	std::getline(is, buf);
	buf = prs::deleteWhitespace(buf);

	line.reserve(buf.size());

	for (int i = 0; i < buf.size(); ++i)
	{
		if (std::isspace(buf[i]) && line.empty())
			continue;

		if (buf[i] != '\\')
			line.push_back(buf[i]);
	}

	line.shrink_to_fit();
	if (buf.back() == '\\')
		line.append(cli::ReadLine(is));
	return line;
}