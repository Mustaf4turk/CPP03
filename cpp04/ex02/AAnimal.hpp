/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:33 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:34:12 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		
		std::string type;
	
	public:

		AAnimal();
		AAnimal(const AAnimal &animal);
		AAnimal& operator=(const AAnimal& animal);
		virtual ~AAnimal();
		
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
