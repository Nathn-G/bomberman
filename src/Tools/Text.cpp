/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(std::shared_ptr<Raylib> raylib, std::string text, std::shared_ptr<MyFont> font, int layer, int size, int x, int y)
{
    this->_raylib = raylib;
    this->_text = text;
    this->_layer = layer;
    this->_size = size;
    this->setX(x);
    this->setY(y);
    this->setCenterTextX();
    this->_centerText = false;
    this->_font = font;
    this->screen = screen;
}

Text::~Text()
{
}

void Text::setText(std::string text)
{
    this->_text = text;
    this->setCenterTextX();
}

void Text::draw()
{
    int place_x = this->_raylib.get()->GetPlacementWidthE(this->_x);
    int place_y = this->_raylib.get()->GetPlacementHeightE(this->_y);
    int font_size = this->_raylib.get()->GetScreenWidthE() / (100 - this->_size);

    if (!this->_centerText)
        this->_raylib.get()->DrawTextExE(GetFontDefault(), this->_text, place_x, place_y, font_size, this->_size / 10, BLACK);
    else {
        this->setCenterTextX();
        this->_raylib.get()->DrawTextExE(GetFontDefault(), this->_text, this->_centerTextX, place_y, font_size, this->_size / 10, BLACK);
    }
}

void Text::setCenterTextX()
{
    int res = this->_raylib.get()->MeasureTextExE(GetFontDefault(), this->_text, this->_raylib.get()->GetScreenWidthE() / (100 - this->_size), this->_size / 10);
    this->_centerTextX = this->_raylib.get()->GetPlacementWidthE(this->_x) - (res / 2);
}

void Text::setX(int x)
{
    this->_x = this->_raylib.get()->GetPlacementWidthE(x);
    this->setCenterTextX();
}

void Text::setY(int y)
{
    this->_y = this->_raylib.get()->GetPlacementHeightE(y);
}