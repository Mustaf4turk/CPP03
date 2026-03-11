/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:43 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:29:14 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		
		Brain* brain;

	public:

		Dog();
		Dog(const Dog& dog);
		Dog& operator=(const Dog& dog);
		~Dog();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif
