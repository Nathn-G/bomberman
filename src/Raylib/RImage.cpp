/*
** EPITECH PROJECT, 2022
** RImage
** File description:
** RImage
*/

#include "RImage.hpp"

RImage::RImage(std::string path)
{
    this->image = LoadImage(path.c_str());
    this->image_initial = ImageCopy(this->image);
    this->_isResize = false;
}

RImage::~RImage()
{
    // UnloadImage(this->image);
}

Image RImage::getImage()
{
    return this->image;
}

void RImage::ImageResizeE(int width, int height)
{
    if (!_isResize) {
        ImageResize(&(this->image), width, height);
        this->_isResize = true;
    } else {
        UnloadImage(this->image);
        this->image = ImageCopy(this->image_initial);
        ImageResize(&(this->image), width, height);
    }
}
