/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:12:44 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/09 17:16:57 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


int main(int argc, char **argv)
{
	(void)argv;
	if(argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cout << "Not enough Parameers!" << std::endl;
	}
	return (0);
}