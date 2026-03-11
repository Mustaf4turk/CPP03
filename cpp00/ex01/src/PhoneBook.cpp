/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:53:28 by rakman            #+#    #+#             */
/*   Updated: 2025/11/12 19:38:25 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/PhoneBook.hpp"


const std::string PhoneBook::_intro_banner =
		"\033[1;33m _____                                                                                   _____ \n"
		"( ___ )                                                                                 ( ___ )\n"
		" |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n"
		" |   |                                                                                   |   | \n"
		" |   |                                                                                   |   | \n"
		" |   |                                                                                   |   | \n"
		" |   |    d8888b. db   db  .d88b.  d8b   db d88888b d8888b.  .d88b.   .d88b.  db   dD    |   | \n"
		" |   |    88  `8D 88   88 .8P  Y8. 888o  88 88'     88  `8D .8P  Y8. .8P  Y8. 88 ,8P'    |   | \n"
		" |   |    88oodD' 88ooo88 88    88 88V8o 88 88ooooo 88oooY' 88    88 88    88 88,8P      |   | \n"
		" |   |    88~~~   88~~~88 88    88 88 V8o88 88~~~~~ 88~~~b. 88    88 88    88 88`8b      |   | \n"
		" |   |    88      88   88 `8b  d8' 88  V888 88.     88   8D `8b  d8' `8b  d8' 88 `88.    |   | \n"
		" |   |    88      YP   YP  `Y88P'  VP   V8P Y88888P Y8888P'  `Y88P'   `Y88P'  YP   YD    |   | \n"
		" |   |                                                                                   |   | \n"
		" |   |                                                                                   |   | \n"
		" |   |                                                                                   |   | \n"
		" |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n"
		"(_____)                                                                                 (_____) \033[0m\n";

const std::string PhoneBook::_outro_banner = 
		"\033[1;31m\n"
        "▄▄▄▄·             • ▌ ▄ ·. \n"
        "▐█ ▀█▪▪     ▪     ·██ ▐███▪\n"
        "▐█▀▀█▄ ▄█▀▄  ▄█▀▄ ▐█ ▌▐▌▐█·\n"
        "██▄▪▐█▐█▌.▐▌▐█▌.▐▌██ ██▌▐█▌\n"
        "·▀▀▀▀  ▀█▄▀▪ ▀█▄▀▪▀▀  █▪▀▀▀\n"
        "\n";

PhoneBook::PhoneBook()
{
	this->_totalAddedCount = 0;
	operator<<(std::cout, PhoneBook::_intro_banner);
	operator<<(std::cout, "\033[1;32mWelcome to the PhoneBook, what is your desire? Just type it and i'll make it happen.\033[0m\n");
}

PhoneBook::~PhoneBook() 
{
	operator<<(std::cout, PhoneBook::_outro_banner);
	operator<<(std::cout, "What,,, have,,, you,,,, done, EVIL!");
}

volatile sig_atomic_t PhoneBook::_signalReceived = 0;

void PhoneBook::signalHandler(int signum) 
{
    (void)signum;
    _signalReceived = 1;
}

bool PhoneBook::shouldExit() 
{
	if (_signalReceived == 1)
		return (1);
	else
		return (0);
}

std::string PhoneBook::_getAnswer(const std::string question, const std::string err) const
{
    std::string answer;

    while (answer.empty() && !PhoneBook::shouldExit())
    {
        operator<<(std::cout, question);
        operator<<(std::cout, "\033[1;38;5;208mλ \033[0m");

        if (!std::getline(std::cin, answer))
        {
            if (PhoneBook::shouldExit() || std::cin.eof())
                return ("");
            std::cin.clear();
        }
        if (answer.empty() && !PhoneBook::shouldExit())
            operator<<(std::cout, err);
    }
    return (answer);
}


void PhoneBook::addContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	int			index;

	firstName = this->_getAnswer(
		"\033[1;38;5;208mPlease enter the first name of the new contact\n",
		"\n\e[31mName field cannot be empty, please enter a valid name\e[0m\n"
	);
	lastName = this->_getAnswer(
		"\033[1;38;5;208mPlease enter the last name of the new contact\n",
		"\n\e[31mLast name field cannot be empty, please enter a valid name\e[0m\n"
	);
	nickName = this->_getAnswer(
		"\033[1;38;5;208mPlease enter the nickname of the new contact\n",
		"\n\e[31mNick name field cannot be empty, please enter a valid name\e[0m\n"
	);
	phoneNumber = this->_getAnswer(
		"\033[1;38;5;208mPlease enter the number of the new contact\n",
		"\n\e[31mPhone number field cannot be empty, please enter a valid name\e[0m\n"
	);
	darkestSecret = this->_getAnswer(
		"\033[1;38;5;208mPlease enter the darkest secret of the new contact\n",
		"\n\e[31mDarkest secret field cannot be empty, please enter a valid name\e[0m\n"
	);

	//if you have an object and wanna use its member function use .
	index = this->_totalAddedCount % 8;
	this->_contacts[index].setFirstName(firstName);
	this->_contacts[index].setLastName(lastName);
	this->_contacts[index].setNickName(nickName);
	this->_contacts[index].setPhoneNumber(phoneNumber);
	this->_contacts[index].setDarkestSecret(darkestSecret);
	this->_totalAddedCount++;
	if (PhoneBook::shouldExit() != 1)
		operator<<(std::cout, "\033[1;32mNew contact successfully created! Please wish your next desire.\e[0m\n");
}
