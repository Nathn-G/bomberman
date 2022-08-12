/*
** EPITECH PROJECT, 2022
** Game
** File description:
** Game
*/

#ifndef __CORE_HPP__
    #define __CORE_HPP__

    #include "../Raylib/Raylib.hpp"
    #include "../Raylib/RTexture.hpp"
    #include "../Raylib/RSound.hpp"
    #include "../Raylib/RMusic.hpp"
    #include "../Utils.hpp"

    #include "../MapSelection/MapSelection.hpp"
    #include "../LoadSave/LoadSave.hpp"
    #include "../Menu/Menu.hpp"
    #include "../Pause/Pause.hpp"
    #include "../Settings/Settings.hpp"
    #include "../Game/Game.hpp"
    #include "../HowToPlay/HowToPlay.hpp"
    #include "../Ending/Ending.hpp"
    #include "../Tools/Tools.hpp"

    #include <vector>
    #include <sstream>
    #include <fstream>
    #include <iostream>
    #include <string>
    #include <regex>
    #include <chrono>
    #include <ctime>
    #include <iterator>
    #include <algorithm>

class Core {
    public:
        Core();
        ~Core();
        void init();

        void loop();
        void displayModuleScreen();

    private:
        std::shared_ptr<CoreInfo> _coreinfo;
        std::shared_ptr<Cam> _camera;
        MapSelection _mapSelection;
        LoadSave _loadSave;
        Menu _menu;
        Game _game;
        Pause _pause;
        Settings _settings;
        HowToPlay _howToPlay;
        Ending _ending;

        Tools _tools;
        Raylib lib;

        std::map<std::string, std::shared_ptr<RSound>> _sounds;
        
        bool start;
        bool showFPS;
        bool gameIsInit = false;
        bool gameIsEnd = false;
        bool testgame = false;

};

#endif
