/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:55 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 11:47:12 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//canonical
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.name;
        this->hit_points = source.hit_points;
        this->energy_points = source.energy_points;
        this->attack_damage = source.attack_damage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << this->name << std::endl;
}

//wanted
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called for " << name << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "FragTrap " << this->name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->attack_damage;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->name << " cannot attack (No HP or Energy)!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl;
}
