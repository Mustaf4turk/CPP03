/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:30 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << kColor << "WrongCat default constructor called" << kReset << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
	std::cout << kColor << "WrongCat copy constructor called" << kReset << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cat)
{
	std::cout << kColor << "WrongCat assignment operator called." << kReset << std::endl;
	if (this != &cat)
	{
		WrongAnimal::operator=(cat);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << kColor << "WrongCat destructor called." << kReset << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << kColor << "Meooowww!!" << kReset << std::endl;
}
