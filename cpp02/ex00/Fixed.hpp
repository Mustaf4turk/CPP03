/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:00:59 by rakman            #+#    #+#             */
/*   Updated: 2026/02/11 14:25:22 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		
		// ---ex00---
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		
		// ---ex00---

		Fixed();
		Fixed( const Fixed &src );
		Fixed &operator=( const Fixed &src );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif