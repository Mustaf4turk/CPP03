/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:40 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 12:24:38 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	ScavTrap scav("Scavvy");
	
	scav.attack("Enemy1");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
	
	ScavTrap warrior("Warrior");
	warrior.attack("Monster1");
	warrior.attack("Monster2");
	warrior.attack("Monster3");
	warrior.guardGate();
	
	ScavTrap tired("Tired");
	int i = 0;
	while (i < 51)
	{
		if (i < 50)
			tired.attack("Dummy");
		else
		{
			std::cout << "Attempting attack after energy depleted:" << std::endl;
			tired.attack("LastEnemy");
		}
		i++;
	}
	
	ScavTrap original("Original");
	ScavTrap copy(original);
	copy.attack("CopyTarget");
	
	return 0;
}
