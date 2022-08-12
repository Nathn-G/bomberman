/*
** EPITECH PROJECT, 2022
** RTexture
** File description:
** RTexture
*/

#include "RTexture.hpp"

RTexture::RTexture(Image image)
{
    this->texture = LoadTextureFromImage(image);
}

RTexture::~RTexture()
{
}

void RTexture::ChangeTexture(Image image)
{
    UnloadTexture(this->texture);
    this->texture = LoadTextureFromImage(image);
}

Texture2D RTexture::getTexture()
{
    return this->texture;
}
