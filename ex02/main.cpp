/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:35:15 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/13 12:51:50 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void)
{
    // Seed random number generator
    std::srand(std::time(NULL));
    
    // Test with pointer version
    std::cout << "=== Testing identify(Base* p) ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();
        std::cout << "Generated type: ";
        identify(ptr);
        delete ptr;
    }
    
    std::cout << std::endl;
    
    // Test with reference version
    std::cout << "=== Testing identify(Base& p) ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();
        std::cout << "Generated type: ";
        identify(*ptr);  // Dereference pointer to get reference
        delete ptr;
    }
    
    return 0;
}
