/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:00 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 13:38:12 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "\033[38;5;10m--- Memory adresses ---\033[0m" << std::endl;
	std::cout << "\033[38;5;10mStr variable: \033[0m" << &str << std::endl;
	std::cout << "\033[38;5;10mStr pointer: \033[0m" << stringPTR << std::endl;
	std::cout << "\033[38;5;10mStr reference: \033[0m" << &stringREF << std::endl;

	std::cout << "\033[38;5;10m--- Values ---\033[0m" << std::endl;
	std::cout << "\033[38;5;10mStr variable: \033[0m" << str << std::endl;
	std::cout << "\033[38;5;10mStr pointer: \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[38;5;10mStr reference: \033[0m" << stringREF << std::endl;

}
