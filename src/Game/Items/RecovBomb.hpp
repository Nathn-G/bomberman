/*
** EPITECH PROJECT, 2022
** RecovBomb
** File description:
** RecovBomb
*/

#ifndef __RECOVBOMB_HPP__
    #define __RECOVBOMB_HPP__

    #include "Item.hpp"
    #include <ctime>

class RecovBomb : public Item {
    public:
        RecovBomb(float x, float y, std::shared_ptr<Tools>, CoreScreen screen);
        ~RecovBomb();
        static void explose(std::shared_ptr<bool> explode);
        std::shared_ptr<bool> explode;
        std::thread time;
        void pure() override;

    protected:
    private:
};

#endif /* !__RECOVBOMB_HPP__ */
