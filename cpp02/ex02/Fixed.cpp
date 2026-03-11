/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:02:28 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 17:22:35 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


//ex00
Fixed::Fixed( void )
{
	this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &src )
{
	*this = src;
}

Fixed &Fixed::operator=( const Fixed &src ) 
{
    if ( this != &src )
	{
        this->_fixedPointValue = src.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed( void )
{
	
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}

//ex01
Fixed::Fixed(const int n)
{
	this->_fixedPointValue = n * (1 << _fractionalBits);
}

Fixed::Fixed(const float n)
{
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

std::ostream &operator<<(std::ostream &outputstream, Fixed const &fixedPointValue)
{
	outputstream << fixedPointValue.toFloat();
	
	return (outputstream);
}

//ex02
//first compiler turns a > b to a.operator>(b)
//then it checks if there is an overload for operator> in Fixed class
//Fixed const *this added to functions from compiler.
bool Fixed::operator>(const Fixed &righthandside) const
{
	if (this->_fixedPointValue > righthandside.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &righthandside) const
{
	if (this->_fixedPointValue < righthandside.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &righthandside) const
{
	if (this->_fixedPointValue >= righthandside.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &righthandside) const
{
	if (this->_fixedPointValue <= righthandside.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &righthandside) const
{
	if (this->_fixedPointValue == righthandside.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &righthandside) const
{
	if (this->_fixedPointValue != righthandside.getRawBits())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed &righthandside) const
{
	return Fixed(this->toFloat() + righthandside.toFloat());
}

Fixed Fixed::operator-(const Fixed &righthandside) const
{
	return Fixed(this->toFloat() - righthandside.toFloat());
}

Fixed Fixed::operator*(const Fixed &righthandside) const
{
	return Fixed(this->toFloat() * righthandside.toFloat());
}

Fixed Fixed::operator/(const Fixed &righthandside) const
{
	return Fixed(this->toFloat() / righthandside.toFloat());
}

Fixed &Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return *this;
}

//to understand the difference between pre-increment and post-increment, we can look at the following example:
//we have a dummy parameter in post-increment operator. its 0.
Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
