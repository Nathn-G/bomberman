/*
** EPITECH PROJECT, 2022
** indie
** File description:
** AnimatedSprite
*/

#include "AnimatedSprite.hpp"

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::setAnimation(int width, int height, int column, float clock)
{
    this->_rectangle.x = 0;
    this->_rectangle.y = 0;
    this->_rectangle.width = width;
    this->_rectangle.height = height;
    this->_column = column;
    this->_clockAnim.setRefreshTime(clock);
}

void AnimatedSprite::animate(void)
{
    if (this->_column <= this->_rectangle.x / this->_rectangle.width) {
        this->_rectangle.x = 0;
    } else {
        this->_rectangle.x += this->_rectangle.width;
    }
}

void AnimatedSprite::setRow(int row)
{
    this->_rectangle.y = row * this->_rectangle.height;
}

void AnimatedSprite::draw()
{
    int x = 0;
    int y = 0;

    if (!this->_animIsSet) {
        return;
    }
    if (this->_clockAnim.check()) {
        this->animate();
    }
    if (this->_display) {
        x = this->_raylib.get()->GetPlacementWidthE(this->_x);
        y = this->_raylib.get()->GetPlacementHeightE(this->_y);
        Vector2 pos = {static_cast<float>(x), static_cast<float>(y)};
        this->_raylib.get()->DrawTextureRecE(*this->_texture.get(), this->_rectangle, pos, this->_color);
    }
}