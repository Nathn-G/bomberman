/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** LoadSave
*/

#ifndef __LOADSAVE_HPP__
    #define __LOADSAVE_HPP__

    #include "../IModuleScreen.hpp"
    #include <sstream>
    #include <fstream>
    #include <filesystem>

class LoadSave : public IModuleScreen {
    public:
        LoadSave();
        ~LoadSave();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();
        void show_files();
        void loadFile(std::string filepath);
        void loadMap();

    private:
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
        Tools _tools;
        Raylib lib;
        std::string _map_string;

        std::map<std::string, std::shared_ptr<Text>> _texts;
};

#endif /* !LOADSAVE_HPP_ */
