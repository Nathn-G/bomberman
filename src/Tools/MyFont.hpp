/*
** EPITECH PROJECT, 2022
** indie
** File description:
** MyFont
*/

#ifndef MYFONT_HPP_
    #define MYFONT_HPP_

    #include "../Raylib/Raylib.hpp"
    #include "../Raylib/RTexture.hpp"
    #include "../Raylib/RMusic.hpp"
    #include <iostream>
    #include <map>
    #include <vector>
    #include <algorithm>
    #include <memory>

class MyFont {
    public:
        MyFont(std::shared_ptr<Raylib> raylib, std::string fontPath){this->_font = raylib.get()->LoadFontE(fontPath);};
        ~MyFont(){};
        Font _font;
    private:
};

#endif /* !MYFONT_HPP_ */
