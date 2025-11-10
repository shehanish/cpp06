/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:25:40 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/10 17:13:09 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONVERT_HPP
#define	CONVERT_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
	private: //non-instantiable
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		//Helper functions
		static void	isCharLiteral(const std::string& input);
		static void		isIntLiteral(const std::string& input);
		static void	isFloatLiteral(const std::string& input);
		static void	isDoubleLiteral(const std::string& input);
		static void	isSpecialLiteral(const std::string& input); //Result of a undefined mathamatical operation
			
		static bool	detectInt(const std::string& input);
		static bool detectFloat(const std::string& input);
		static bool detectDouble(const std::string& input);
	
public:
	static void		convert(const std::string& input);
};

#endif