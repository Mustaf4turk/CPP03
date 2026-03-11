/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:50 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 14:48:04 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon)
{

}

void HumanA::attack( void ) const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
