/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:27 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << kColor << "WrongAnimal default constructor called" << kReset << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << kColor << "WrongAnimal copy constructor called" << kReset << std::endl;
	this->type = animal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
	std::cout << kColor << "WrongAnimal assignment operator called." << kReset << std::endl;
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << kColor << "WrongAnimal destructor called." << kReset << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << kColor << "* Generic wrong animal sound *" << kReset << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
