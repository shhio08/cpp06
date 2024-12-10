#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input)
{
	if (isSpecialFloat(input) || isSpecialDouble(input))
		convertSpecial(input);
	else
	if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else
		std::cout << "Impossible to convert the literal." << std::endl;
}

void ScalarConverter::convertChar(const std::string &input)
{
	if (input.length() != 3 || input[0] != '\'' || input[2] != '\'')
	{
		std::cout << "Invalid char literal." << std::endl;
		return;
	}
	char c = input[1];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
	try
	{
		int i = std::stoi(input);
		std::cout << "char: ";
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Impossible to convert to int." << std::endl;
	}
}

void ScalarConverter::convertFloat(const std::string &input)
{
	std::string floatStr = input.substr(0, input.length() - 1);
	std::stringstream ss(floatStr);
	float f;
	ss >> f;
		// 変換が失敗した場合
	if (ss.fail()) {
		std::cout << "Impossible to convert to float." << std::endl;
		return;
	}

	try
	{
		std::cout << "char: ";
		if (f < 32 || f > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: ";
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "Impossible" << std::endl;
		else
			std::cout << static_cast<int>(f) << std::endl;

		// 小数点以下が0の場合はf付きの0桁表示、それ以外は元の表示を維持
		if (f == static_cast<int>(f))
		{
			// 小数点以下が0なら整数形式で表示
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		}
		else
		{
			// 小数点以下がある場合は通常表示
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Impossible to convert to float." << std::endl;
	}
}

void ScalarConverter::convertDouble(const std::string &input)
{
	std::stringstream ss(input);
	double d;
	ss >> d;
	// 変換が失敗した場合
	if (ss.fail()) {
		std::cout << "Impossible to convert to double." << std::endl;
		return;
	}

	try
	{
		std::cout << "char: ";
		if (d < 32 || d > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: ";
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "Impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
		// 小数点以下が0の場合は.0をつけて表示
		if (d == static_cast<int>(d)) {
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		} else {
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cout << "Impossible to convert to double." << std::endl;
	}
}

void ScalarConverter::convertSpecial(const std::string &input)
{
	if (input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	if (input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &input)
{
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool ScalarConverter::isInt(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
	return input.find("f") != std::string::npos && input.length() > 1 && input[input.length() - 1] == 'f';
}

bool ScalarConverter::isDouble(const std::string &input)
{
	return input.find(".") != std::string::npos;
}

bool ScalarConverter::isSpecialFloat(const std::string &input)
{
	return input == "nanf" || input == "+inff" || input == "-inff";
}

bool ScalarConverter::isSpecialDouble(const std::string &input)
{
	return input == "nan" || input == "+inf" || input == "-inf";
}