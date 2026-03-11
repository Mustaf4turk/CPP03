/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:04:46 by rakman            #+#    #+#             */
/*   Updated: 2026/02/08 15:07:01 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <sstream>

bool checkFileAccess(const std::string &filename);
int validateArguments(int argc, char **argv);
std::string fileToString(const std::string &filename);
std::string findandReplace(const std::string &input, const std::string &to_find, const std::string &to_replace_with);

#endif
