/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-mathis.lorenzo
** File description:
** Game_init
*/

#include "Core.hpp"

Core::Core()
{
    this->_camera = std::make_shared<Cam>();
    _coreinfo = std::make_shared<CoreInfo>();
    this->gameIsInit = false;
}

Core::~Core()
{

}

void Core::init()
{
    // init window
    const int screenWidth = 800;
    const int screenHeight = 600;
    RImage icon("../assets/icon.png");
    this->lib.InitWindowE(screenWidth, screenHeight, "Bomberman");
    this->lib.SetWindowIconE(icon);
    this->lib.SetTargetFPSE(60);
    this->start = false;
    this->lib.InitAudioDeviceE();
    this->showFPS = false;
    std::shared_ptr<MusicP> bgMusic = this->_tools.newMusic("../assets/Music/Menu.mp3");
    bgMusic.get()->play();

    SetTargetFPS(60);

    _menu.init(_coreinfo, _camera);
    _mapSelection.init(_coreinfo, _camera);
    _howToPlay.init(_coreinfo, _camera);
    _settings.init(_coreinfo, _camera);
    _loadSave.init(_coreinfo, _camera);
}
