/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:35 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:29:14 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


static const char* kColor = "\033[36m";
static const char* kReset = "\033[0m";

Brain::Brain()
{
	std::cout << kColor << "Brain default constructor called" << kReset << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << kColor << "Brain copy constructor called" << kReset << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << kColor << "Brain assignment operator called." << kReset << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << kColor << "Brain destructor called." << kReset << std::endl;
}
