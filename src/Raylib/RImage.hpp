/*
** EPITECH PROJECT, 2022
** RImage
** File description:
** RImage
*/

#ifndef __RIMAGA_HPP__
    #define __RIMAGA_HPP__

    #include <iostream>
    #include "raylib.h"

class RImage {
    public:
        RImage(std::string path);
        ~RImage();
        Image getImage();
        void ImageResizeE(int width, int height);

    protected:
    private:
        Image image;
        Image image_initial;
        bool _isResize;
};

#endif /* !__RIMAGA_HPP__ */