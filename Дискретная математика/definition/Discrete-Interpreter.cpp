#include <algorithm>

module Discrete:Interpreter;

std::string cli::ReadLine(std::istream& is)
{
	//��������� ������ ������� ������ � ������� �������� ��������� �����
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

//std::vector<std::string> cli::ReplaceVariables(std::vector<std::string> expression, std::map<std::string, discrete::Type> variables)
//{
//	// �������� ����� ���������� �� �� ��������
//	return std::vector<std::string>();
//}
//
//std::vector<std::string> cli::SolveExpression(const std::vector<std::string>& expression)
//{
//	// �������� ��������� ��� �������������� ��������
//	// �.�. �������� 2 + 2 �� 4
//	// ���������� �������� ������� ��� ������ ��������� ������
//
//	std::vector<std::string> solved;
//	std::vector<std::string> brackets;
//	std::vector<std::string> 
//
//	return solved;
//}
