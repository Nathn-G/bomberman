/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_camera = camera;
    this->_core = core;
    _scrollingBack = 0.0f;
    _scrollingMid = 0.0f;
    _scrollingFore = 0.0f;


    // init text
    // _texts["pressEnter"] = _tools.newText("PRESS ENTER to BEGIN", "nasa", CoreScreen::MENU, 400, 250, 0, 50);
    // _texts["loadSave"] = _tools.newText("PRESS L to LOAD a SAVE", "nasa", CoreScreen::MENU, 400, 290, 0, 45);
    // _texts["howToPlay"] = _tools.newText("PRESS H to HOW TO PLAY", "nasa", CoreScreen::MENU, 400, 330, 0, 45);
    // _texts["selectNbPlayer"] = _tools.newText("PRESS 1, 2, 3 or 4 to select the number of players", "nasa", CoreScreen::MENU, 400, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 2.75, 0, 40);
    // _texts["pressEnter"]->_centerText = true;
    // _texts["loadSave"]->_centerText = true;
    // _texts["howToPlay"]->_centerText = true;
    // _texts["selectNbPlayer"]->_centerText = true;
    _texts["player1"] = _tools.newText("CPU", "nasa", this->lib.GetScreenWidthE() / 2 - (this->lib.GetScreenWidthE() / 6) * 2 - 75, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 12, 2, 40);
    _texts["player2"] = _tools.newText("CPU", "nasa", this->lib.GetScreenWidthE() / 2 - this->lib.GetScreenWidthE() / 6 - 15, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 12, 2, 40);
    _texts["player3"] = _tools.newText("CPU", "nasa", this->lib.GetScreenWidthE() / 2 + 45, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 12, 2, 40);
    _texts["player4"] = _tools.newText("CPU", "nasa", this->lib.GetScreenWidthE() / 2 + 30 + this->lib.GetScreenWidthE() / 6 + 75, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 12, 2, 40);

    //init sprite
    _sprites["_background"] = _tools.newSprite("../assets/back.png", 1, 0, 0);
    _sprites["_midground"] = _tools.newSprite("../assets/mid.png", 0, _scrollingMid, 0);
    _sprites["_foreground"] = _tools.newSprite("../assets/fore.png", 0, _scrollingFore, 0);
    for (int t = 0; t < 10; t++) {
        this->particles.push_back(Particles());
    }

    // _sprites["_backgroundR"] = _tools.newSprite("../assets/back.png", 0, this->lib.GetScreenWidthE() + _scrollingBack, 0);
    _sprites["_midgroundR"] = _tools.newSprite("../assets/mid.png", 0, this->lib.GetScreenWidthE() + _scrollingMid, 0);
    _sprites["_foregroundR"] = _tools.newSprite("../assets/fore.png", 0, this->lib.GetScreenWidthE() + _scrollingFore, 0);
    _sprites["_addp1"] = _tools.newSprite("../assets/buttons/addp.png", 2, 40, 566);
    _sprites["_addp1c"] = _tools.newSprite("../assets/buttons/addpc.png", 2, 40, 566);
    _sprites["_addp2"] = _tools.newSprite("../assets/buttons/addp.png", 2, 232, 566);
    _sprites["_addp2c"] = _tools.newSprite("../assets/buttons/addpc.png", 2, 232, 566);
    _sprites["_addp3"] = _tools.newSprite("../assets/buttons/addp.png", 2, 427, 566);
    _sprites["_addp3c"] = _tools.newSprite("../assets/buttons/addpc.png", 2, 427, 566);
    _sprites["_addp4"] = _tools.newSprite("../assets/buttons/addp.png", 2, 620, 566);
    _sprites["_addp4c"] = _tools.newSprite("../assets/buttons/addpc.png", 2, 620, 566);
    _sprites["_play"] = _tools.newSprite("../assets/buttons/play.png", 1, 0, 0);
    _sprites["_playc"] = _tools.newSprite("../assets/buttons/playc.png", 1, 0, 0);
    _sprites["_load"] = _tools.newSprite("../assets/buttons/load.png", 1, 0, 0);
    _sprites["_loadc"] = _tools.newSprite("../assets/buttons/loadc.png", 1, 0, 0);
    _sprites["_settings"] = _tools.newSprite("../assets/buttons/settings.png", 1, 0, 0);
    _sprites["_settingsc"] = _tools.newSprite("../assets/buttons/settingsc.png", 1, 0, 0);
    _sprites["_help"] = _tools.newSprite("../assets/buttons/help.png", 1, 0, 0);
    _sprites["_helpc"] = _tools.newSprite("../assets/buttons/helpc.png", 1, 0, 0);
    _sprites["_quit"] = _tools.newSprite("../assets/buttons/quit.png", 1, 0, 0);
    _sprites["_quitc"] = _tools.newSprite("../assets/buttons/quitc.png", 1, 0, 0);
    _sprites["logo"] = _tools.newSprite("../assets/logo.png", 1, 0, 0);
    _sprites["yellow"] = _tools.newSprite("../assets/yellow1.png", 1, this->lib.GetScreenWidthE() / 2 - (this->lib.GetScreenWidthE() / 6) * 2 - 90, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 3);
    _sprites["red"] = _tools.newSprite("../assets/red1.png", 1, this->lib.GetScreenWidthE() / 2 - this->lib.GetScreenWidthE() / 6 - 30, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 3);
    _sprites["blue"] =  _tools.newSprite("../assets/blue1.png", 1, this->lib.GetScreenWidthE() / 2 + 30, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 3);
    _sprites["green"] = _tools.newSprite("../assets/green1.png", 1, this->lib.GetScreenWidthE() / 2 + 30 + this->lib.GetScreenWidthE() / 6 + 60, this->lib.GetScreenHeightE() - this->lib.GetScreenHeightE() / 3);

    // init sounds
    _sounds["_1"] = std::make_shared<RSound>("../assets/Sounds/1_joueur.mp3");
    _sounds["_2"] = std::make_shared<RSound>("../assets/Sounds/2_joueurs.mp3");
    _sounds["_3"] = std::make_shared<RSound>("../assets/Sounds/3_joueurs.mp3");
    _sounds["_4"] = std::make_shared<RSound>("../assets/Sounds/4_joueurs.mp3");

    // set display false
    _sprites["_playc"]->_display = false;
    _sprites["_loadc"]->_display = false;
    _sprites["_settingsc"]->_display = false;
    _sprites["_helpc"]->_display = false;
    _sprites["_quitc"]->_display = false;
    _sprites["_addp1c"]->_display = false;
    _sprites["_addp2c"]->_display = false;
    _sprites["_addp3c"]->_display = false;
    _sprites["_addp4c"]->_display = false;
}

void Menu::destroy()
{

}

void Menu::update()
{
    _scrollingBack -= 0.5f;
    _scrollingMid -= 0.7f;
    _scrollingFore -= 1.0f;

    // if (_scrollingBack <= -_sprites["_background"]->getWidth())
    //     _scrollingBack = 0;
    if (_scrollingMid <= -_sprites["_midground"].get()->getWidth())
        _scrollingMid = 0;
    if (_scrollingFore <= -_sprites["_foreground"].get()->getWidth())
        _scrollingFore = 0;
    // _sprites["_background"]->setX(_scrollingBack);
    _sprites["_midground"]->setX(_scrollingMid);
    _sprites["_foreground"]->setX(_scrollingFore);
    // _sprites["_backgroundR"]->setX(this->lib.GetScreenWidthE() + _scrollingBack);
    _sprites["_midgroundR"]->setX(this->lib.GetScreenWidthE() + _scrollingMid);
    _sprites["_foregroundR"]->setX(this->lib.GetScreenWidthE() + _scrollingFore);
    for (int i = 0; i < this->particles.size(); i++) {
        this->particles[i].Update();
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 185 && this->lib.GetMousePosition().second <= 220) {
        _sprites["_playc"]->_display = true;
    } else {
        _sprites["_playc"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 230 && this->lib.GetMousePosition().second <= 265) {
        _sprites["_loadc"]->_display = true;
    } else {
        _sprites["_loadc"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 276 && this->lib.GetMousePosition().second <= 310) {
        _sprites["_settingsc"]->_display = true;
    } else {
        _sprites["_settingsc"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 393 &&
        this->lib.GetMousePosition().second >= 340 && this->lib.GetMousePosition().second <= 377) {
        _sprites["_helpc"]->_display = true;
    } else {
        _sprites["_helpc"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 400 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 340 && this->lib.GetMousePosition().second <= 377) {
        _sprites["_quitc"]->_display = true;
    } else {
        _sprites["_quitc"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 40 && this->lib.GetMousePosition().first <= 40 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
        _sprites["_addp1c"]->_display = true;
    } else {
        _sprites["_addp1c"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 232 && this->lib.GetMousePosition().first <= 232 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
        _sprites["_addp2c"]->_display = true;
    } else {
        _sprites["_addp2c"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 427 && this->lib.GetMousePosition().first <= 427 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
        _sprites["_addp3c"]->_display = true;
    } else {
        _sprites["_addp3c"]->_display = false;
    }
    if (this->lib.GetMousePosition().first >= 620 && this->lib.GetMousePosition().first <= 620 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
        _sprites["_addp4c"]->_display = true;
    } else {
        _sprites["_addp4c"]->_display = false;
    }
}

void Menu::display()
{
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);
    this->_tools.display(CoreScreen::MENU, this->_camera->getCam());
    for (int i = 0; i < this->particles.size(); i++) {
        this->particles[i].Draw();
    }

    this->lib.EndDrawingE();
}

void Menu::handleEvent()
{
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 40 && this->lib.GetMousePosition().first <= 40 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
            if (this->_core->nb_players == 1)
                this->_core->nb_players = 0;
            else
                this->_core->nb_players = 1;
            _sounds["_1"]->PlayMulti();
        }
    }
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 232 && this->lib.GetMousePosition().first <= 232 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
            this->_core->nb_players = 2;
            _sounds["_2"]->PlayMulti();
        }
    }
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 427 && this->lib.GetMousePosition().first <= 427 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
            this->_core->nb_players = 3;
            _sounds["_3"]->PlayMulti();
        }
    }
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 620 && this->lib.GetMousePosition().first <= 620 + 123 &&
        this->lib.GetMousePosition().second >= 566 && this->lib.GetMousePosition().second <= 592) {
            this->_core->nb_players = 4;
            _sounds["_4"]->PlayMulti();
        }
    }

    // play button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 185 && this->lib.GetMousePosition().second <= 220)
            this->_core->changeScreen(CoreScreen::MAP_SELECTION);
    }
    // load save
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 230 && this->lib.GetMousePosition().second <= 265)
            this->_core->changeScreen(CoreScreen::LOADSAVE);
    }
    // settings button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 276 && this->lib.GetMousePosition().second <= 310)
            this->_core->changeScreen(CoreScreen::SETTINGS);
    }
    // help button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 217 && this->lib.GetMousePosition().first <= 393 &&
        this->lib.GetMousePosition().second >= 340 && this->lib.GetMousePosition().second <= 377)
            this->_core->changeScreen(CoreScreen::HOW_TO_PLAY);
    }
    // quit button
    if (this->lib.IsGestureDetectedE(GESTURE_TAP)) {
        if (this->lib.GetMousePosition().first >= 400 && this->lib.GetMousePosition().first <= 575 &&
        this->lib.GetMousePosition().second >= 340 && this->lib.GetMousePosition().second <= 377)
            this->_core->gameRunning = false;
    }
    if (this->particles.size() < MAX_PARTICLES) {
        Particles particle;
        this->particles.push_back(particle);
    }
    for (int i = 0; i < this->particles.size(); i++) {
        this->particles[i].Update();
    }
    if (this->_core->nb_players > 0)
        this->_texts["player1"]->setText("Player 1");
    else
        this->_texts["player1"]->setText("CPU");
    if (this->_core->nb_players > 1)
        this->_texts["player2"]->setText("Player 2");
    else
        this->_texts["player2"]->setText("CPU");
    if (this->_core->nb_players > 2)
        this->_texts["player3"]->setText("Player 3");
    else
        this->_texts["player3"]->setText("CPU");
    if (this->_core->nb_players > 3)
        this->_texts["player4"]->setText("Player 4");
    else
        this->_texts["player4"]->setText("CPU");

    this->_core->nb_ais = MAX_PLAYERS - this->_core->nb_players;
}

void Menu::windowResized()
{
    _sprites["yellow"]->Resize(this->lib.GetScreenWidthE() / 6, this->lib.GetScreenHeightE() / 3);
    _sprites["red"]->Resize(this->lib.GetScreenWidthE() / 6, this->lib.GetScreenHeightE() / 3);
    _sprites["blue"]->Resize(this->lib.GetScreenWidthE() / 6, this->lib.GetScreenHeightE() / 3);
    _sprites["green"]->Resize(this->lib.GetScreenWidthE() / 6, this->lib.GetScreenHeightE() / 3);
    // _sprites["_background"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_midground"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_foreground"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_backgroundR"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_midgroundR"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_foregroundR"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["logo"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_play"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_playc"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_load"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_loadc"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_settings"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_settingsc"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_help"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_helpc"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_quit"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
    // _sprites["_quitc"]->Resize(this->lib.GetScreenWidthE(), this->lib.GetScreenHeightE());
}
