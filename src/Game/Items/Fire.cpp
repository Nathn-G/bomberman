/*
** EPITECH PROJECT, 2022
** Fire
** File description:
** Fire
*/

#include "Fire.hpp"

Fire::Fire(float x, float y, std::shared_ptr<Tools> tools, CoreScreen screen)
{
    this->explode = std::make_shared<bool>(false);
    this->time = std::thread(this->explose, this->explode);
    this->model = tools->newModel(
        screen,
        "../assets/Fire/fire.glb", "../assets/Fire/fire.glb",
        {static_cast<float>(x), .0f, static_cast<float>(y)},
        {.6f, .6f, .6f}, {.0f, -2.5f, 0.0f},
        -90.0f
    );
    this->scaled = false;
}

Fire::~Fire()
{
    this->time.join();

}

void Fire::pure()
{
}

void Fire::explose(std::shared_ptr<bool> explode)
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 1500 && *explode.get() != true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    *explode = true;
}
