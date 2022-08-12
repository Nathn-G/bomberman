/*
** EPITECH PROJECT, 2022
** Particles
** File description:
** Particles
*/

#include "Particles.hpp"

Particles::Particles()
{
    this->velocity = {lib.GetRandomValueE(2, 7) * .05f, lib.GetRandomValueE(10, 30) * .05f};
    this->size = lib.GetRandomValueE(2, 4) * 0.9f;
    this->position = {lib.GetRandomValueE(0, lib.GetScreenWidthE()) * 1.0f, lib.GetRandomValueE(0, -20) * 1.0f};
}

Particles::~Particles()
{
}

void Particles::Update()
{
    std::get<0>(this->position) = std::get<0>(this->position) + std::get<0>(this->velocity);
    std::get<1>(this->position) = std::get<1>(this->position) + std::get<1>(this->velocity) / 2;
    if (lib.GetRandomValueE(0, 150) < 2)
        this->size -= 1;
    if (this->size < 0 || std::get<0>(this->position) > lib.GetScreenWidthE() || std::get<1>(this->position) > lib.GetScreenHeightE()) {
        this->velocity = {lib.GetRandomValueE(2, 7) * .05f, lib.GetRandomValueE(10, 30) * .05f};
        this->size = lib.GetRandomValueE(2, 7) * 0.9f;
        this->position = {lib.GetRandomValueE(0, lib.GetScreenWidthE()) * 1.0f, lib.GetRandomValueE(0, -20) * 1.0f};
    }
}

void Particles::Draw()
{
    lib.DrawCircleE(std::get<0>(this->position), std::get<1>(this->position), this->size, RED);
}

void Particles::Draw_yellow()
{
    lib.DrawCircleE(std::get<0>(this->position), std::get<1>(this->position), this->size, YELLOW);
}

void Particles::Draw_green()
{
    lib.DrawCircleE(std::get<0>(this->position), std::get<1>(this->position), this->size, GREEN);
}

void Particles::Draw_blue()
{
    lib.DrawCircleE(std::get<0>(this->position), std::get<1>(this->position), this->size, BLUE);
}

