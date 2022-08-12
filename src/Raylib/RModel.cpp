/*
** EPITECH PROJECT, 2022
** RModel
** File description:
** RModel
*/

#include "RModel.hpp"

RModel::RModel(std::string path)
{
    this->_model = LoadModel(path.c_str());
    this->_animcount = 0;
}

RModel::RModel(std::string pathModel, std::string pathTexture)
{
    this->_model = LoadModel(pathModel.c_str());
    this->_animcount = 0;
    Texture texture = LoadTexture(pathTexture.c_str());
    SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
}

RModel::RModel(std::string pathModel, std::string pathTexture, std::string pathAnimation)
{
    this->_model = LoadModel(pathModel.c_str());
    this->_animcount = 0;
    Texture texture = LoadTexture(pathTexture.c_str());
    SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    ModelAnimation *animationPtr = LoadModelAnimations(pathAnimation.c_str(), &this->_animcount);
    this->_animation = animationPtr;
}

RModel::~RModel()
{
}

Model RModel::getModel()
{
    return (this->_model);
}

void RModel::loadTexture(std::string path)
{
    Texture texture = LoadTexture(path.c_str());
    SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
}

void RModel::loadTexture(RTexture texture)
{
    SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture.getTexture());
}

void RModel::loadAnimation(ModelAnimation *animation)
{
    this->_animation = animation;
}

void RModel::loadAnimation(std::string path)
{
    ModelAnimation *animationPtr = LoadModelAnimations(path.c_str(), &this->_animcount);
    this->_animation = animationPtr;
}
