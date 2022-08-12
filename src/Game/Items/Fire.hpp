/*
** EPITECH PROJECT, 2022
** Fire
** File description:
** Fire
*/

#ifndef __FIRE_HPP__
    #define __FIRE_HPP__

    #include "Item.hpp"
    #include <ctime>

class Fire : public Item {
    public:
        Fire(float x, float y, std::shared_ptr<Tools> tools, CoreScreen screen);
        ~Fire();
        static void explose(std::shared_ptr<bool> explode);
        std::shared_ptr<bool> explode;
        std::thread time;
        void pure() override;
        bool scaled;

    protected:
    private:
};

#endif /* !__FIRE_HPP__ */
