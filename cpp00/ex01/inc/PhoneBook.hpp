/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:44:20 by rakman            #+#    #+#             */
/*   Updated: 2025/11/12 18:00:52 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>


/*
 * Name Mangling / Implicit Parameter Injection
 *
 * void Contact::_displayContactList() const {
 * std::cout << this->_name;
 * }
 *
 * turns into this (internally by the compiler):
 *
 * void _ZN7Contact19_displayContactListEv(const Contact* const this) {
 * std::cout << this->_name;
 * }
 *
 * When the compiler encounters a class member function, it implicitly injects 
 * a 'this' pointer as the first parameter.
 *
 * The type of 'this' depends on the 'const' qualifier:
 *
 * 1. Non-const function:  ClassName* const this
 * (Pointer is constant, but the data it points to can be modified.)
 *
 * 2. Const function:      const ClassName* const this
 * (Both the pointer and the data it points to are constant/read-only.)
 *
 * This mechanism allows the same compiled function code to operate on 
 * different object instances by simply passing the object's address.
 */

//
// ### Pointer & Const Reference Table
//
// | Syntax | Data Mutable? | Address Mutable? | Short Description |
// | --- | --- | --- | --- |
// | `T* ptr` | **Yes** | **Yes** | **Fully Wild:** You can change both the data and where you point. |
// | `T* const ptr` | **Yes** | **No** | **Locked Address:** You can change the data, but the pointer is stuck to one address. |
// | `const T* ptr` | **No** | **Yes** | **Read-only Data:** You can move the pointer, but you can't touch the data. |
// | `const T* const ptr` | **No** | **No** | **Total Lockdown:** Everything is read-only and fixed in place. |
//
// ---
//
// ### Key Concepts for Your Notes
//
// * **Read-from-Right Rule:** To understand any pointer in C++, read the declaration from right to left:
// * `T* const`  "Constant Pointer to T" (Address is fixed).
// * `const T*`  "Pointer to Constant T" (Data is fixed).
//
//
// * **The "Injection" Context:** While you can use any of these in your general C++ code, the compiler specifically chooses the **fixed address** versions (`* const`) for class members to ensure an object never loses its memory identity during a function call.
// * **Memory Safety:** High-level engineering uses these `const` qualifiers to prevent "accidental mutation"—making sure a function that is only supposed to *view* data doesn't accidentally *overwrite* it.
//

//sttic functions are class-level functions not object - level. they haven got and this pointer injection.

class PhoneBook
{
	private:
		
		Contact			_contacts[8];
		int				_totalAddedCount;
		static const	std::string _intro_banner;
		static const	std::string _outro_banner;
		std::string		_getAnswer(const std::string question, const std::string err) const;
		void			_printFormattedCell(const std::string content) const; 
		void			_displayContactList() const;
		bool			_isNumeric(const std::string &str) const;
		static volatile __sig_atomic_t _signalReceived;

	public:

		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContacts();

		//static member functions can only access static private variables.
		//you can define this functions outside of the class too.
		//this functions got no *this pointers.
		static void signalHandler(int signum);
		static bool shouldExit();
};
#endif
