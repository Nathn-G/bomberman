/*
** EPITECH PROJECT, 2022
** IItem
** File description:
** IItem
*/

#ifndef __IITEM_HPP__
#define __IITEM_HPP__

class IItem {
    public:
        virtual ~IItem() = default;
        virtual void setIndex(int idx) = 0;
        virtual int getIndex() = 0;
};

#endif /* !__IITEM_HPP__ */
