/*
** EPITECH PROJECT, 2022
** indie
** File description:
** sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_
    #include "../Raylib/Raylib.hpp"
    #include "../Raylib/RTexture.hpp"
    #include "../Raylib/RMusic.hpp"
    #include "../Utils.hpp"
    #include <memory>

class Sprite {
    public:
        Sprite(std::shared_ptr<Raylib> raylib, std::shared_ptr<RImage> image, int layer, int x, int y);
        ~Sprite();
        void draw();
        void Resize(int w, int h);
        void setX(int x);
        void setY(int y);

        int getX() {return _x;};
        int getY() {return _y;};

        int getWidth() {return _width;};
        int getHeight() {return _height;};

        // var
        int _layer;
        Color _color;
        bool _display;

    protected:
        std::shared_ptr<RTexture> _texture;
        int _x;
        int _y;
        int _width;
        int _height;
        std::shared_ptr<Raylib> _raylib;
        std::shared_ptr<RImage> _image;

    private:
};


#endif /* !SPRITE_HPP_ */
