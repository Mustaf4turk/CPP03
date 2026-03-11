/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:50 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 09:00:24 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//canonical
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->name = "Default";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = source;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.name;
		this->hit_points = source.hit_points;
		this->energy_points = source.energy_points;
		this->attack_damage = source.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << this->name << std::endl;
}

//wanted
ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap Constructor called for " << name << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points	= 10;
	this->attack_damage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << "ClapTrap " << this->name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->attack_damage;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " cannot attack (No HP or Energy)!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		if (amount >= this->hit_points)
			this->hit_points = 0;
		else
			this->hit_points = this->hit_points - amount;

		std::cout << "ClapTrap " << this->name << " takes " << amount;
		std::cout << " damage! Current HP: ";
		std::cout << this->hit_points << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		this->hit_points = this->hit_points + amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " repairs itself for " << amount;
		std::cout << " HP! Current HP: " << this->hit_points << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name;
		std::cout << " cannot repair (No HP or Energy)!" << std::endl;
	}
}
