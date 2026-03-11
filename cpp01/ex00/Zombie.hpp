/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:11:42 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 13:08:30 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:

	    std::string name;
    
	public:

		Zombie();
		~Zombie();
	    Zombie( std::string name );
	    void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
