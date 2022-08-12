/*
** EPITECH PROJECT, 2022
** Bomb
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb()
{
    this->explode = std::make_shared<bool>(false);
    this->timeStart = std::make_shared<clockTime>(std::chrono::high_resolution_clock::now());
    this->time = std::thread(this->explose, this->explode, this->timeStart);
}

Bomb::~Bomb()
{
    this->time.join();
}

void Bomb::pure()
{
}

std::string Bomb::getSecondAI()
{
    double remain = 4000 - std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - *timeStart.get()).count();

    if (remain > 3500)
        return "E";
    if (remain > 2500)
        return "D";
    if (remain > 1500)
        return "C";
    if (remain > 500)
        return "B";
    return "A";
}

void Bomb::explose(std::shared_ptr<bool> explode, std::shared_ptr<clockTime> timeStart)
{
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - *timeStart.get()).count() < 4000 && *explode.get() != true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    // std::cout << "bomb explode" << std::endl;
    *explode = true;
}