/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Pause
*/

#ifndef __PAUSE_HPP__
    #define __PAUSE_HPP__

    #include "../IModuleScreen.hpp"

class Pause : public IModuleScreen {
    public:
        Pause();
        ~Pause();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();
        void windowResized();

    private:
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;
        Tools _tools;
        int _settings_index;
        Raylib lib;

        std::map<std::string, std::shared_ptr<Text>> _texts;
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
};

#endif /* !PAUSE_HPP_ */
