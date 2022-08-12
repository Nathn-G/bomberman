/*
** EPITECH PROJECT, 2022
** Detonator
** File description:
** Detonator
*/

#include "Detonator.hpp"

Detonator::Detonator(float x, float y, std::shared_ptr<Tools> tools, CoreScreen screen)
{
    this->explode = std::make_shared<bool>(false);
    this->time = std::thread(this->explose, this->explode);
    this->model = tools->newModel(
        screen,
        "../assets/Bonus/bomberman-bonus/source/bonus/bonus.fbx", "../assets/Bonus/bomberman-bonus/source/bonus/textures/detonator.png",
        {static_cast<float>(x), .0f, static_cast<float>(y)},
        {.6f, .6f, .6f}, {.0f, -2.5f, 0.0f},
        -90.0f
    );
}

Detonator::~Detonator()
{
    this->time.join();
}

void Detonator::pure()
{
}

void Detonator::explose(std::shared_ptr<bool> explode)
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 10000 && *explode.get() != true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    *explode = true;
}