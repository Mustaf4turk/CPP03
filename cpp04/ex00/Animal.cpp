/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:17 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

Animal::Animal() : type("Animal")
{
	std::cout << kColor << "Animal default constructor called" << kReset << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << kColor << "Animal copy constructor called" << kReset << std::endl;
	this->type = animal.type;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << kColor << "Animal assignment operator called." << kReset << std::endl;
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << kColor << "Animal destructor called." << kReset << std::endl;
}

void Animal::makeSound() const
{
	std::cout << kColor << "* Generic animal sound *" << kReset << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
