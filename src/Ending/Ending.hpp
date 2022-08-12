/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Ending
*/

#ifndef __ENDING_HPP__
    #define __ENDING_HPP__
    #define MAX_PARTICLES 200

    #include "../IModuleScreen.hpp"

class Ending : public IModuleScreen {
    public:
        Ending();
        ~Ending();

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
        std::vector<Particles> particles;
};

#endif /* !ENDING_HPP_ */
