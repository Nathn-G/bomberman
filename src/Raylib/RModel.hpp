/*
** EPITECH PROJECT, 2022
** RModel
** File description:
** RModel
*/

#ifndef __RMODEL_HPP__
    #define __RMODEL_HPP__

    #include <iostream>
    #include <memory>

    #include "raylib.h"
    #include "RTexture.hpp"

class RModel {
    public:
        RModel(std::string path);
        RModel(std::string pathModel, std::string pathTexture);
        RModel(std::string pathModel, std::string pathTexture, std::string pathAnimation);
        ~RModel();

        Model getModel();
        void loadTexture(RTexture texture);
        void loadTexture(std::string path);

        void loadAnimation(std::string path);
        void loadAnimation(ModelAnimation *animation);

    private:
        Model _model;
        ModelAnimation *_animation;
        unsigned int _animcount;
};

#endif /* !__RMODEL_HPP__ */
