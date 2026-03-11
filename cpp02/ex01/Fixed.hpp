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
		
		// ---ex00---

		Fixed();
		Fixed( const Fixed &src );	
		Fixed &operator=( const Fixed &src );	
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// ---ex01---
		Fixed(const int n);
		Fixed(const float n);
		
		float toFloat( void ) const;
		int   toInt( void ) const;
};

//actually we can declare this function with friend keyword in member functions
//but we can not, its forbidden.
//
std::ostream &operator<<( std::ostream &outputstream, Fixed const &fixedPointValue );

#endif