/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findandReplace.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:05:42 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 17:29:22 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string fileToString(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return (buffer.str());
}

std::string findandReplace(const std::string &input, const std::string &to_find, const std::string &to_replace_with)
{
    std::string result = input;
    size_t current_position = 0;
    size_t found_position;

    while (true)
    {
        found_position = result.find(to_find, current_position);
        if (found_position == std::string::npos)
            break ;

        result.erase(found_position, to_find.length());
        result.insert(found_position, to_replace_with);
        current_position = found_position + to_replace_with.length();
    }
    return (result);
}
