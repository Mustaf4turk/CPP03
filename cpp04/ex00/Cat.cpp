/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:20 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

Cat::Cat()
{
	this->type = "Cat";
	std::cout << kColor << "Cat default constructor called" << kReset << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << kColor << "Cat copy constructor called" << kReset << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << kColor << "Cat assignment operator called." << kReset << std::endl;
	if (this != &cat)
	{
		Animal::operator=(cat);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << kColor << "Cat destructor called." << kReset << std::endl;
}

void Cat::makeSound() const
{
	std::cout << kColor << "Meooowww!!" << kReset << std::endl;
}
