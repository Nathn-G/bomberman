/*
** EPITECH PROJECT, 2022
** Model3D
** File description:
** Model3D
*/

#include "Model3D.hpp"

Model3D::Model3D(std::shared_ptr<Raylib> raylib, CoreScreen screen, std::shared_ptr<RModel> model, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle, int layer)
{
    this->_model = model;
    this->_raylib = raylib;
    this->_screen = screen;
    this->_position = position;
    this->_scale = scale;
    this->_rotationAxis = rotationAxis;
    this->_rotationAngle = rotationAngle;
    this->_hasAnimation = false;
    this->_indexAnimation = 1;
    this->_loopAnimation = true;
    this->_display = true;
    this->_layer = layer;
    this->_color = WHITE;
    this->_colorStr = "WHITE";
}

Model3D::Model3D(std::shared_ptr<Raylib> raylib, CoreScreen screen, std::string pathModel, std::string pathTexture, std::string pathAnimation, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle, int layer)
{
    this->_model = std::make_shared<RModel>(pathModel, pathTexture, pathAnimation);
    this->_raylib = raylib;
    this->_screen = screen;
    this->_position = position;
    this->_scale = scale;
    this->_rotationAxis = rotationAxis;
    this->_rotationAngle = rotationAngle;
    this->_animations = LoadModelAnimations("../assets/player/player.iqm", &this->_animationsCount);
    this->_hasAnimation = true;
    this->_indexAnimation = 1;
    this->_animFrameCounter = 0;
    this->_loopAnimation = true;
    this->_display = true;
    this->_layer = layer;
    this->_color = WHITE;
    this->_colorStr = "WHITE";
}

void Model3D::draw()
{
    DrawModelEx(this->_model->getModel(), this->_position, this->_rotationAxis, this->_rotationAngle, this->_scale, this->_color);
}

void Model3D::setX(float x)
{
    this->_position.x = x;
}

void Model3D::setY(float y)
{
    this->_position.y = y;
}

void Model3D::setZ(float z)
{
    this->_position.z = z;
}

void Model3D::setPosition(float x, float y, float z)
{
    this->_position.x = x;
    this->_position.y = y;
    this->_position.z = z;
}

void Model3D::setScaleX(float x)
{
    this->_scale.x = x;
}

void Model3D::setScaleY(float y)
{
    this->_scale.y = y;
}

void Model3D::setScaleZ(float z)
{
    this->_scale.z = z;
}void getPosition();

void Model3D::setScale(float x, float y, float z)
{
    this->_scale.x = x;
    this->_scale.y = y;
    this->_scale.z = z;
}

void Model3D::setRotationAxisX(float x)
{
    this->_rotationAxis.x = x;
}

void Model3D::setRotationAxisY(float y)
{
    this->_rotationAxis.y = y;
}

void Model3D::setRotationAxisZ(float z)
{
    this->_rotationAxis.z = z;
}

void Model3D::setRotationAxis(float x, float y, float z)
{
    this->_rotationAxis.x = x;
    this->_rotationAxis.y = y;
    this->_rotationAxis.z = z;
}

void Model3D::setRotationAngle(float angle)
{
    this->_rotationAngle = angle;
}

Vector3 Model3D::getPosition()
{
    return this->_position;
}

bool Model3D::hasAnimation()
{
    return this->_hasAnimation;
}

void Model3D::updateAnimation()
{
    this->_animFrameCounter++;

    if (this->_animFrameCounter < this->_animations[this->_indexAnimation].frameCount)
        UpdateModelAnimation(this->_model.get()->getModel(), this->_animations[this->_indexAnimation], this->_animFrameCounter);
    if (this->_animFrameCounter >= this->_animations[this->_indexAnimation].frameCount && this->_loopAnimation)
        this->_animFrameCounter = 0;
}

void Model3D::resetAnimation()
{
    this->_animFrameCounter = 0;
}

void Model3D::changeAnimation(int indexAnimation)
{
    this->_indexAnimation = indexAnimation;
}

float Model3D::getRotationAngle()
{
    return (this->_rotationAngle);
}

void Model3D::setIndex(int idx)
{
    this->_index = idx;
}

int Model3D::getIndex()
{
    return (this->_index);
}

bool Model3D::isLastAnimation()
{
    if (this->_animFrameCounter > this->_animations[this->_indexAnimation].frameCount && !this->_loopAnimation) {
        return true;
    }
    return false;
}