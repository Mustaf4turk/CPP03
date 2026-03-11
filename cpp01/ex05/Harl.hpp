/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:30 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 13:00:35 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private:

        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

    public:

        Harl(void);
        ~Harl(void);
        void complain( std::string level );
};

#endif