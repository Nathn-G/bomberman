/*
** EPITECH PROJECT, 2022
** RecovLife
** File description:
** RecovLife
*/

#ifndef __RECOVLIFE_HPP__
    #define __RECOVLIFE_HPP__

    #include "Item.hpp"
    #include <ctime>

class RecovLife : public Item {
    public:
        RecovLife(float x, float y, std::shared_ptr<Tools>, CoreScreen screen);
        ~RecovLife();
        static void explose(std::shared_ptr<bool> explode);
        std::shared_ptr<bool> explode;
        std::thread time;
        void pure() override;

    protected:
    private:
};

#endif /* !RecovLife */
