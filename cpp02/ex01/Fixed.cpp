/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:02:17 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 17:12:08 by rakman           ###   ########.fr       */
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}

//ex01 functions

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n * ( 1 << _fractionalBits );
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_fixedPointValue / (1 << _fractionalBits);
}

// When 'std::cout << a' is called:
// 1. The compiler checks for an overloaded operator<< that accepts (std::ostream, Fixed).
// 2. It finds this function and passes 'std::cout' as the output stream and 'a' as the fixedPointValue.
// 3. The function calls 'a.toFloat()' to print the actual floating-point value.
// 4. Finally, it returns the output stream to support chained operations.
std::ostream &operator<<(std::ostream &outputstream, Fixed const &fixedPointValue)
{
	outputstream << fixedPointValue.toFloat();
	
	return (outputstream);
}
