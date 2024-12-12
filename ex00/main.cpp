#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [literal]" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);

	//pdfのテスト
	// std::cout << std::endl << std::endl;
	// std::cout << "Test with '0':" << std::endl;
	// ScalarConverter::convert("0");
	// std::cout << std::endl;
	// std::cout << "Test with 'nan':" << std::endl;
	// ScalarConverter::convert("nan");
	// std::cout << std::endl;
	// std::cout << "Test with '42.0f':" << std::endl;
	// ScalarConverter::convert("42.0f");
	// std::cout << std::endl;
	// std::cout << "Test with '42.0':" << std::endl;
	// ScalarConverter::convert("123456789");



    return 0;
}