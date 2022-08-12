/*
** EPITECH PROJECT, 2022
** indie studio
** File description:
** Game
*/

#ifndef __GAME_HPP__
    #define __GAME_HPP__

    #include "../IModuleScreen.hpp"
    #include "../Raylib/RSound.hpp"
    #include "Items/Fire.hpp"
    #include "Characters/Player.hpp"
    #include "Items/Bomb.hpp"
    #include "Items/SpeedUp.hpp"
    #include "Items/Detonator.hpp"
    #include "Items/RecovBomb.hpp"
    #include "Items/RecovLife.hpp"

class Game : public IModuleScreen {
    public:
        Game();
        ~Game();

        void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera);
        void destroy();
        void update();
        void display();
        void handleEvent();
        bool addFire(int x, int y, int map_x, int map_z);

        void initMap();
        void initMapWalls();
        void initMapFloor();

        void windowResized();
        void closeAllObjects();
        int _frameCounter;

    private:
        std::shared_ptr<Tools> _tools;
        Raylib lib;
        std::shared_ptr<CoreInfo> _core;
        std::shared_ptr<Cam> _camera;
        std::map<std::string, std::shared_ptr<RSound>> _sounds;

        // std::vector<std::shared_ptr<Player>> _players;

        std::map<std::string, std::shared_ptr<Text>> _texts;
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
        std::vector<std::shared_ptr<Model3D>> _models;
        std::vector<std::shared_ptr<Model3D>> _destroyables;
        std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> _bombs;
        std::vector<std::shared_ptr<Fire>> _fires;
        std::vector<std::shared_ptr<SpeedUp>> _speeds;
        std::vector<std::shared_ptr<Detonator>> _detonators;
        std::vector<std::shared_ptr<RecovBomb>> _recovBombs;
        std::vector<std::shared_ptr<RecovLife>> _recovLifes;
        Pclock _clock;
        Pclock _startIa;
        bool _iaActive;
};

#endif /* !__GAME_HPP__ */
