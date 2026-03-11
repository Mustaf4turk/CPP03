/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookSearch.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:34:35 by rakman            #+#    #+#             */
/*   Updated: 2025/11/12 21:30:23 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"


void PhoneBook::_printFormattedCell(std::string content) const
{
	if (content.length() > 10)
		content = content.substr(0, 9) + ".";
	operator<<(std::cout, std::setw(10));
	operator<<(std::cout, content);
}

bool PhoneBook::_isNumeric(const std::string& str) const
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

void PhoneBook::_displayContactList() const
{
	int contactCount;
	int i;

	if (this->_totalAddedCount > 8)
		contactCount = 8;
	else
		contactCount = this->_totalAddedCount;
	
	operator<<(std::cout, "\033[1;33m");	
	operator<<(std::cout, "---------------------------------------------\n");	
	operator<<(std::cout, "|");
	PhoneBook::_printFormattedCell("Index");
	operator<<(std::cout, "|");
	PhoneBook::_printFormattedCell("First Name");
	operator<<(std::cout, "|");
	PhoneBook::_printFormattedCell("Last Name");
	operator<<(std::cout, "|");
	PhoneBook::_printFormattedCell("Nickname");
	operator<<(std::cout, "|\n");
	operator<<(std::cout, "---------------------------------------------\n");
	operator<<(std::cout, "\033[0m");

	i = 0;
	while (i < contactCount)
	{	
		std::stringstream ss;
		ss << i;

		operator<<(std::cout, "\033[1;33m|\033[0m");
		PhoneBook::_printFormattedCell(ss.str());
		operator<<(std::cout, "\033[1;33m|\033[0m");
		PhoneBook::_printFormattedCell(this->_contacts[i].getFirstName());
		operator<<(std::cout, "\033[1;33m|\033[0m");
		PhoneBook::_printFormattedCell(this->_contacts[i].getLastName());
		operator<<(std::cout, "\033[1;33m|\033[0m");
		PhoneBook::_printFormattedCell(this->_contacts[i].getNickname());
		operator<<(std::cout, "\033[1;33m|\n\033[0m");
		i++;
	}
	operator<<(std::cout, "\033[1;33m---------------------------------------------\n\033[0m");
}

void PhoneBook::searchContacts()
{
	int contactCount;
	int index;
	std::string indexStr;

	//we are not using seperate index and contactCount
	//so if we have more than 8 contacts, we only show 8
	if (this->_totalAddedCount > 8)
		contactCount = 8;
	else
		contactCount = this->_totalAddedCount;
	//if no contact added yet, show message and return
	if (contactCount == 0)
	{
		operator<<(std::cout, "\n\033[1;33mPhoneBook is empty. Please ADD a contact first.\033[0m\n");
		return;
	}

	//display contact list
	this->_displayContactList();
	
	while (true)
	{
		// get input
		operator<<(std::cout, "\033[1;38;5;208mPlease enter the index of the contact to display\nλ \033[0m");

        
        if (!std::getline(std::cin, indexStr)) 
        {
            if (PhoneBook::shouldExit() || std::cin.eof())
                return;
            std::cin.clear();
            continue;
        }
		//	we need to check if input is numeric 
		if (!PhoneBook::_isNumeric(indexStr))
		{
			std::cerr << "\n\033[1;31mPlease enter a valid number.\033[0m\n";
			continue;
		}
		
		// Convert to integer and check the range
		// there is no need to implement integere overflow here
		index = std::atoi(indexStr.c_str());
		if (index >= 0 && index < contactCount)
			//exit the loop
			break;
		
		// Invalid index message, if loop didnt break
		std::ostringstream err_ss;
		err_ss << "\n\033[1;31mInvalid index. Please enter a number between 0 and " 
		       << (contactCount - 1) << ".\033[0m\n";
		operator<<(std::cerr, err_ss.str());
	}

	if (PhoneBook::shouldExit())
		return;

	operator<<(std::cout, "\n\033[1;38;5;208mContact Details:\033[0m\n");
	std::cout << "\033[1;38;5;208mFirst Name:     \033[0m" + this->_contacts[index].getFirstName() << std::endl;
	std::cout << "\033[1;38;5;208mLast Name:      \033[0m" + this->_contacts[index].getLastName() << std::endl;
	std::cout << "\033[1;38;5;208mNickname:       \033[0m" + this->_contacts[index].getNickname() << std::endl;
	std::cout << "\033[1;38;5;208mPhone Number:   \033[0m" + this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "\033[1;38;5;208mDarkest Secret: \033[0m" + this->_contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
	
	operator<<(std::cout, "\033[1;32m\033[1mWish your next wish:\033[0m\n");
}
