/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** How to play
*/

#include "HowToPlay.hpp"

HowToPlay::HowToPlay()
{

}

HowToPlay::~HowToPlay()
{

}

void HowToPlay::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_core = core;
    this->_camera = camera;

    _sprites["_background"] = this->_tools.newSprite("../assets/howtoplay_background.png");
    _sprites["_background_clicked"] = this->_tools.newSprite("../assets/howtoplay_backgroundc.png");
    _sprites["_background_clicked"]->_display = false;
}

void HowToPlay::destroy()
{

}

void HowToPlay::update()
{
}

void HowToPlay::display()
{
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);
    
    _tools.display(CoreScreen::HOW_TO_PLAY, this->_camera->getCam());

    this->lib.EndDrawingE();
}

void HowToPlay::handleEvent()
{
    if (this->lib.IsKeyPressedE(KEY_H) || this->lib.IsKeyPressedE(KEY_BACKSPACE)) {
        this->_core->changeScreen(CoreScreen::MENU);
    }
    if (this->lib.GetMousePosition().first >= 140 && this->lib.GetMousePosition().first <= 330 &&
        this->lib.GetMousePosition().second >= 500 && this->lib.GetMousePosition().second <= 540) {
        _sprites["_background_clicked"]->_display = true;
    } else {
        _sprites["_background_clicked"]->_display = false;
    }
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 140 && this->lib.GetMousePosition().first <= 330 &&
            this->lib.GetMousePosition().second >= 500 && this->lib.GetMousePosition().second <= 540) {
            this->_core->changeScreen(CoreScreen::MENU);
        }
    }
}
