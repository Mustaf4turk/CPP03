/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:02:30 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 16:01:51 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		
		Fixed();
		Fixed( const Fixed &src );
		~Fixed();
		Fixed &operator=( const Fixed &src );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		//ex01
		Fixed(const int n);
		Fixed(const float n);
		
		float toFloat( void ) const;
		int   toInt( void ) const;

		//ex02
		//we can overlaod these operators as member functions because
		//they the left operand is always a Fixed object.
		bool operator>(const Fixed &righthandside) const;
		bool operator<(const Fixed &righthandside) const;
		bool operator>=(const Fixed &righthandside) const;
		bool operator<=(const Fixed &righthandside) const;
		bool operator==(const Fixed &righthandside) const;
		bool operator!=(const Fixed &righthandside) const;

		Fixed operator+(const Fixed &righthandside) const;
		Fixed operator-(const Fixed &righthandside) const;
		Fixed operator*(const Fixed &righthandside) const;
		Fixed operator/(const Fixed &righthandside) const;

		Fixed &operator++( void );
		Fixed operator++( int );
		Fixed &operator--( void );
		Fixed operator--( int );

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<( std::ostream &outputstream, Fixed const &fixedPointValue );

#endif