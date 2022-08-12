/*
** EPITECH PROJECT, 2022
** RTexture
** File description:
** RTexture
*/

#ifndef __RTEXTURE_HPP__
    #define __RTEXTURE_HPP__

    #include "raylib.h"

class RTexture {
    public:
        RTexture(Image image);
        ~RTexture();
        void ChangeTexture(Image image);
        Texture2D getTexture();

    protected:
    private:
        Texture2D texture;
};

#endif /* !__RTEXTURE_HPP__ */
