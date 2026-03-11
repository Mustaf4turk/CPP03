/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:59:50 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 13:22:02 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    
    //in here we create an array of N zombies.
    //the difference between this and malloc is
    //that the constructor will be called for each zombie in the array.
    //but if we used malloc, the constructor would not be called and 
    //we would have to call it manually for each zombie in the array.
    int i;
    Zombie* horde = new Zombie[N];

    i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return horde;
}
