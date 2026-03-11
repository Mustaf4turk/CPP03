/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:39 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << kColor << "Cat default constructor called" << kReset << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	this->brain = new Brain(*cat.brain);
	std::cout << kColor << "Cat copy constructor called" << kReset << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << kColor << "Cat assignment operator called." << kReset << std::endl;
	if (this != &cat)
	{
		Animal::operator=(cat);
		delete this->brain;
		this->brain = new Brain(*cat.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << kColor << "Cat destructor called." << kReset << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << kColor << "Meooowww!!" << kReset << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}
