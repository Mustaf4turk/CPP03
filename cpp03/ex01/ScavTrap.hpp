/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:48 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 11:50:04 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		//canonical
		ScavTrap();
		ScavTrap(const ScavTrap &source);
		ScavTrap &operator=(const ScavTrap &source);
		~ScavTrap();

		//wanted
		ScavTrap(const std::string &name);
		void attack(const std::string& target);
		void guardGate();
};

#endif
