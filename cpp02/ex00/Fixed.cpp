/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:00:47 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 14:30:15 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//in copy assignment operator if we use like this
//a = b; firstly, compiler turns this line into a.operator=(b);
//then in operator function, compiler adds Fixed *const this as parameter as 
//in all non-static member functions, so the function becomes like this:
//Fixed &Fixed::operator=( Fixed * const this, const Fixed &src )
//in here a becomes this and b becomes src, so we can access a's 
//members with this-> and b's members with src.
Fixed &Fixed::operator=( const Fixed &src ) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &src )
	{
        this->_fixedPointValue = src.getRawBits();
    }
    else
    {

    }
    return (*this);
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}