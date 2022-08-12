/*
** EPITECH PROJECT, 2022
** indie studio
** File description:
** CoreInfo
*/

#ifndef __CORE_INFO_HPP__
    #define __CORE_INFO_HPP__

    #include "../Utils.hpp"
    #include "../Raylib/Raylib.hpp"
    #include "../Tools/Sprite.hpp"
    #include "../Game/Characters/Player.hpp"
    #include "../AError.hpp"
    #include <filesystem>
    #include <fstream>
    #include <regex>
    #include <string>

typedef struct box_s {
    int width;
    int height;
    int x;
    int y;
    Color color;
} box_t;

typedef struct map_s {
    int width;
    int height;
    int nb_player;
    bool valid = true;
    std::string data;
    std::vector<std::string> data_players;
    std::vector<box_t> boxes;
} map_t;

class CoreInfo {
    public:
        CoreInfo();
        ~CoreInfo();

        void changeScreen(CoreScreen coreScreen);
        CoreScreen getCurrentScreen();
        CoreScreen getOldScreen();
        void saveGame();
        void update_controllers();
        
        //var
        bool gameRunning = true;
        int _map_to_display = 0;
        int winner;
        std::vector<map_t> maps;
        std::vector<map_t> saves;
        std::vector<std::string> _map_split;
        std::vector<std::string> _players_load_infos;
        int nb_players;
        int nb_ais;
        std::shared_ptr<Sprite> _player1_settings;
        std::shared_ptr<Sprite> _player2_settings;
        std::shared_ptr<Sprite> _player3_settings;
        std::shared_ptr<Sprite> _player4_settings;
        std::vector<std::vector<int>> _players_binds;
        std::vector<std::shared_ptr<Player>> _players;

    private:
        CoreScreen current_screen;
        CoreScreen old_screen;
};

#endif /* !__CORE_INFO_HPP__ */
