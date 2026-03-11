/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:44:09 by rakman            #+#    #+#             */
/*   Updated: 2025/11/12 17:40:02 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"


int main()
{
    struct sigaction sa;
    std::memset(&sa, 0, sizeof(sa));
    sa.sa_handler = PhoneBook::signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0; 

    if (sigaction(SIGINT, &sa, NULL) == -1) 
	{
        std::cerr << "Sinyal kaydedilemedi!" << std::endl;
        return (1);
    }

	PhoneBook phoneBook;
	std::string command;
	while (PhoneBook::shouldExit() != 1)
	{
		operator<<(std::cout, "\033[1;32m\033[1m> ");
		
		//check if the steam is ok, if stream returns false check why its failing.
		if (!std::getline(std::cin, command)) 
		{	
			//sigint
			if (PhoneBook::shouldExit()) 
			{
				std::cout << "SIGINT recieved, terminating phonebook..." << std::endl;
				break;
			}
			//ctrl + d
			if (std::cin.eof()) 
			{
				std::cout << "EOF recieved, terminating phonebook..." << std::endl;
				break;
			}
			if (std::cin.fail() || std::cin.bad()) 
			{
				std::cerr << "READ ERROR!" << std::endl;
				std::cin.clear();
				continue;
			}
		}	
		else if (operator==(command, "ADD"))
			phoneBook.addContact();
		else if (operator==(command, "SEARCH"))
			phoneBook.searchContacts();	
		else if (operator==(command, "EXIT"))
			break;
		// when you create a program in cpp there is only one std::cin object
		// you could use this like this too 
		// if (!std::getline(std::cin, command)) {
		// in cpp if you check a stream object in if block means you checking its !fail() flag
		// which returns true false
		// return (1);
		//	}
		//	
		//	ctrl+d -> eof -> read = 0 -> std::cin eofbit and failbit flags rise. and when theese flags set 
		//	it wont clear itself till you clear it.
		//
	}
	return(0);
}
