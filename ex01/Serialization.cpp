/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:14:57 by shkaruna          #+#    #+#             */
/*   Updated: 2025/11/11 18:18:00 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer(){};

Serializer::Serializer(const Serializer& other){};

Serializer&	Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer(){};

uintptr_t	Serializer::serialize(Data*	ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}