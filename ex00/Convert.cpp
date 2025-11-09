/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:46:36 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/09 19:56:51 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter(){};

//Compiler already knows this function is static from it's header
void	ScalarConverter::convert(const std::string& input)
{
	//std::cout <<"length: " << input.length() <<  std::endl;
	
	if(input.length() == 3 && input[0] == '\'' && input[2] == '\'')
	{
		isCharLiteral(input);
		return;
	}

	if(input == "nan" || input == "nanf"
		|| input == "+inf" || input == "-inf"
		|| input == "inf"  || input == "+inff"
		|| input == "-inff" || input == "inff")
	{
		isSpecialLiteral(input);
		return;
	}
	bool isInt = true;
	size_t i = 0;
	
	if (!input.empty() && (input[0] == '+' || input[0] == '-'))
		i = 1;

	if (i >= input.length())
		isInt = false;
	
	for (; i < input.length() && isInt; i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			isInt = false;
	}
	
	if (isInt)
	{
		isIntLiteral(input);
	}
	
}


void	ScalarConverter::isCharLiteral(const std::string& input)
{
	std::cout << "char: " << input << std::endl;
	std::cout << "int: " << static_cast<int>(input[1]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[1]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[1]) << ".0" << std::endl;
	
}
void		ScalarConverter::isIntLiteral(const std::string& input)
{
	std::cout << "char: " << "'" << static_cast<char>(atoi(input.c_str())) << "'" << std::endl;
	std::cout << "int: " << atoi(input.c_str()) << std::endl;
	std::cout << "float: " << atoi(input.c_str()) << ".0f" << std::endl;
	std::cout << "double: " << atoi(input.c_str()) << ".0" << std::endl;
}

void	ScalarConverter::isFloatLiteral(const std::string& input)
{
	std::cout << "char: " << "'" << static_cast<char>(atoi(input.c_str())) << "'" << std::endl;
	std::cout << "int: " << atoi(input.c_str()) << std::endl;
	std::cout << "float: " << atoi(input.c_str()) << ".0f" << std::endl;
	std::cout << "double: " << atoi(input.c_str()) << ".0" << std::endl;
}
void		ScalarConverter::isSpecialLiteral(const std::string& input)
{
	if(input == "nan")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if(input == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if(input == "+inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if(input == "-inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if(input == "inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if(input == "+inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else if(input == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else if(input == "inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
}