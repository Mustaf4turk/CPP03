/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:02:33 by rakman            #+#    #+#             */
/*   Updated: 2025/11/12 16:47:09 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickname) {
    this->_nickName = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return (this->_firstName);
}

std::string Contact::getLastName() const {
    return (this->_lastName);
}

std::string Contact::getNickname() const {
    return (this->_nickName);
}

std::string Contact::getPhoneNumber() const {
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const {
    return (this->_darkestSecret);
}
