/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Pause
*/

#include "Pause.hpp"

Pause::Pause()
{
}

Pause::~Pause()
{
}

void Pause::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_core = core;
    this->_camera = camera;
    this->_settings_index = 1;

    //init text
    // _texts["select"] = this->_tools.newText("Select a player to edit key binding", "nasa", this->lib.GetPlacementWidthE(185), this->lib.GetPlacementHeightE(75), 1);

    //init sprite
    _sprites["_backgroundp"] = this->_tools.newSprite("../assets/backpause.png");
    _sprites["_continue"] = this->_tools.newSprite("../assets/buttons/continue.png");
    _sprites["_continuec"] = this->_tools.newSprite("../assets/buttons/continuec.png");
    _sprites["_save"] = this->_tools.newSprite("../assets/buttons/save.png");
    _sprites["_savec"] = this->_tools.newSprite("../assets/buttons/savec.png");
    _sprites["_quitp"] = this->_tools.newSprite("../assets/buttons/quitp.png");
    _sprites["_quitpc"] = this->_tools.newSprite("../assets/buttons/quitpc.png");

    _sprites["_continuec"]->_display = false;
    _sprites["_savec"]->_display = false;
    _sprites["_quitpc"]->_display = false;
}

void Pause::destroy()
{
}

void Pause::update()
{
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 185 && this->lib.GetMousePosition().second <= 220) {
        _sprites["_continuec"]->_display = true;
    } else {
        _sprites["_continuec"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 230 && this->lib.GetMousePosition().second <= 265) {
        _sprites["_savec"]->_display = true;
    } else {
        _sprites["_savec"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 276 && this->lib.GetMousePosition().second <= 310) {
        _sprites["_quitpc"]->_display = true;
    } else {
        _sprites["_quitpc"]->_display = false;
    }    
}

void Pause::display()
{
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);

    this->_tools.display(CoreScreen::PAUSE, this->_camera->getCam());
    
    this->lib.EndDrawingE();
}
void Pause::handleEvent()
{
    if (this->lib.IsKeyPressedE(KEY_BACKSPACE)) {
        this->_core->changeScreen(CoreScreen::GAMEPLAY);
    }
    if (this->lib.IsKeyPressedE(KEY_ENTER)) {
        this->_core->changeScreen(CoreScreen::SETTINGS);
    }
    if (this->lib.IsKeyPressedE(KEY_LEFT) && this->_settings_index >= 2)
        this->_settings_index -= 1;
    if (this->lib.IsKeyPressedE(KEY_RIGHT) && this->_settings_index < 4 && this->_settings_index < this->_core->nb_players)
        this->_settings_index += 1;
    
    // continue button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 185 && this->lib.GetMousePosition().second <= 220)
            this->_core->changeScreen(CoreScreen::GAMEPLAY);
    }
    // save button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 230 && this->lib.GetMousePosition().second <= 265)
            this->_core->saveGame();
    }
    // quit button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 276 && this->lib.GetMousePosition().second <= 310)
            this->_core->gameRunning = false;
    }
}

void Pause::windowResized()
{
    
}
