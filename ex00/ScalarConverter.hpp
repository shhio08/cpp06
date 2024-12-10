#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void convertChar(const std::string &input);
	static void convertInt(const std::string &input);
	static void convertFloat(const std::string &input);
	static void convertDouble(const std::string &input);

	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isSpecialFloat(const std::string &input);
	static bool isSpecialDouble(const std::string &input);

public:
	static void convert(const std::string &input);
};