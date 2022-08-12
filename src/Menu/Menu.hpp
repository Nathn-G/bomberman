/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Menu
*/

#ifndef __MENU_HPP__
    #define __MENU_HPP__

    #define MAX_PLAYERS 4
    #define MAX_PARTICLES 200

    #include "../IModuleScreen.hpp"
    #include "../Raylib/RSound.hpp"

class Menu : public IModuleScreen {
    public:
        Menu();
        ~Menu();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();
        void windowResized();

    private:
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;

        std::map<std::string, std::shared_ptr<Text>> _texts;
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
        std::map<std::string, std::shared_ptr<RSound>> _sounds;
        Tools _tools;
        Raylib lib;

        float _scrollingBack;
        float _scrollingMid;
        float _scrollingFore;

        std::vector<Particles> particles;
};

#endif /* !MENU_HPP_ */
