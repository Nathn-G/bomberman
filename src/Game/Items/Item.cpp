/*
** EPITECH PROJECT, 2022
** Item
** File description:
** Item
*/

#include "Item.hpp"

Item::Item()
{
}

Item::~Item()
{
}

void Item::setIndex(int idx)
{
    this->_index = idx;
}

int Item::getIndex()
{
    return (this->_index);
}