/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-mathis.lorenzo
** File description:
** Game_back
*/

#include "Core.hpp"

void Core::loop()
{
    bool controllers = false;
    // bgMusic.get()->play();

    while (!this->lib.WindowShouldCloseE() && this->_coreinfo->gameRunning) {
        if (controllers == false && this->lib.AmountGamePadE() > 0) {
            controllers = true;
            this->_coreinfo->nb_players = this->lib.AmountGamePadE();
        }
        // this->lib.UpdateCameraE(&this->camera);
        // UpdateCamera(&this->_camera->getCam());
        this->_camera->update(this->_coreinfo->getCurrentScreen());
        if (this->lib.IsKeyPressedE(KEY_EQUAL))
            this->showFPS = !this->showFPS;
        if (this->lib.IsWindowResizedE() || !this->start) {
            this->start = true;
            this->_menu.windowResized();
        }
        this->displayModuleScreen();
    }
    this->_game.closeAllObjects();
    this->lib.CloseWindowE();
}

void Core::displayModuleScreen()
{
    this->_tools.updateMusic();
    switch (this->_coreinfo->getCurrentScreen()) {
        case CoreScreen::MENU:
        {
            this->_menu.handleEvent();
            this->_menu.update();
            this->_menu.display();
        } break;
        case CoreScreen::HOW_TO_PLAY:
        {
            this->_howToPlay.handleEvent();
            this->_howToPlay.update();
            this->_howToPlay.display();
        } break;
        case CoreScreen::MAP_SELECTION:
        {
            this->_mapSelection.handleEvent();
            this->_mapSelection.update();
            this->_mapSelection.display();
        } break;
        case CoreScreen::LOADSAVE:
        {
            this->_loadSave.handleEvent();
            this->_loadSave.update();
            this->_loadSave.display();
        } break;
        case CoreScreen::SETTINGS:
        {
            this->_settings.handleEvent();
            this->_settings.update();
            this->_settings.display();
        } break;
        case CoreScreen::PAUSE:
        {
            this->_pause.handleEvent();
            this->_pause.update();
            this->_pause.display();
        } break;
        case CoreScreen::GAMEPLAY:
        {
            if (!this->gameIsInit) {
                this->gameIsEnd = false;
                this->_game.init(_coreinfo, _camera);
                this->_pause.init(_coreinfo, _camera);
                this->_pause.windowResized();
                this->gameIsInit = true;
            }
            this->_game.handleEvent();
            if (this->testgame) {
                this->_game.update();
            } else {
                this->testgame = true;
            }
            this->_game.display();
        } break;
        case CoreScreen::ENDING:
        {
            if (!this->gameIsEnd) {
                this->gameIsInit = false;
                this->_ending.init(_coreinfo, _camera);
                this->gameIsEnd = true;
            }
            this->_ending.handleEvent();
            this->_ending.update();
            this->_ending.display();
        } break;
        default:
            break;
    }
}
