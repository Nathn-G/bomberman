/*
** EPITECH PROJECT, 2022
** indie studio
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _clock(0.02), _startIa(4.0f)
{
    this->_tools = std::make_shared<Tools>();
    this->_bombs = std::make_shared<std::vector<std::shared_ptr<Bomb>>>();
    this->_frameCounter = 0;
    this->_iaActive = false;
}

Game::~Game()
{

}

void Game::init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera)
{
    this->_startIa.reset();
    this->_core = core;
    this->_camera = camera;
    this->initMap();
    _sprites["_interface"] = this->_tools->newSprite("../assets/interface.png", 2, 0, 0);
    _sprites["_backgame"] = this->_tools->newSprite("../assets/backgame.png", 0, 0, 0);
    _texts["life1"] = _tools->newText("1", "nasa", 70, 15, 3, 60);
    _texts["life2"] = _tools->newText("1", "nasa", 730, 15, 3, 60);
    _texts["life3"] = _tools->newText("1", "nasa", 70, 520, 3, 60);
    _texts["life4"] = _tools->newText("1", "nasa", 730, 520, 3, 60);
    _texts["bomb1"] = _tools->newText("1", "nasa", 70, 15 + 45, 3, 60);
    _texts["bomb2"] = _tools->newText("1", "nasa", 730, 15 + 45, 3, 60);
    _texts["bomb3"] = _tools->newText("1", "nasa", 70, 520 + 45, 3, 60);
    _texts["bomb4"] = _tools->newText("1", "nasa", 730, 520 + 45, 3, 60);
    _sprites["speed1"] = this->_tools->newSprite("../assets/Bonus/bomberman-bonus/source/bonus/textures/speed.png", 3, 78, 78);
    _sprites["speed1"]->Resize(20, 20);
    _sprites["speed2"] = this->_tools->newSprite("../assets/Bonus/bomberman-bonus/source/bonus/textures/speed.png", 3, 702, 78);
    _sprites["speed2"]->Resize(20, 20);
    _sprites["speed3"] = this->_tools->newSprite("../assets/Bonus/bomberman-bonus/source/bonus/textures/speed.png", 3, 78, 502);
    _sprites["speed3"]->Resize(20, 20);
    _sprites["speed4"] = this->_tools->newSprite("../assets/Bonus/bomberman-bonus/source/bonus/textures/speed.png", 3, 702, 502);
    _sprites["speed4"]->Resize(20, 20);

    _sounds["_bomb"] = std::make_shared<RSound>("../assets/Sounds/bomb.mp3");
    _sounds["_dead"] = std::make_shared<RSound>("../assets/Sounds/mort.mp3");

}

void Game::destroy()
{

}

void Game::update()
{
    if (!this->_iaActive && !this->_startIa.check())
        return;
    this->_iaActive = true;
    for (int i = 0; i < this->_core->_players.size(); i++) {
        if (this->_core->_players[i]->_isAi && !this->_core->_players[i]->isDead) {
            this->_core->_players.at(i)->p_posi = this->_core->_players.at(i)->model->getPosition();
            this->_core->_players.at(i).get()->model->changeAnimation(1);
            this->_core->_players.at(i)->updateAI2(this->_core->_map_split, this->_bombs, this->_core->getCurrentScreen(), this->_tools, this->_fires);
            this->_core->_players.at(i)->updatePlayer();
        }
    }
}

void Game::display()
{
    if (!this->_clock.check())
        return;
    this->lib.BeginDrawingE();
    this->lib.ClearBackgroundE(GRAY);
    for (int i = 0; i < this->_core->_players.size(); i++) {
        std::string life = "life" + std::to_string(i + 1);
        std::string bomb = "bomb" + std::to_string(i + 1);
        std::string speed = "speed" + std::to_string(i + 1);

        _texts[life]->setText(std::to_string(this->_core->_players[i]->lives));
        _texts[bomb]->setText(std::to_string(*this->_core->_players[i]->nb_bombs));
        _sprites[speed]->_display = this->_core->_players[i]->isSpeedBoosted();
    }
    this->_tools->display(CoreScreen::GAMEPLAY, this->_camera->getCam());

    this->lib.EndDrawingE();
}

void Game::handleEvent()
{
    // if (this->lib.IsKeyPressedE(KEY_ENTER) || this->lib.IsGestureDetectedE(GESTURE_TAP)) {
    //     this->_core->changeScreen(CoreScreen::ENDING);
    // }
    if (this->lib.IsKeyPressedE(KEY_P)) {
        this->_core->changeScreen(CoreScreen::PAUSE);
    }
    int in_live = 0;
    int player_alive = 0;
    for (int i = 0; i < this->_core->_players.size(); i++) {
        if (!this->_core->_players[i]->isDead && !this->_core->_players[i]->isBot)
            player_alive++;
    }
    for (int i = 0; i < this->_core->_players.size(); i++) {
        if (!this->_core->_players[i]->isDead)
            in_live++;
    }
    if (in_live <= 1 || (this->_core->nb_players > 0 && player_alive == 0)) {
        this->_core->winner = 0;
        for (int i = 0; i < this->_core->_players.size(); i++) {
            if (!this->_core->_players[i]->isDead)
                this->_core->winner = i + 1;
            }
        if (this->_core->nb_players > 0 && player_alive == 0)
            this->_core->winner = 0;
        for (int i = 0; i < this->_core->_players.size(); i++) {
            this->_tools->deleteModel(this->_core->_players[i]->model->getIndex());
        }
        // this->_core->_players.clear();
        for (int i = 0; i < this->_models.size(); i++) {
            this->_tools->deleteModel(this->_models[i]->getIndex());
        }
        // this->_models.clear();
        for (int i = 0; i < this->_destroyables.size(); i++) {
            this->_tools->deleteModel(this->_destroyables[i]->getIndex());
        }
        // this->_destroyables.clear();
        for (int i = 0; i < this->_bombs->size(); i++) {
            this->_tools->deleteModel((*this->_bombs.get())[i]->model->getIndex());
        }
        // this->_bombs.clear();
        for (int i = 0; i < this->_fires.size(); i++) {
            this->_tools->deleteModel(this->_fires[i]->model->getIndex());
        }
        // this->_fires.clear();
        for (int i = 0; i < this->_speeds.size(); i++) {
            this->_tools->deleteModel(this->_speeds[i]->model->getIndex());
        }
        // this->_speeds.clear();
        for (int i = 0; i < this->_detonators.size(); i++) {
            this->_tools->deleteModel(this->_detonators[i]->model->getIndex());
        }
        // this->_detonators.clear();
        for (int i = 0; i < this->_recovBombs.size(); i++) {
            this->_tools->deleteModel(this->_recovBombs[i]->model->getIndex());
        }
        // this->_recovBombs.clear();
        for (int i = 0; i < this->_recovLifes.size(); i++) {
            this->_tools->deleteModel(this->_recovLifes[i]->model->getIndex());
        }
        // this->_recovLifes.clear();
        this->_sprites.clear();
        _texts["life1"]->setText("");
        _texts["life2"]->setText("");
        _texts["life3"]->setText("");
        _texts["life4"]->setText("");
        _texts["bomb1"]->setText("");
        _texts["bomb2"]->setText("");
        _texts["bomb3"]->setText("");
        _texts["bomb4"]->setText("");
        this->_texts.clear();
        this->_core->changeScreen(CoreScreen::ENDING);
        this->_core->_players.clear();
        this->_models.clear();
        this->_destroyables.clear();
        this->_bombs->clear();
        this->_fires.clear();
        this->_speeds.clear();
        this->_detonators.clear();
        this->_recovBombs.clear();
        this->_recovLifes.clear();

        return;
    }
    for (int i = 0; i < this->_core->_players.size(); i++) {
        if (!this->_core->_players.at(i).get()->isDead) {
            this->_core->_players.at(i).get()->model->changeAnimation(1);
            if (!this->_core->_players.at(i)->isBot) {
                if (this->lib.IsKeyDownE(this->_core->_players_binds.at(i).at(0)) || this->lib.isGamepadButtonPressedE(i, GAMEPAD_BUTTON_LEFT_FACE_UP))
                    this->_core->_players.at(i).get()->moveUp(this->_core->_map_split);
                if (this->lib.IsKeyDownE(this->_core->_players_binds.at(i).at(1)) || this->lib.isGamepadButtonPressedE(i, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
                    this->_core->_players.at(i).get()->moveDown(this->_core->_map_split);
                if (this->lib.IsKeyDownE(this->_core->_players_binds.at(i).at(2)) || this->lib.isGamepadButtonPressedE(i, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
                    this->_core->_players.at(i).get()->moveLeft(this->_core->_map_split);
                if (this->lib.IsKeyDownE(this->_core->_players_binds.at(i).at(3)) || this->lib.isGamepadButtonPressedE(i, 6))
                    this->_core->_players.at(i).get()->moveRight(this->_core->_map_split);
                if (this->lib.IsKeyDownE(this->_core->_players_binds.at(i).at(4)) || this->lib.isGamepadButtonPressedE(i, 1)) {
                    std::shared_ptr<Bomb> bomb = this->_core->_players.at(i).get()->dropBomb(this->_core->_map_split, *this->_bombs.get(), this->_core->getCurrentScreen(), this->_tools);
                    if (bomb != NULL)
                        this->_bombs->push_back(bomb);
                }
            }
        }
        this->_core->_players.at(i)->updatePlayer();
    }
    for (int i = 0; i < this->_recovLifes.size(); i++)
    {
        for (int j = 0; j < this->_core->_players.size(); j++) {
            if (!this->_core->_players.at(j).get()->isDead) {
                Vector3 posi = this->_core->_players.at(j).get()->getTruePos(this->_core->_map_split);
                if (posi.x == this->_recovLifes[i].get()->model.get()->getPosition().x &&
                posi.z == this->_recovLifes[i].get()->model.get()->getPosition().z) {
                    if (this->_core->_players[j]->lives < 2)
                        this->_core->_players[j]->lives = this->_core->_players[j]->lives + 1;
                    if (this->_core->_players[j]->lives > 2)
                        this->_core->_players[j]->lives = 2;
                    *this->_recovLifes[i].get()->explode = true;
                }
            }
        }
        if (*this->_recovLifes[i].get()->explode.get() == true)
        {
            this->_tools->deleteModel(this->_recovLifes[i].get()->model.get()->getIndex());
            std::vector<std::shared_ptr<RecovLife>>::iterator it = this->_recovLifes.begin();
            for (int a = 0; a < i; a++, it++);
            this->_recovLifes.erase(it);
            i--;
        }
    }
    for (int i = 0; i < this->_recovBombs.size(); i++)
    {
        for (int j = 0; j < this->_core->_players.size(); j++) {
            if (!this->_core->_players.at(j).get()->isDead) {
                Vector3 posi = this->_core->_players.at(j).get()->getTruePos(this->_core->_map_split);
                if (posi.x == this->_recovBombs[i].get()->model.get()->getPosition().x &&
                posi.z == this->_recovBombs[i].get()->model.get()->getPosition().z) {
                    if (*this->_core->_players[j]->nb_bombs < 3)
                        *this->_core->_players[j]->nb_bombs = *this->_core->_players[j]->nb_bombs + 1;
                    if (*this->_core->_players[j]->nb_bombs > 3)
                        *this->_core->_players[j]->nb_bombs = 3;
                    *this->_recovBombs[i].get()->explode = true;
                }
            }
        }
        if (*this->_recovBombs[i].get()->explode.get() == true)
        {
            this->_tools->deleteModel(this->_recovBombs[i].get()->model.get()->getIndex());
            std::vector<std::shared_ptr<RecovBomb>>::iterator it = this->_recovBombs.begin();
            for (int a = 0; a < i; a++, it++);
            this->_recovBombs.erase(it);
            i--;
        }
    }
    for (int i = 0; i < this->_detonators.size(); i++)
    {
        for (int j = 0; j < this->_core->_players.size(); j++) {
            if (!this->_core->_players.at(j).get()->isDead) {
                Vector3 posi = this->_core->_players.at(j).get()->getTruePos(this->_core->_map_split);
                if (posi.x == this->_detonators[i].get()->model.get()->getPosition().x &&
                posi.z == this->_detonators[i].get()->model.get()->getPosition().z) {
                    *this->_detonators[i].get()->explode = true;
                    for (int q = 0; q < this->_bombs->size(); q++)
                        *this->_bombs->at(q)->explode = true;
                }
            }
        }
        if (*this->_detonators[i].get()->explode.get() == true)
        {
            this->_tools->deleteModel(this->_detonators[i].get()->model.get()->getIndex());
            std::vector<std::shared_ptr<Detonator>>::iterator it = this->_detonators.begin();
            for (int a = 0; a < i; a++, it++);
            this->_detonators.erase(it);
            i--;
        }
    }
    for (int i = 0; i < this->_speeds.size(); i++)
    {
        for (int j = 0; j < this->_core->_players.size(); j++) {
            if (!this->_core->_players.at(j).get()->isDead) {
                Vector3 posi = this->_core->_players.at(j).get()->getTruePos(this->_core->_map_split);
                if (posi.x == this->_speeds[i].get()->model.get()->getPosition().x &&
                posi.z == this->_speeds[i].get()->model.get()->getPosition().z) {
                    this->_core->_players.at(j).get()->speedBoost();
                    *this->_speeds[i].get()->explode = true;
                }
            }
        }
        if (*this->_speeds[i].get()->explode.get() == true)
        {
            this->_tools->deleteModel(this->_speeds[i].get()->model.get()->getIndex());
            std::vector<std::shared_ptr<SpeedUp>>::iterator it = this->_speeds.begin();
            for (int a = 0; a < i; a++, it++);
            this->_speeds.erase(it);
            i--;
        }
    }
    this->_frameCounter += 1;
    for (int i = 0; i < this->_fires.size(); i++)
    {
        if (this->_fires[i]->scaled == false && this->_frameCounter % 10 == 0) {
            this->_fires[i]->scaled = true;
            this->_fires[i]->model->setScale(.7f, .7f, .7f);
        } else if (this->_frameCounter % 10 == 0) {
            this->_fires[i]->scaled = false;
            this->_fires[i]->model->setScale(.6f, .6f, .6f);
        }
        for (int j = 0; j < this->_core->_players.size(); j++) {
            if (!this->_core->_players.at(j)->isDead) {
                Vector3 posi = this->_core->_players.at(j).get()->getTruePos(this->_core->_map_split);
                if (posi.x == this->_fires[i].get()->model.get()->getPosition().x &&
                posi.z == this->_fires[i].get()->model.get()->getPosition().z) {
                    this->_core->_players.at(j).get()->dead();
                    if (this->_core->_players.at(j)->lives == 0)
                        _sounds["_dead"]->PlayMulti();
                }
            }
        }
        if (*this->_fires[i].get()->explode.get() == true)
        {
            this->_tools->deleteModel(this->_fires[i].get()->model.get()->getIndex());
            std::vector<std::shared_ptr<Fire>>::iterator it = this->_fires.begin();
            for (int a = 0; a < i; a++, it++);
            this->_fires.erase(it);
            i--;
        }
    }
    for (int i = 0; i < this->_bombs->size(); i++)
    {
        if ((*this->_bombs.get())[i]->model->_colorStr == "WHITE" && this->_frameCounter >= 20) {
            (*this->_bombs.get())[i]->model->_color = YELLOW;
            (*this->_bombs.get())[i]->model->_colorStr = "YELLOW";
        } else if (this->_frameCounter >= 20) {
            (*this->_bombs.get())[i]->model->_color = WHITE;
            (*this->_bombs.get())[i]->model->_colorStr = "WHITE";
        }

        if (*(*this->_bombs.get())[i]->explode.get() == true)
        {
            Vector3 p = this->_bombs->at(i).get()->model.get()->getPosition();
            int map_x = p.x + this->_core->_map_split.at(0).size() / 2;
            if (this->_core->_map_split.size() % 2 == 0)
                map_x -= 1;
            int map_z = p.z + this->_core->_map_split.size() / 2;
            bool valid = true;

            for (int a = 0; a < 5; a++)
            {
                if (map_x - a < 0 || !(this->_core->_map_split.at(map_z).at(map_x - a) == ' ' || this->_core->_map_split.at(map_z).at(map_x - a) == 'O'))
                    valid = false;
                if (valid)
                    valid = this->addFire(p.x - a, p.z, map_x - a, map_z);
            }
            valid = true;
            for (int a = 0; a < 5; a++)
            {
                if (map_x + a >= this->_core->_map_split.at(0).size() || !(this->_core->_map_split.at(map_z).at(map_x + a) == ' ' || this->_core->_map_split.at(map_z).at(map_x + a) == 'O'))
                    valid = false;
                if (valid)
                    valid = this->addFire(p.x + a, p.z, map_x + a, map_z);
            }
            valid = true;
            for (int a = 0; a < 5; a++)
            {
                if (map_z - a < 0 || !(this->_core->_map_split.at(map_z - a).at(map_x) == ' ' || this->_core->_map_split.at(map_z - a).at(map_x) == 'O'))
                    valid = false;
                if (valid)
                    valid = this->addFire(p.x, p.z - a, map_x, map_z - a);
            }
            valid = true;
            for (int a = 0; a < 5; a++)
            {
                if (map_z + a >= this->_core->_map_split.size() || !(this->_core->_map_split.at(map_z + a).at(map_x) == ' ' || this->_core->_map_split.at(map_z + a).at(map_x) == 'O'))
                    valid = false;
                if (valid)
                    valid = this->addFire(p.x, p.z + a, map_x, map_z + a);
            }
            this->_tools->deleteModel(this->_bombs->at(i).get()->model.get()->getIndex());
            std::vector<std::shared_ptr<Bomb>>::iterator it = this->_bombs->begin();
            for (int a = 0; a < i; a++, it++);
            this->_bombs->erase(it);
            _sounds["_bomb"]->PlayMulti();
            i--;
        }
    }
    if (this->_frameCounter >= 20)
        this->_frameCounter = 0;
}

bool Game::addFire(int x, int y, int map_x, int map_z)
{
    std::shared_ptr<Fire> fire = std::make_shared<Fire>(static_cast<float>(x), static_cast<float>(y), this->_tools, this->_core->getCurrentScreen());
    fire.get()->setIndex(this->_fires.size());
    this->_fires.push_back(fire);
    for (int z = 0; z < this->_bombs->size(); z++)
        if (this->_bombs->at(z).get()->model.get()->getPosition().x == x &&
        this->_bombs->at(z).get()->model.get()->getPosition().z == y)
            *this->_bombs->at(z).get()->explode = true;
    if (this->_core->_map_split.at(map_z).at(map_x) == 'O') {
        for (int e = 0; e < this->_destroyables.size(); e++) {
            if (this->_destroyables[e].get()->getPosition().x == x &&
            this->_destroyables[e].get()->getPosition().z == y) {
                this->_tools->deleteModel(this->_destroyables[e].get()->getIndex());
                std::vector<std::shared_ptr<Model3D>>::iterator it = this->_destroyables.begin();
                for (int q = 0; q < e; q++, it++);
                this->_destroyables.erase(it);
            }
        }
        this->_core->_map_split.at(map_z).at(map_x) = ' ';
        int ran = lib.GetRandomValueE(0, 10);
        if (ran < 2) {
            std::shared_ptr<SpeedUp> speedUp = std::make_shared<SpeedUp>(static_cast<float>(x), static_cast<float>(y), this->_tools, this->_core->getCurrentScreen());
            speedUp.get()->setIndex(this->_speeds.size());
            this->_speeds.push_back(speedUp);
        }
        if (ran >= 2 && ran < 3) {
            std::shared_ptr<Detonator> detonator = std::make_shared<Detonator>(static_cast<float>(x), static_cast<float>(y), this->_tools, this->_core->getCurrentScreen());
            detonator.get()->setIndex(this->_detonators.size());
            this->_detonators.push_back(detonator);
        }
        if (ran >= 3 && ran < 5) {
            std::shared_ptr<RecovBomb> recovBomb = std::make_shared<RecovBomb>(static_cast<float>(x), static_cast<float>(y), this->_tools, this->_core->getCurrentScreen());
            recovBomb.get()->setIndex(this->_recovBombs.size());
            this->_recovBombs.push_back(recovBomb);
        }
        if (ran >= 5 && ran < 6) {
            std::shared_ptr<RecovLife> recovLife = std::make_shared<RecovLife>(static_cast<float>(x), static_cast<float>(y), this->_tools, this->_core->getCurrentScreen());
            recovLife.get()->setIndex(this->_recovLifes.size());
            this->_recovLifes.push_back(recovLife);
        }
        return (false);
    }
    return (true);
}

void Game::initMapFloor()
{
    for (int i = 0; i < this->_core->_map_split.size(); i++) {
        int x = 0;
        int y = 0;

        for (int j = 0; j < this->_core->_map_split.at(0).size(); j++) {
            x = -1 * (this->_core->_map_split.size() / 2) + j;
            y = -1 * (this->_core->_map_split.at(i).size() / 2) + i;
            if (this->_core->_map_split.size() % 2 == 1)
                x = -1 * (this->_core->_map_split.size() / 2) + j - 1;
            if (this->_core->_map_split.at(i).size() % 2 == 1)
                y += 1;

            std::shared_ptr<Model3D> block = this->_tools->newModel(
                this->_core->getCurrentScreen(),
                "../assets/Box/brique.obj", "../assets/Box/textures/brick.png",
                { static_cast<float>(x), -1.0f, static_cast<float>(y) },
                { .5f, .5f, .5f }, { 1.0f, 0.0f, 0.0f },
                -90.0f
            );
            this->_models.push_back(block);
        }
    }
}

void Game::initMapWalls()
{
    for (int i = 0; i < this->_core->_map_split.size(); i++) {
        int x = 0;
        int y = 0;

        for (int j = 0; j < this->_core->_map_split.at(0).size(); j++) {
            x = -1 * (this->_core->_map_split.size() / 2) + j;
            y = -1 * (this->_core->_map_split.at(i).size() / 2) + i;
            if (this->_core->_map_split.size() % 2 == 1)
                x -= 1;
            if (this->_core->_map_split.at(i).size() % 2 == 1)
                y += 1;
            if (this->_core->_map_split[i][j] == '#') {
                std::shared_ptr<Model3D> brick = this->_tools->newModel(
                    this->_core->getCurrentScreen(),
                    "../assets/Box/brique.obj", "../assets/Box/textures/brique2.png",
                    { static_cast<float>(x), .0f, static_cast<float>(y) },
                    { .5f, .5f, .5f }, { 1.0f, 0.0f, 0.0f },
                    -90.0f
                );
                this->_models.push_back(brick);
            } else if (this->_core->_map_split[i][j] == 'P') {
                std::string textureName = "../assets/player/textures/yellow1.png";
                if (this->_core->_players.size() == 1) 
                    textureName = "../assets/player/textures/red1.png";
                if (this->_core->_players.size() == 2) 
                    textureName = "../assets/player/textures/cyan.png";
                if (this->_core->_players.size() == 3) 
                    textureName = "../assets/player/textures/green1.png";
                
                std::shared_ptr<Player> player = std::make_shared<Player>();
                player->model = this->_tools->newModelWithAnimation(
                    this->_core->getCurrentScreen(),
                    "../assets/player/player.iqm", textureName, "../assets/player/player.iqm",
                    {static_cast<float>(x), .0f, static_cast<float>(y) },
                    {.6f, .6f, .6f}, {.0f, -2.5f, 0.0f},
                    -90.0f
                );
                this->_core->_players.push_back(player);
                if (this->_core->_players.size() <= this->_core->nb_players)
                    this->_core->_players[this->_core->_players.size() - 1]->isBot = false;
                else
                    this->_core->_players[this->_core->_players.size() - 1]->_isAi = true;
                this->_core->_map_split[i][j] = ' ';
            } else if (this->_core->_map_split[i][j] == 'O') {
                std::shared_ptr<Model3D> brick = this->_tools->newModel(
                    this->_core->getCurrentScreen(),
                    "../assets/Box/brique.obj", "../assets/Box/textures/wood3.png",
                    { static_cast<float>(x), .0f, static_cast<float>(y) },
                    { .5f, .5f, .5f }, { 1.0f, 0.0f, 0.0f },
                    -90.0f
                );
                this->_destroyables.push_back(brick);
            }
        }
    }
    for (int i = 0; i < this->_core->_players_load_infos.size(); i++)
    {
        std::vector<std::string> data = Utils::split(this->_core->_players_load_infos[i], ' ');

        this->_core->_players[i]->isBot = std::stoi(data[0]);
        this->_core->_players[i]->isDead = std::stoi(data[1]);
        this->_core->_players[i]->lives = std::stoi(data[2]);
        this->_core->_players[i]->model->setX(std::stoi(data[3]));
        this->_core->_players[i]->model->setZ(std::stoi(data[4]));
        if (this->_core->_players[i]->isDead)
            this->_core->_players[i]->dead();
    }
}

void Game::initMap()
{
    this->initMapFloor();
    this->initMapWalls();
}

void Game::closeAllObjects()
{
    for (int i = 0; i < this->_bombs->size(); i++)
        *(*this->_bombs.get())[i]->explode = true;
    for (int i = 0; i < this->_fires.size(); i++)
        *this->_fires[i]->explode = true;
    for (int i = 0; i < this->_speeds.size(); i++)
        *this->_speeds[i]->explode = true;
    for (int i = 0; i < this->_detonators.size(); i++)
        *this->_detonators[i]->explode = true;
    for (int i = 0; i < this->_recovBombs.size(); i++)
        *this->_recovBombs[i]->explode = true;
    for (int i = 0; i < this->_recovLifes.size(); i++)
        *this->_recovLifes[i]->explode = true;
}
