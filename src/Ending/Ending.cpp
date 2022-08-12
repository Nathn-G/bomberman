/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Settings
*/

#include "Ending.hpp"

Ending::Ending()
{

}

Ending::~Ending()
{

}

void Ending::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_core = core;
    this->_camera = camera;

    _sprites["_background"] = this->_tools.newSprite("../assets/win_background.png");
    _sprites["_menu"] = this->_tools.newSprite("../assets/buttons/win_menu.png");
    _sprites["_menu_clicked"] = this->_tools.newSprite("../assets/buttons/win_menu_clicked.png");
    _sprites["_quit"] = this->_tools.newSprite("../assets/buttons/win_quit.png");
    _sprites["_quit_clicked"] = this->_tools.newSprite("../assets/buttons/win_quit_clicked.png");
    _sprites["_top1"] = this->_tools.newSprite("../assets/win_top1.png");

    if (this->_core->winner == 1) {
        _sprites["_winner"] = this->_tools.newSprite("../assets/win_player1.png");
    } else if (this->_core->winner == 2) {
        _sprites["_winner"] = this->_tools.newSprite("../assets/win_player2.png");
    } else if (this->_core->winner == 3) {
        _sprites["_winner"] = this->_tools.newSprite("../assets/win_player3.png");
    } else if (this->_core->winner == 4) {
        _sprites["_winner"] = this->_tools.newSprite("../assets/win_player4.png");
    } else {
        _sprites["_winner"] = this->_tools.newSprite("../assets/win_equality.png");
        _sprites["_top1"]->_display = false;
    }

    _sprites["_menu_clicked"]->_display = false;
    _sprites["_quit_clicked"]->_display = false;
    for (int t = 0; t < 10; t++) {
        this->particles.push_back(Particles());
    }
}

void Ending::destroy()
{

}

void Ending::update()
{

}

void Ending::display()
{
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);

    this->lib.DrawRectangleE(0, 0, this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE(), BLUE);
    this->_tools.display(CoreScreen::ENDING, this->_camera->getCam());
    for (int i = 0; i < this->particles.size(); i++) {
        if (this->_core->winner == 1) {
            this->particles[i].Draw_yellow();
        } else if (this->_core->winner == 2) {
            this->particles[i].Draw();
        } else if (this->_core->winner == 3) {
            this->particles[i].Draw_blue();
        } else if (this->_core->winner == 4) {
            this->particles[i].Draw_green();
        }
    }
    
    this->lib.EndDrawingE();
}

void Ending::handleEvent()
{
    if (this->particles.size() < MAX_PARTICLES) {
        Particles particle;
        this->particles.push_back(particle);
    }
    for (int i = 0; i < this->particles.size(); i++) {
        this->particles[i].Update();
    }

    if (this->lib.GetMousePosition().first >= 70 && this->lib.GetMousePosition().first <= 250 &&
        this->lib.GetMousePosition().second >= 440 && this->lib.GetMousePosition().second <= 470) {
        _sprites["_menu_clicked"]->_display = true;
    } else {
        _sprites["_menu_clicked"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 70 && this->lib.GetMousePosition().first <= 250 &&
        this->lib.GetMousePosition().second >= 515 && this->lib.GetMousePosition().second <= 550) {
        _sprites["_quit_clicked"]->_display = true;
    } else {
        _sprites["_quit_clicked"]->_display = false;
    }

    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 70 && this->lib.GetMousePosition().first <= 250 &&
        this->lib.GetMousePosition().second >= 440 && this->lib.GetMousePosition().second <= 470) {
            this->_core->changeScreen(CoreScreen::MENU);
        }
        if (this->lib.GetMousePosition().first >= 70 && this->lib.GetMousePosition().first <= 250 &&
            this->lib.GetMousePosition().second >= 515 && this->lib.GetMousePosition().second <= 550) {
            this->_core->gameRunning = false;
        }
    }
}
