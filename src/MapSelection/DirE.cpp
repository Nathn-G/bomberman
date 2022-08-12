/*
** EPITECH PROJECT, 2022
** DirE
** File description:
** DirE
*/

#include "DirE.hpp"

DirE::DirE(std::string name)
{
    this->dir = opendir(name.c_str());
}

DirE::~DirE()
{
    closedir(this->dir);
}

bool DirE::readdirE()
{
    this->dp = readdir(this->dir);
    if (this->dp == NULL)
        return (false);
    return (true);
}

std::string DirE::getName()
{
    return (std::string(this->dp->d_name));
}
