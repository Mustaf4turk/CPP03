/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:02:08 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 14:22:42 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*int niceOutput( void )
{
    std::cout << "\033[92m*** DEFAULT CONSTRUCTOR CALLING ***\033[0m" << std::endl;
    Fixed a;
    std::cout << std::endl;

    std::cout << "\033[92m*** COPY CONSTRUCTOR CALLING ***\033[0m" << std::endl;
    Fixed b( a );
    std::cout << std::endl;

    std::cout << "\033[92m*** DEFAULT CONSTRUCTOR CALLING FOR THIRD OBJECT***\033[0m" << std::endl;
    Fixed c;
    std::cout << std::endl;

    std::cout << "\033[92m*** COPY ASSIGNMENT OPERATOR CALLING ***\033[0m" << std::endl;
    c = b;
    std::cout << std::endl;

    std::cout << "\033[92m*** GET RAW BITS FUNCTION CALLING ***\033[0m" << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "\033[92m*** DESTRUCTORS CALLING ***\033[0m" << std::endl;
    return 0;
}
*/

int main( void )
{
    //you can call the nice output from this function
    //niceOutput(); 

    Fixed a;
    Fixed b( a );
    Fixed c;

    //in here compiler turns this line into c.operator=(b);
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
