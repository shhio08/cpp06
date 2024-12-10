#include "ScalarConverter.hpp"

int main(void)
{
    // // intリテラルのテスト
    // std::cout << "Test with int literal '42':" << std::endl;
    // ScalarConverter::convert("42");

    // std::cout << std::endl;

    // std::cout << "Test with int literal '-42':" << std::endl;
    // ScalarConverter::convert("-42");

    // std::cout << std::endl;

    // // charリテラルのテスト
    // std::cout << "Test with char literal ''a'':" << std::endl;
    // ScalarConverter::convert("'a'");

    // std::cout << std::endl;

    // // 不正なcharリテラルのテスト（エラーメッセージが出ることを確認）
    // std::cout << "Test with invalid char literal 'a':" << std::endl;
    // ScalarConverter::convert("a");

    // std::cout << std::endl;

    // // floatリテラルのテスト
    // std::cout << "Test with float literal '42.42f':" << std::endl;
    // ScalarConverter::convert("42.42f");

    // std::cout << std::endl;

    // std::cout << "Test with float literal '-42.42f':" << std::endl;
    // ScalarConverter::convert("-42.42f");

    // std::cout << std::endl;

    // std::cout << "Test with float literal 'nanf':" << std::endl;
    // ScalarConverter::convert("nanf");

    // std::cout << std::endl;

    // std::cout << "Test with float literal '+inff':" << std::endl;
    // ScalarConverter::convert("+inff");

    // std::cout << std::endl;

    // std::cout << "Test with float literal '-inff':" << std::endl;
    // ScalarConverter::convert("-inff");

    // std::cout << std::endl;

    // // doubleリテラルのテスト
    // std::cout << "Test with double literal '42.42':" << std::endl;
    // ScalarConverter::convert("42.42");

    // std::cout << std::endl;

    // std::cout << "Test with double literal '-42.42':" << std::endl;
    // ScalarConverter::convert("-42.42");

    // std::cout << std::endl;

    // std::cout << "Test with double literal 'nan':" << std::endl;
    // ScalarConverter::convert("nan");

    // std::cout << std::endl;

    // std::cout << "Test with double literal '+inf':" << std::endl;
    // ScalarConverter::convert("+inf");

    // std::cout << std::endl;

    // std::cout << "Test with double literal '-inf':" << std::endl;
    // ScalarConverter::convert("-inf");

	//pdfのテスト
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