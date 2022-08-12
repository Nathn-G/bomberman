/*
** EPITECH PROJECT, 2022
** indie studio
** File description:
** CoreInfo
*/

#include "CoreInfo.hpp"

CoreInfo::CoreInfo()
{
    std::regex splitter("\\d+");
    std::smatch matcher;
    std::ifstream infile("../saves/binds_save.txt");
    this->nb_players = 0;
    this->nb_ais = 0;
    this->current_screen = CoreScreen::MENU;
    this->old_screen = CoreScreen::MENU;
    std::vector<int> tmp;
    this->_players_load_infos = {};

    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {    
            int i = 1;
            tmp.clear();
            while (regex_search(line, matcher, splitter)) {
                try {
                    tmp.push_back(std::stoi(matcher.str(0)));
                } catch (__attribute__((unused))std::exception &err) {
                    throw Indie::AError("Error while converting string to float/int", "Reception::init");
                }
                line = matcher.suffix().str();
                i++;
            }
            tmp.push_back(0);
            _players_binds.push_back(tmp);
        }
    } else {
        std::ofstream save ("../saves/binds_save.txt");
        // forward, backward, left, right, bomb
        _players_binds.push_back(std::vector<int>({KEY_W, KEY_S, KEY_A, KEY_D, KEY_E, 0}));
        _players_binds.push_back(std::vector<int> ({KEY_T, KEY_G, KEY_F, KEY_H, KEY_Y, 0}));
        _players_binds.push_back(std::vector<int>({KEY_I, KEY_K, KEY_J, KEY_L, KEY_O, 0}));
        _players_binds.push_back(std::vector<int> ({KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, 0}));
        save.close();
    }
}

CoreInfo::~CoreInfo()
{
    std::fstream ofs;
    ofs.open("../saves/binds_save.txt", std::ios::out | std::ios::trunc);
    for (auto &binds : _players_binds) {
        ofs << binds[0] << ";" << binds[1] << ";" << binds[2] << ";" << binds[3] << ";" << binds[4] << std::endl;
    }
    ofs.close();
}

void CoreInfo::update_controllers()
{
    for (int i = 0; i < this->nb_players; i++) {
        this->_players_binds[i][0] = GAMEPAD_BUTTON_LEFT_FACE_UP;
        this->_players_binds[i][1] = GAMEPAD_BUTTON_LEFT_FACE_DOWN;
        this->_players_binds[i][2] = GAMEPAD_BUTTON_LEFT_FACE_LEFT;
        this->_players_binds[i][3] = GAMEPAD_BUTTON_LEFT_FACE_RIGHT;
        this->_players_binds[i][4] = 6;
        this->_players_binds[i][5] = 1;
    }
}

void CoreInfo::changeScreen(CoreScreen coreScreen)
{
    this->old_screen = current_screen;
    this->current_screen = coreScreen;
}

CoreScreen CoreInfo::getCurrentScreen()
{
    return this->current_screen;
}

CoreScreen CoreInfo::getOldScreen()
{
    return this->old_screen;
}

void CoreInfo::saveGame()
{
    // DirE dire("../saves");
    int count_save = 0;
    std::vector<std::string> map_to_save = this->_map_split;
    int before_x = _map_split.at(0).size() / 2;
    int before_z = _map_split.size() / 2;

    // while (dire.readdirE()) {
    //     if (dire.getName().length() > 4 && dire.getName().substr(0, 4) == "save")
    //         count_save += 1;
    // }
    const std::filesystem::path sandbox{"../saves/"};

    for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) 
    {
        std::filesystem::path p{dir_entry};
        std::string ddd{p.u8string()};
        if (ddd.length() > 14 && ddd.substr(9, 4) == "save") {
            count_save++;
        }
    }
    for (int i = 0; i < 4; i++) {
        Vector3 pos = this->_players.at(i)->getTruePos(this->_map_split);
        int ix = pos.x + _map_split.at(0).size() / 2;
        int iz = pos.z + _map_split.size() / 2;
        map_to_save[iz][ix] = 'P';
    }
    std::ofstream {"../saves/save" + std::to_string(count_save) + ".txt"};
    std::fstream f("../saves/save" + std::to_string(count_save) + ".txt", std::fstream::app);
    for (int i = 0; i < map_to_save.size(); i++)
        f << map_to_save[i] << "\n";
    for (int i = 0; i < 4; i++) {
        Vector3 pos = this->_players.at(i)->getTruePos(this->_map_split);
        f << this->_players.at(i)->isBot << " " << this->_players.at(i)->isDead << " " <<
        this->_players.at(i)->lives << " " << pos.x << " " << pos.z << "\n";
    }
    f.close();
}
