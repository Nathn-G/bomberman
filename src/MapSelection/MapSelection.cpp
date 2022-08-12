/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** MapSelection
*/

#include "MapSelection.hpp"

MapSelection::MapSelection()
{

}

MapSelection::~MapSelection()
{

}

void MapSelection::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_core = core;
    this->_camera = camera;

    this->_tools.loadFont("../assets/Font/mcfont.ttf", "mcfont");
    _sprites["_backmap"] = this->_tools.newSprite("../assets/backmap.png", 0, 0, 0);
    _sprites["_maptext"] = this->_tools.newSprite("../assets/maptext.png", 1, 0, 0);
    // _texts["select"] = this->_tools.newText("SELECT YOUR MAP", "mcfont", 300, 30, 0, 50);
    // _texts["wall"] = this->_tools.newText("WALLS", "mcfont", 600, 100, 0, 50);
    // _texts["create"] = this->_tools.newText("CRATES", "mcfont", 600, 150, 0, 50);
    // _texts["players"] = this->_tools.newText("PLAYERS", "mcfont", 600, 200, 0, 50);
    // _texts["empty"] = this->_tools.newText("EMPTY SPACES", "mcfont", 600, 250, 0, 50);
    loadMap();
}

void MapSelection::update()
{

}

void MapSelection::display()
{
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);
    this->_tools.display(CoreScreen::MAP_SELECTION, this->_camera->getCam());

    this->lib.DrawRectangleE(550, 100, 25, 25, RED);
    this->lib.DrawRectangleE(550, 150, 25, 25, BLUE);
    this->lib.DrawRectangleE(550, 200, 25, 25, YELLOW);
    this->lib.DrawRectangleE(550, 250, 25, 25, WHITE);
    if (this->_core->maps.size() > 0)
        for (int a = 0; a < this->_core->maps[this->_core->_map_to_display].boxes.size(); a++) {
            this->lib.DrawRectangleE(this->_core->maps[this->_core->_map_to_display].boxes[a].x, this->_core->maps[this->_core->_map_to_display].boxes[a].y, this->_core->maps[this->_core->_map_to_display].boxes[a].width, this->_core->maps[this->_core->_map_to_display].boxes[a].height, this->_core->maps[this->_core->_map_to_display].boxes[a].color);
        }

    this->lib.EndDrawingE();
}

void MapSelection::handleEvent()
{
    if (this->lib.IsKeyPressedE(KEY_BACKSPACE)) {
        this->_core->changeScreen(CoreScreen::MENU);
    }
    if (this->lib.IsKeyPressedE(KEY_ENTER) || this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        this->_map_string = this->_core->maps[this->_core->_map_to_display].data;
        this->_core->_map_split = Utils::split(this->_map_string, '\n');
        int size = this->_core->_map_split.size() > this->_core->_map_split.at(0).size() ? this->_core->_map_split.size() : this->_core->_map_split.at(0).size();
        Vector3 pos = {};
        Vector3 tar = {};
        if (this->_core->_map_split.size() % 2 == 0) {
            pos = { 1.0f, static_cast<float>(size), 6.0f };
            tar = { 1.0f, -2.0f, .0f };
        } else {
            pos = { 0.0f, static_cast<float>(size), 6.0f };
            tar = { 0.0f, -2.0f, .0f };
        }
        this->_camera->setUp({ .0f, 10.0f, 0.0f });
        this->_camera->setFovy(45.0f);
        this->_camera->setProjection(CAMERA_PERSPECTIVE);
        this->lib.SetCameraModeE(this->_camera->getCam(), CAMERA_CUSTOM);
        this->_core->changeScreen(CoreScreen::GAMEPLAY);

        // set pose before anim
        this->_camera->setPosition({ -6.0f, 2.0f, -3.0f });
        this->_camera->setTarget({ -6.0f, 0.0f, -5.0f });
        this->_camera->setAnim(pos, tar, 0.2f);
    }
    if (this->lib.IsKeyPressedE(KEY_RIGHT)) {
        if (this->_core->_map_to_display + 1 >= this->_core->maps.size())
            this->_core->_map_to_display = 0;
        else
            this->_core->_map_to_display += 1;
    }
    if (this->lib.IsKeyPressedE(KEY_LEFT)) {
        if (this->_core->_map_to_display - 1 < 0)
            this->_core->_map_to_display = this->_core->maps.size() - 1;
        else
            this->_core->_map_to_display -= 1;
    }
}

void MapSelection::destroy()
{

}

void MapSelection::show_files()
{
    // DirE dire("../maps");
    int count = 0;

    const std::filesystem::path sandbox{"../maps/"};

    for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) 
    {
        std::filesystem::path p{dir_entry};
        std::string ddd{ p.u8string() };
        if (ddd.length() > 12 && ddd.substr(8, 3) == "map") {
            loadFile(ddd);
            count += 1;
        }
    }

    // while (dire.readdirE()) {
    //     if (!dire.getName().find("map")) {
    //         loadFile("../maps/" + dire.getName());
    //         count += 1;
    //     }
    // }
    if (count == 0) {
        std::ofstream {"../maps/map1.txt"};
        std::fstream f("../maps/map1.txt", std::fstream::app);
        f << "###############\n#P OOOOOOOOO P#\n# #O#O#O#O#O# #\n#OOOOOOOOOOOOO#\n#O#O#O#O#O#O#O#\n#OOOOOOOOOOOOO#\n#O#O#O#O#O#O#O#\n#OOOOOOOOOOOOO#\n#O#O#O#O#O#O#O#\n#OOOOOOOOOOOOO#\n# #O#O#O#O#O# #\n#P OOOOOOOOO P#\n###############";
        f.close();
        loadFile("../maps/map1.txt");
    }
}

void MapSelection::loadFile(std::string filepath)
{
    std::string content;
    std::ifstream file(filepath);
    map_t tmp;

    if (file.is_open() == false) {
        return;
    } else {
        std::stringstream stream;
        stream << file.rdbuf();
        content = stream.str();
    }
    int x_nb = 0;
    int y_nb = 0;
    for (float i = 0; content[i]; i++, x_nb++) {
        if (i > 0 && content[i - 1] == '\n') {
            y_nb += 1;
            x_nb = 0;
        }
        if (content[i] == '#') {
            tmp.boxes.push_back(box_t {20, 20, x_nb * 20 + 50, y_nb * 20 + 100, RED});
        } else if (content[i] == 'P') {
            tmp.boxes.push_back(box_t {20, 20, x_nb * 20 + 50, y_nb * 20 + 100, YELLOW});
        } else if (content[i] == 'O') {
            if (rand() % 2 == 1)
                tmp.boxes.push_back(box_t {20, 20, x_nb * 20 + 50, y_nb * 20 + 100, BLUE});
            else {
                content[i] = ' ';
                tmp.boxes.push_back(box_t {20, 20, x_nb * 20 + 50, y_nb * 20 + 100, WHITE});
            }
        } else if (content[i] == ' ') {
            tmp.boxes.push_back(box_t {20, 20, x_nb * 20 + 50, y_nb * 20 + 100, WHITE});
        }
    }
    tmp.width = 0;
    tmp.height = 0;
    tmp.nb_player = 0;
    tmp.valid = true;
    tmp.data = content;
    this->_core->maps.push_back(tmp);
}

void MapSelection::loadMap()
{
    show_files();
    for (int a = 0; a < this->_core->maps.size(); a++) {
        for (; this->_core->maps[a].data[this->_core->maps[a].width] != '\n'; this->_core->maps[a].width++);
        for (float i = 0; this->_core->maps[a].data[i]; i++) {
            if (this->_core->maps[a].data[i] == '\n') {
                this->_core->maps[a].height++;
            }
            if (this->_core->maps[a].data[i] == 'P') {
                this->_core->maps[a].nb_player++;
            }
        }
        if (this->_core->maps[a].nb_player > 4) {
            this->_core->maps[a].valid = false;
        }
        if (this->_core->maps[a].height < 8 || this->_core->maps[a].height > 20) {
            this->_core->maps[a].valid = false;
        }
        if (this->_core->maps[a].width < 8 || this->_core->maps[a].width > 20) {
            this->_core->maps[a].valid = false;
        }
    }
}
