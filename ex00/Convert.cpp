/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:46:36 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/10 17:40:59 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#define GREEN "\033[0;32m"

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
	if (!input.empty())
	{
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
	if (input.find('.') != std::string::npos && 
	    !input.empty() && 
	    (input[input.length()-1] == 'f' || input[input.length()-1] == 'F'))
		{
			isFloatLiteral(input);
			return;
		}
	if (input.find('.') != std::string::npos)
		{
			isDoubleLiteral(input);
			return;
		}
	if (detectInt(input))
		{
			isIntLiteral(input);
			return;
		}
	}
}

bool	ScalarConverter::detectInt(const std::string& input)
{
	bool isInt = true;
	size_t i = 0;

	if(input[0] == '+' || input[0] == '-')
		i = 1;
	if(i >= input.length())
		isInt = false;
	for(; i < input.length() && isInt; i++)
	{
		if(!std::isdigit(static_cast<unsigned char>(input[i])))
			isInt = false;
	}
	return(isInt);
}


bool	ScalarConverter::detectFloat(const std::string& input)
{
	bool	isFloat = false;
	size_t 		  i = 0;

	for(; i < input.length(); i++)
	{
		if(input.find('.') && (input.find('f') || input.find('F')))
			isFloat = true;
	}
	return(isFloat);
}


bool	ScalarConverter::detectDouble(const std::string& input)
{
	bool	isDouble = false;
	size_t  i = 0;

	for(; i < input.length(); i++)
	{
		if(input.find('.'))
			isDouble = true;
	}
	return (isDouble);
}

void	ScalarConverter::isCharLiteral(const std::string& input)
{
	int value = 0;

	if (value >= 0 && value <= 127)  // In valid ASCII range
	{
		if (std::isprint(static_cast<char>(value)))
			std::cout << "\033[1;32mchar: '" << input[1] << "'\033[0m" << std::endl;  // Green color for char only
		else
			std::cout << "\033[1;32mchar: Non displayable\033[0m" << std::endl;  // Green color
	}
	else
	{
		std::cout << "\033[1;32mchar: impossible\033[0m" << std::endl;  // Green color
	}
	
	std::cout << "int: " << static_cast<int>(input[1]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[1]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[1]) << ".0" << std::endl;
	
}
void		ScalarConverter::isIntLiteral(const std::string& input)
{
	int value = atoi(input.c_str());
	
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "\033[0;32mint: " << value << "\033[0m" << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	ScalarConverter::isFloatLiteral(const std::string& input)
{
	float value = static_cast<float>(atof(input.c_str()));

	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "\033[0;32mfloat: ";
	if (value == static_cast<int>(value))  
		std::cout << value << ".0f\033[0m" << std::endl;
	else
		std::cout << value << "f" << std::endl;
	
	std::cout << "double: ";
	if (value == static_cast<int>(value))
		std::cout << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::isDoubleLiteral(const std::string& input)
{
	double value = atof(input.c_str());

	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: ";
	if (value == static_cast<int>(value))
		std::cout << static_cast<float>(value) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;
	
	std::cout << "\033[0;32mdouble: ";
	if (value == static_cast<int>(value))
		std::cout << value << ".0\033[0m" << std::endl;
	else
		std::cout << value << std::endl;
}
void		ScalarConverter::isSpecialLiteral(const std::string& input)
{
	if(input == "nan")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "nanf\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "nan\033[0m" << std::endl;
	}
	else if(input == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "nanf\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "nan\033[0m" << std::endl;
	}
	else if(input == "+inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "+inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "+inf\033[0m" << std::endl;
	}
	else if(input == "-inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "-inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "-inf\033[0m" << std::endl;
	}
	else if(input == "inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "+inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "+inf\033[0m" << std::endl;
	}
	else if(input == "+inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "+inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "+inf\033[0m" << std::endl;
	}
	else if(input == "-inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "-inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "-inf\033[0m" << std::endl;
	}
	else if(input == "inff")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "\033[0;32mfloat: " << "+inff\033[0m" << std::endl;
		std::cout << "\033[0;32mdouble: " << "+inf\033[0m" << std::endl;
	}
}