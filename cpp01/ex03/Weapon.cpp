/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:01:05 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 14:48:19 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType( void ) const
{
    const std::string &typeReference = this->type;

    return typeReference;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
