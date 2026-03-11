/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:21:05 by rakman            #+#    #+#             */
/*   Updated: 2025/11/08 16:29:14 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//C++ (cout) ➜ C++ Stream Buffer ➜ C (stdout) ➜ OS Kernel (write) ➜ Screen


// https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170
//
// The operator keyword declares a function specifying what operator-symbol means when applied to instances of a class. This gives the operator more than one meaning, or "overloads" it. The compiler distinguishes between the different meanings of an operator by examining the types of its operands.
//
// You can redefine the function of most built-in operators globally or on a class-by-class basis. Overloaded operators are implemented as functions.
// The name of an overloaded operator is operator x, where x is the operator as it appears in the following table. For example, to overload the addition operator, you define a function called operator+. Similarly, to overload the addition/assignment operator, +=, define a function called operator+=.
//
// namespace std {
//     class ostream {
//     public:
//         // 1. Member function for Function Pointers (like std::endl)
//         // This allows the syntax: ostream.operator<<(std::endl)
//         ostream& operator<<(ostream& (*pf)(ostream&)) {
//             return pf(*this); 
//         }
//         // Other member overloads for primitive types
//         ostream& operator<<(int n);
//         ostream& operator<<(double f);
//     };
//     class istream {
//     };
//     class iostream : public istream, public ostream {
//     };
//
//
//     // 2. Non-member functions for C-Strings and Characters
//     // This allows the syntax: operator<<(std::cerr, "string")
//     ostream& operator<<(ostream& out, const char* s);
//     ostream& operator<<(ostream& out, char c);
//     // External object definitions
//     extern ostream cout;
//     extern ostream cerr;
//     extern ostream clog;
//     extern istream cin;
//
//
//     // The Manipulator (std::endl)
//     ostream& endl(ostream& os) {
//         os.put('\n');
//         os.flush();
//         return os;
//     }
// } ***new delete overload edilebilir.

#include <iostream>

int megaphone(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 0)
		return (1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			/*
			* "::" is the Scope Resolution Operator, used to access identifiers 
			* defined within specific namespaces or classes (e.g., the 'std' namespace).
			* * In C++, 'operator<<' is a function name. Unlike a C compiler, the C++ compiler 
			* supports "Function Overloading." When this function is called, the compiler 
			* performs "Overload Resolution" to find the best match based on the argument types.
			*
			* Process:
			* 1. The compiler identifies the types of the arguments: 'std::ostream' (cout) and 'char'.
			* 2. It searches for a matching function signature, such as:
			* std::operator<<(std::ostream&, char)
			* 3. It uses ADL (Argument-Dependent Lookup) to find the operator in the 
			* namespace associated with the arguments (std).
			* * Note: If multiple candidates match equally well, the compiler throws an 
			* "ambiguity error." The 'static_cast<char>' is essential here because 
			* 'std::toupper' returns an 'int'. Without the cast, the compiler would 
			* call the 'int' overload, printing the ASCII value instead of the character.
			*/
			operator<<(std::cout, static_cast<unsigned char>(std::toupper(argv[i][j])));
			j++;
		}
		i++;
	}
	//add next line and flush the buffer. std::endl is a function pointer , manipulator
	std::cout.operator<<(std::endl);
	return (0);
}

int main(int argc, char **argv) 
{
	if (argc == 1)
	{   
		std::string errmesage;
		errmesage =	"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		
		std::ostream &ostreamref = operator<<(std::cerr, errmesage);
		ostreamref.operator<<(std::endl);
	}
	else 
	{	
		int ret;

		ret = megaphone(argc, argv);
		if (ret != 0)
		{
			operator<<(std::cerr, "MEGAERROR\n");
			return (1);
		}
	}
	return (0);
}

