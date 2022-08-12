/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Core
*/

#ifndef TOOLS_HPP_

    #define TOOLS_HPP_
    #include "../Raylib/Raylib.hpp"
    #include "../Raylib/RTexture.hpp"
    #include "../Raylib/RMusic.hpp"
    #include "../Utils.hpp"
    #include <iostream>
    #include "Sprite.hpp"
    #include "AnimatedSprite.hpp"
    #include "Text.hpp"
    #include "Cam.hpp"
    #include "MusicP.hpp"
    #include "MyFont.hpp"
    #include "Model3D.hpp"
    #include "KeyEvent.hpp"
    #include <map>
    #include <vector>
    #include <algorithm>

class Tools {
    public:
        Tools();
        ~Tools();
        void display(CoreScreen screen, Camera3D camera);
        void setLayer();
        void loadFont(std::string fontPath, std::string name);

        std::shared_ptr<Sprite> newSprite(std::string path, int layer = 0, int x = 0, int y = 0);
        std::shared_ptr<AnimatedSprite> newAnimatedSprite(std::string path, int layer = 0, int x = 0, int y = 0);
        std::shared_ptr<Text> newText(std::string text, std::string font, int x = 0, int y = 0, int layer = 0, int size = 20);
        std::shared_ptr<Model3D> newModel(CoreScreen screen, std::string pathModel, std::string pathTexture, Vector3 position = {0}, Vector3 scale = {0}, Vector3 rotationAxis = {0}, float rotationAngle = 0, int layer = 1);
        std::shared_ptr<Model3D> newModelWithAnimation(CoreScreen screen, std::string pathModel, std::string pathTexture, std::string pathAnimation, Vector3 position = {0}, Vector3 scale = {0}, Vector3 rotationAxis = {0}, float rotationAngle = 0, int layer = 1);
        std::shared_ptr<MusicP> newMusic(std::string path, bool loop = false);
        std::shared_ptr<RImage> getImagePath(std::string path);
        void deleteModel(int idx);
        void updateMusic();
        KeyEvent _keyEvent;

    private:
        int _widthWindow;
        int _heightWindow;
        std::map<std::string, std::shared_ptr<RImage>> _imageMap;
        std::vector<std::shared_ptr<Sprite>> _sprites;
        std::vector<std::shared_ptr<AnimatedSprite>> _animatedSprites;
        std::vector<std::shared_ptr<Text>> _texts;
        std::vector<std::shared_ptr<MusicP>> _musics;
        std::vector<std::shared_ptr<Model3D>> _models;
        std::vector<int> _layeurList;
        std::shared_ptr<Raylib> _raylib;
        std::map<std::string, std::shared_ptr<MyFont>> _font;
        std::map<std::string, std::shared_ptr<RModel>> _listModels;
};

#endif /* !CORE_HPP_ */