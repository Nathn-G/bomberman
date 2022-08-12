/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::shared_ptr<Raylib> raylib, std::shared_ptr<RImage> image, int layer, int x, int y)
{
    this->_image = image;
    this->_texture = std::make_shared<RTexture>(this->_image.get()->getImage());
    this->setX(x);
    this->setY(y);
    this->_width = _texture.get()->getTexture().width;
    this->_height = _texture.get()->getTexture().height;
    this->_layer = layer;
    this->_color = WHITE;
    this->_raylib = raylib;
    this->_display = true;
}

Sprite::~Sprite()
{
}

void Sprite::draw()
{
    int x = 0;
    int y = 0;

    if (this->_display) {
        x = this->_raylib.get()->GetPlacementWidthE(this->_x);
        y = this->_raylib.get()->GetPlacementHeightE(this->_y);
        this->_raylib.get()->DrawTextureE(*this->_texture.get(), x, y, this->_color);
    }
}

void Sprite::Resize(int w, int h)
{
    this->_image.get()->ImageResizeE(w, h);
    this->_texture.get()->ChangeTexture(this->_image.get()->getImage());
    this->_width = w;
    this->_height = h;
}

void Sprite::setX(int x)
{
    this->_x = this->_raylib.get()->GetPlacementWidthE(x);
}

void Sprite::setY(int y)
{
    this->_y = this->_raylib.get()->GetPlacementHeightE(y);
}
