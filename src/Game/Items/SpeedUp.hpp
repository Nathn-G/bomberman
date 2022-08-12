/*
** EPITECH PROJECT, 2022
** SpeedUp
** File description:
** SpeedUp
*/

#ifndef __SPEEDUP_HPP__
    #define __SPEEDUP_HPP__

    #include "Item.hpp"
    #include <ctime>

class SpeedUp : public Item {
    public:
        SpeedUp(float x, float y, std::shared_ptr<Tools>, CoreScreen screen);
        ~SpeedUp();
        static void explose(std::shared_ptr<bool> explode);
        std::shared_ptr<bool> explode;
        std::thread time;
        void pure() override;

    protected:
    private:
};

#endif /* !__SPEEDUP_HPP__ */
