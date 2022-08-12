/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_
    #include "../Raylib/Raylib.hpp"
    #include "../Raylib/RTexture.hpp"
    #include "../Raylib/RMusic.hpp"
    #include "../Utils.hpp"
    #include "MyFont.hpp"
    #include <memory>

class Text {
    public:
        Text(std::shared_ptr<Raylib> raylib, std::string text, std::shared_ptr<MyFont> font, int layer, int size, int x, int y);
        ~Text();

        void draw();
        void setX(int x);
        void setY(int y);
        void setText(std::string text);
        void setCenterTextX();

        // var
        int _layer;
        int _size;
        Color _color;
        bool _centerText;
        CoreScreen screen;

    private:
        std::shared_ptr<Raylib> _raylib;
        std::shared_ptr<MyFont> _font;
        int _x;
        int _y;
        int _centerTextX;
        int _spacing;
        std::string _text;
};

#endif /* !TEXT_HPP_ */
