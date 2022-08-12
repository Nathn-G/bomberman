/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#ifndef __BOMB_HPP__
    #define __BOMB_HPP__

    #include "Item.hpp"
    #include <ctime>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> clockTime;

class Bomb : public Item {
    public:
        Bomb();
        ~Bomb();
        static void explose(std::shared_ptr<bool> explode, std::shared_ptr<clockTime> timeStart);
        void pure() override;
        std::string getSecondAI();

        std::shared_ptr<bool> explode;
        std::thread time;
        std::shared_ptr<clockTime> timeStart;

    protected:
    private:
};

#endif /* !__BOMB_HPP__ */