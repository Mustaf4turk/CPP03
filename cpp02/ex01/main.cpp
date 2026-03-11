/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:02:22 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 16:47:35 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*int niceOutput( void )
{
    std::cout << "\033[92m*** DEFAULT CONSTRUCTOR CALLING WITHOUT PARAMETERS ***\033[0m" << std::endl;
    Fixed a;
    std::cout << std::endl;

    std::cout << "\033[92m*** INTEGER CONSTRUCTOR CALLING WITH PARAMETER 10***\033[0m" << std::endl;
    Fixed b( 10 );
    std::cout << std::endl;

    std::cout << "\033[92m*** FLOAT CONSTRUCTOR CALLING WITH PARAMETER 42.42f***\033[0m" << std::endl;
    Fixed c( 42.42f );
    std::cout << std::endl;

    std::cout << "\033[92m*** COPY CONSTRUCTOR CALLING WITH PARAMETER b ***\033[0m" << std::endl;
    Fixed d( b );
    std::cout << std::endl;

    std::cout << "\033[92m*** COPY ASSIGNMENT OPERATOR CALLING WITH PARAMETER 1234.4321f ***\033[0m" << std::endl;
    a = Fixed( 1234.4321f );
    std::cout << std::endl;

    std::cout << "\033[92m*** operator<< OVERLOAD CALLING ***\033[0m" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << std::endl;


    std::cout << "\033[92m*** toInt FUNCTION CALLING ***\033[0m" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << std::endl;

    std::cout << "\033[92m*** DESTRUCTORS CALLING ***\033[0m" << std::endl;
    return 0;
}*/

int main( void )
{
    //nice output function
    //niceOutput();
    //std::cout << std::endl;

    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
