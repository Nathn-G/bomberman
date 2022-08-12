/*
** EPITECH PROJECT, 2022
** Utils
** File description:
** Utils
*/

#include "Utils.hpp"

std::vector<std::string> Utils::split(std::string str, char delim)
{
    std::vector<std::string> array;
    size_t end = 0;
    size_t start = str.find_first_not_of(delim, end);

    while (start != std::string::npos) {
        end = str.find(delim, start);
        array.push_back(str.substr(start, end - start));
        start = str.find_first_not_of(delim, end);
    }
    return array;
}