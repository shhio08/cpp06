#include "ScalarConverter.hpp"

int main(void)
{

    std::cout << "Testing Char: 'a'" << std::endl;
    ScalarConverter::convert("'a'");

    std::cout << "\nTesting Int: 42" << std::endl;
    ScalarConverter::convert("42");

    std::cout << "\nTesting Float: 42.42f" << std::endl;
    ScalarConverter::convert("42.42f");

    std::cout << "\nTesting Double: 42.42" << std::endl;
    ScalarConverter::convert("42.42");

    std::cout << "\nTesting Special Float: nanf" << std::endl;
    ScalarConverter::convert("nanf");

    std::cout << "\nTesting Special Double: nan" << std::endl;
    ScalarConverter::convert("nan");

    std::cout << "\nTesting Float: +inff" << std::endl;
    ScalarConverter::convert("+inff");

    std::cout << "\nTesting Double: -inf" << std::endl;
    ScalarConverter::convert("-inf");

    std::cout << "\nTesting Invalid Char: 'ab'" << std::endl;
    ScalarConverter::convert("'ab'");

    std::cout << "\nTesting Invalid Int: 42.42" << std::endl;
    ScalarConverter::convert("42.42");

    std::cout << "\nTesting Invalid Float: 42.42" << std::endl;
    ScalarConverter::convert("42.42");

    std::cout << "\nTesting Invalid Double: 42.42.42" << std::endl;
    ScalarConverter::convert("42.42.42");

	//pdfのテスト
	std::cout << std::endl << std::endl;
	std::cout << "Test with '0':" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	std::cout << "Test with 'nan':" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	std::cout << "Test with '42.0f':" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	std::cout << "Test with '42.0':" << std::endl;
	ScalarConverter::convert("42.0");



    return 0;
}