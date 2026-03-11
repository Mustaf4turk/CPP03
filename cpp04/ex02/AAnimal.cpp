/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:32 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:34:12 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"


static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << kColor << "AAnimal default constructor called" << kReset << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << kColor << "AAnimal copy constructor called" << kReset << std::endl;
	this->type = animal.type;
}

AAnimal& AAnimal::operator=(const AAnimal& animal)
{
	std::cout << kColor << "AAnimal assignment operator called." << kReset << std::endl;
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << kColor << "AAnimal destructor called." << kReset << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}
