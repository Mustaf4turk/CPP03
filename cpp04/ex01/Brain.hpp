/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:28:36 by rakman            #+#    #+#             */
/*   Updated: 2026/03/11 13:29:14 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:


	public:

		std::string ideas[100];

		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();
};

#endif
