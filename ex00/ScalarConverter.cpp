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

// typeはfloatだったら1, doubleだったら2
static bool isNumWithZeros(const std::string &input, int type)
{
	std::string::size_type dot_pos = input.find('.');
	if (dot_pos == std::string::npos)
		return false;

	std::string::size_type i = dot_pos + 1;
	while (i < input.length() && input[i] == '0')
		i++;
	if (type == 1)
	{
		if (i == input.length() - 1 || input[i] == 'f')
			return true;
	}
	else if (type == 2)
	{
		if (i == input.length())
			return true;
	}
	return false;
}

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
	char c = input[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
	try
	{
		std::stringstream ss(input);
		int i;
		ss >> i;
		// 変換が失敗した場合
		if (ss.fail()) {
			std::cout << "Impossible to convert to int." << std::endl;
			return;
		}
		std::cout << "char: ";
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
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

		if (isNumWithZeros(input, 1))
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		}
		else
		{
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

		if (isNumWithZeros(input, 2))
		{
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
		else
		{
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
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inff" || input == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inff" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &input)
{
	return input.length() == 1 && !isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string &input)
{
	if (input.empty())
		return false;
	// 符号の確認
	size_t startIndex = 0;
	if (input[0] == '-' || input[0] == '+')
	{
		if (input.length() == 1)
			return false;
		startIndex = 1;
	}
	// 数値の確認
	for (size_t i = startIndex; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	// 範囲の確認
	try
	{
		std::stringstream ss(input);
		int i;
		ss >> i;
		if (ss.fail())
			return false;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty() || input.back() != 'f')
		return false;

	// fを除いた文字列を取得
	std::string floatStr = input.substr(0, input.length() - 1);

	// 符号の確認
	size_t startIndex = 0;
	if (floatStr[0] == '-' || floatStr[0] == '+')
	{
		if (floatStr.length() == 1)
			return false;
		startIndex = 1;
	}

	// 数値の確認
	bool hasDigit = false;
	bool hasDot = false;
	bool hasExponent = false;

	while (startIndex < floatStr.length())
	{
		char c = floatStr[startIndex];
		if  (isdigit(c))
			hasDigit = true;
		else if (c == '.' && !hasDot && !hasExponent)
			hasDot =true;
		else if ((c == 'e' || c == 'E') && !hasExponent && hasDigit)
		{
			hasExponent = true;
			hasDigit = false;
			if (startIndex + 1 < floatStr.length() && (floatStr[startIndex + 1] == '-' || floatStr[startIndex + 1] == '+'))
				startIndex++;
		}
		else
			return false;
		startIndex++;
	}
	return hasDigit;
}

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty())
		return false;

	std::string::const_iterator it = input.begin();

	// 符号の確認
	if (*it == '-' || *it == '+')
	{
		if (input.length() == 1)
			return false;
		++it;
	}

	// 数値の確認
	bool hasDigit = false;
	bool hasDot = false;

	for (; it != input.end(); it++)
	{
		if (isdigit(*it))
			hasDigit = true;
		else if (*it == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else
			return false;
	}

	// 一つの数字と小数点があればtrue
	return (hasDigit && hasDot);
}

bool ScalarConverter::isSpecialFloat(const std::string &input)
{
	return input == "nanf" || input == "+inff" || input == "-inff";
}

bool ScalarConverter::isSpecialDouble(const std::string &input)
{
	return input == "nan" || input == "+inf" || input == "-inf";
}

