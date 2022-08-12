/*
** EPITECH PROJECT, 2022
** Particles
** File description:
** Particles
*/

#ifndef __PARTICLES_HPP__
    #define __PARTICLES_HPP__

    #include <tuple>
    #include "raylib.h"
    #include "../../Raylib/Raylib.hpp"

class Particles {
    public:
        Particles();
        ~Particles();
        void Update();
        void Draw();
        void Draw_yellow();
        void Draw_blue();
        void Draw_green();

    protected:
    private:
        Raylib lib;
        std::tuple<float, float> position;
        std::tuple<float, float> velocity;
        float size;
};

#endif /* !__PARTICLES_HPP__ */
