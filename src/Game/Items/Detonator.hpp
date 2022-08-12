/*
** EPITECH PROJECT, 2022
** __DETONATOR_HPP__
** File description:
** Detonator
*/

#ifndef __DETONATOR_HPP__
    #define __DETONATOR_HPP__

    #include "Item.hpp"
    #include <ctime>

class Detonator : public Item {
    public:
        Detonator(float x, float y, std::shared_ptr<Tools>, CoreScreen screen);
        ~Detonator();
        static void explose(std::shared_ptr<bool> explode);
        std::shared_ptr<bool> explode;
        std::thread time;
        void pure() override;

    protected:
    private:
};

#endif /* !__DETONATOR_HPP__ */
