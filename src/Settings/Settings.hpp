/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Settings
*/

#ifndef __SETTINGS_HPP__
    #define __SETTINGS_HPP__

    #include "../IModuleScreen.hpp"

class Settings : public IModuleScreen {
    public:
        Settings();
        ~Settings();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();
        void undisplay();
        void update_screen();
        bool is_key_clicked();
        void update_texts();
        bool settings_key_free(int key);

    private:
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;
        Tools _tools;
        Raylib lib;
        int _players_index;

        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
        std::map<std::string, std::shared_ptr<Text>> _texts;
        std::map<int, std::string> _keys;
};

#endif /* !SETTINGS_HPP_ */
