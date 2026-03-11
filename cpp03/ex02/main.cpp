/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:05:00 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 09:06:31 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap Construction Chain ===" << std::endl;
	ScavTrap scav("Scavvy");
	
	std::cout << "\n=== Testing ScavTrap Abilities ===" << std::endl;
	scav.attack("Enemy1");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
	
	std::cout << "\n=== Testing FragTrap Construction Chain ===" << std::endl;
	FragTrap frag("Fraggy");
	
	std::cout << "\n=== Testing FragTrap Abilities ===" << std::endl;
	frag.attack("Monster1");
	frag.attack("Monster2");
	frag.attack("Monster3");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();
	
	std::cout << "\n=== Testing FragTrap vs ScavTrap ===" << std::endl;
	FragTrap warrior("Warrior");
	ScavTrap guardian("Guardian");
	
	std::cout << "\nWarrior attacks:" << std::endl;
	warrior.attack("Guardian");
	guardian.takeDamage(30);
	
	std::cout << "\nGuardian attacks:" << std::endl;
	guardian.attack("Warrior");
	warrior.takeDamage(20);
	
	std::cout << "\nSpecial abilities:" << std::endl;
	warrior.highFivesGuys();
	guardian.guardGate();
	
	std::cout << "\n=== Testing FragTrap Energy (100 points) ===" << std::endl;
	FragTrap energetic("Energetic");
	int i = 0;
	while (i < 10)
	{
		energetic.attack("Training Dummy");
		i++;
	}
	energetic.highFivesGuys();
	
	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	FragTrap original("Original");
	original.attack("Test");
	FragTrap copy(original);
	copy.highFivesGuys();
	
	std::cout << "\n=== Testing All Three Types Together ===" << std::endl;
	ClapTrap basic("Basic");
	ScavTrap advanced("Advanced");
	FragTrap ultimate("Ultimate");
	
	std::cout << "\nBasic attack (0 damage):" << std::endl;
	basic.attack("Dummy");
	
	std::cout << "\nAdvanced attack (20 damage):" << std::endl;
	advanced.attack("Dummy");
	
	std::cout << "\nUltimate attack (30 damage):" << std::endl;
	ultimate.attack("Dummy");
	
	std::cout << "\nSpecial abilities:" << std::endl;
	advanced.guardGate();
	ultimate.highFivesGuys();
	
	std::cout << "\n=== Destruction Order (reverse of construction) ===" << std::endl;
	return 0;
}
