/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** How to play
*/

#ifndef __HOW_TO_PLAY_HPP__
    #define __HOW_TO_PLAY_HPP__

    #include "../IModuleScreen.hpp"

class HowToPlay : public IModuleScreen {
    public:
        HowToPlay();
        ~HowToPlay();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();

    private:
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;
        Tools _tools;
        Raylib lib;

        std::map<std::string, std::shared_ptr<Text>> _texts;
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
};

#endif /* !HOW_TO_PLAY_HPP_ */
