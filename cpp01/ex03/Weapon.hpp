/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:01:11 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 14:48:26 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:

        std::string type;
    
    public:
    
        Weapon( std::string type );
        const std::string &getType( void ) const;
        void setType( const std::string &type );
};

#endif
