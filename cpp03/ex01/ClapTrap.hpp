/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:37 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 11:49:38 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
	protected:

		std::string				name;
		unsigned int			hit_points;
		unsigned int			energy_points;
		unsigned int			attack_damage;
	
	public:

		//canonical
		ClapTrap();
		ClapTrap(const ClapTrap &source);
		ClapTrap &operator=(const ClapTrap &source);
		~ClapTrap();

		//wanted
		ClapTrap(const std::string &name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif
