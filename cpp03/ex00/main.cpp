/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:25 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 09:50:50 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Test 1: Basic Damage " << std::endl;
	ClapTrap robot1("Robot1");
	robot1.print_hit_points();
	robot1.takeDamage(1);
	robot1.print_hit_points();
	
	std::cout << "\n=== Test 2: Basic Energy ===" << std::endl;
	ClapTrap robot2("Robot2");
	robot2.print_energy_points();
	robot2.attack("Enemy1");
	robot2.print_energy_points();
	robot2.takeDamage(2);
	robot2.beRepaired(1);
	robot2.print_energy_points();
	
	std::cout << "\n=== Test 3: Energy Depletion ===" << std::endl;
	ClapTrap robot3("Robot3");
	int i = 0;
	while (i < 12)
	{
		if (i < 10)
			robot3.attack("Dummy");
		else
		{
			std::cout << "Attempting action with no energy:" << std::endl;
			robot3.attack("LastEnemy");
		}
		i++;
	}
	
	std::cout << "\n=== Test 4: Massive Death ===" << std::endl;
	ClapTrap robot4("Robot4");
	robot4.takeDamage(15);
	robot4.print_energy_points();
	robot4.print_hit_points();
	
	
	std::cout << "\n=== Test 5: Repair when Dead ===" << std::endl;
	ClapTrap robot5("Robot5");
	robot5.takeDamage(10);
	robot5.print_energy_points();
	robot5.print_hit_points();
	robot5.beRepaired(5);
	robot5.print_energy_points();
	robot5.print_hit_points();
	
	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	ClapTrap original("Original");
	original.attack("Test");
	ClapTrap copy(original);
	copy.attack("CopyTarget");
	
	std::cout << "\n=== Test 7: Assignment Operator ===" << std::endl;
	ClapTrap robot6("Robot6");
	ClapTrap robot7("Robot7");
	robot6.attack("Enemy");
	robot7 = robot6;
	robot7.attack("AnotherEnemy");
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
