/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:12:44 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/10 17:16:05 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void runTests()
{
	std::cout << "\n=== CHAR LITERALS ===" << std::endl;
	std::cout << "\nTest: 'a'" << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << "\nTest: '*'" << std::endl;
	ScalarConverter::convert("'*'");
	std::cout << "\nTest: '0'" << std::endl;
	ScalarConverter::convert("'0'");
	
	std::cout << "\n=== INT LITERALS ===" << std::endl;
	std::cout << "\nTest: 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "\nTest: 42" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "\nTest: -42" << std::endl;
	ScalarConverter::convert("-42");
	std::cout << "\nTest: 127" << std::endl;
	ScalarConverter::convert("127");
	std::cout << "\nTest: 128" << std::endl;
	ScalarConverter::convert("128");
	
	std::cout << "\n=== FLOAT LITERALS ===" << std::endl;
	std::cout << "\nTest: 0.0f" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "\nTest: 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "\nTest: -4.2f" << std::endl;
	ScalarConverter::convert("-4.2f");
	std::cout << "\nTest: 4.2f" << std::endl;
	ScalarConverter::convert("4.2f");
	
	std::cout << "\n=== DOUBLE LITERALS ===" << std::endl;
	std::cout << "\nTest: 0.0" << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << "\nTest: 42.0" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << "\nTest: -4.2" << std::endl;
	ScalarConverter::convert("-4.2");
	std::cout << "\nTest: 4.2" << std::endl;
	ScalarConverter::convert("4.2");
	
	std::cout << "\n=== SPECIAL VALUES ===" << std::endl;
	std::cout << "\nTest: nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\nTest: nanf" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "\nTest: +inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "\nTest: -inf" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "\nTest: inff" << std::endl;
	ScalarConverter::convert("inff");
	std::cout << "\nTest: +inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "\nTest: -inff" << std::endl;
	ScalarConverter::convert("-inff");
	
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else if (argc == 1)
	{
		runTests();
	}
	else
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		std::cout << "   or: ./convert (to run test suite)" << std::endl;
	}
	return (0);
}