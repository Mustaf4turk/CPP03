/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateArguments.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:03:13 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 17:29:32 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

bool checkFileAccess(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    return (file.is_open());
}

int validateArguments(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "\033[1;31mInvalid number of arguments.\033[0m" << std::endl;
        std::cerr << "\033[1;31mUsage: ./replace <filename> <to_find> <to_replace_with>\033[0m" << std::endl;
        return (1);
    }
    if (std::string(argv[2]).empty() == true)
    {
        std::cerr << "\033[1;31mThe string to be replaced (to_find) cannot be empty.\033[0m" << std::endl;
        return (1);
    }
    if (checkFileAccess(argv[1]) == false)
    {
        std::cerr << "\033[1;31mError: Cannot access file " << argv[1] << ".\033[0m" << std::endl;
        return (1);
    }
    return (0);
}
