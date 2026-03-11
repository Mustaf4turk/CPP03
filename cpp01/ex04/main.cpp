/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:00:41 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 17:29:45 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{  
    if (validateArguments(argc, argv) != 0)
        return (1);

    std::string stringbuffer = fileToString(argv[1]);
    if (stringbuffer.empty() == true)
    {
        std::cerr << "\033[1;31mError: File " << argv[1] << " is empty.\033[0m" << std::endl;
        return (1);
    }
    std::string replacedString = findandReplace(stringbuffer, argv[2], argv[3]);
    std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
    outputFile << replacedString;
    outputFile.close();

    return (0);
}
