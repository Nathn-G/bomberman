/*
** EPITECH PROJECT, 2022
** RecovLife
** File description:
** RecovLife
*/

#include "RecovLife.hpp"

RecovLife::RecovLife(float x, float y, std::shared_ptr<Tools> tools, CoreScreen screen)
{
    this->explode = std::make_shared<bool>(false);
    this->time = std::thread(this->explose, this->explode);
    model = tools.get()->newModel(
        screen,
        "../assets/Bonus/bomberman-bonus/source/bonus/bonus.fbx", "../assets/Bonus/bomberman-bonus/source/bonus/textures/life.png",
        {x, .0f, y},
        {.6f, .6f, .6f}, {.0f, -2.5f, 0.0f},
        -90.0f
    );
}

RecovLife::~RecovLife()
{
    this->time.join();
}

void RecovLife::pure()
{
}

void RecovLife::explose(std::shared_ptr<bool> explode)
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 10000 && *explode.get() != true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    *explode = true;
}
