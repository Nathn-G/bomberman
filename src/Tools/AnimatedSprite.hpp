/*
** EPITECH PROJECT, 2022
** indie
** File description:
** AnimatedSprite
*/

#ifndef ANIMATEDSPRITE_HPP_
    #define ANIMATEDSPRITE_HPP_

    #include "Sprite.hpp"
    #include "Pclock.hpp"

class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite(std::shared_ptr<Raylib> raylib, std::shared_ptr<RImage> image, int layer, int x, int y) : _clockAnim(0.05), Sprite(raylib, image, layer, x, y) {};
        void setAnimation(int width, int height, int column, float clock);
        void draw();
        void setRow(int row);
        void animate(void);
        ~AnimatedSprite();

    protected:
        Rectangle _rectangle;
        Pclock _clockAnim;
    private:
        int _column;
        bool _animIsSet;
};

#endif /* !ANIMATEDSPRITE_HPP_ */
