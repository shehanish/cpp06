/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:46 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/11 18:17:56 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Data* original = new Data;
	original->value = 42;

	std::cout << "Pointer: " << original << std::endl;
	std::cout << "Original Value:  " << original->value << std::endl; 
	
	uintptr_t raw_byte = Serializer::serialize(original);
	std::cout << "serialized: " << raw_byte << std::endl;
	
	Data* Deserialized = Serializer::deserialize(raw_byte);
	std::cout << "Restored: " << Deserialized << std::endl;
	std::cout << "Restored Value: " << Deserialized->value << std::endl;
	
	// Verify pointers match (subject requirement)
	if (original == Deserialized)
		std::cout << " Success: Pointers match!" << std::endl;
	else
		std::cout << "\n Error: Pointers don't match!" << std::endl;
	
	delete(original); 
	return (0);
}