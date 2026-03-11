/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:42 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << kColor << "Dog default constructor called" << kReset << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	this->brain = new Brain(*dog.brain);
	std::cout << kColor << "Dog copy constructor called" << kReset << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << kColor << "Dog assignment operator called." << kReset << std::endl;
	if (this != &dog)
	{
		Animal::operator=(dog);
		delete this->brain;
		this->brain = new Brain(*dog.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << kColor << "Dog destructor called." << kReset << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << kColor << "Woof! Woof!" << kReset << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}
