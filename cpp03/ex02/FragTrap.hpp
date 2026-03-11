/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 06:04:58 by rakman            #+#    #+#             */
/*   Updated: 2026/02/17 08:54:47 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		//canonical
		FragTrap();
		FragTrap(const FragTrap &source);
		FragTrap &operator=(const FragTrap &source);
		~FragTrap();

		//wanted
		FragTrap(const std::string &name);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
