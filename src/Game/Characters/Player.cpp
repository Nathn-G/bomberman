/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    this->speed = std::make_shared<float>(.05f);
    this->_sizeBox = 0.6;
    this->_destination = {0, 0};
    this->_isAi = false;
    this->_lastMove = AIAction::NOTHING;
    this->nb_bombs = std::make_shared<int>(3);
    this->can_be_touch = std::make_shared<bool>(true);
    this->lives = 1;
}

Player::~Player()
{
    for (int i = 0; i < this->threads.size(); i++)
        this->threads[i].join();
}

void Player::moveModel(std::vector<std::string> _map_split)
{
    this->p_posi = this->model.get()->getPosition();
    this->true_x = p_posi.x;
    this->true_z = p_posi.z;
    this->before_x = p_posi.x + _map_split.at(0).size() / 2;
    this->before_z = p_posi.z + _map_split.size() / 2;
    this->_sizeLeft = _map_split.at(0).size() / 2;
    this->_sizeTop = _map_split.size() / 2;

    if (_map_split.size() % 2 == 0) {
        this->before_x -= 1;
        this->_sizeLeft -= 1;
    }
    // std::cout << "this->_sizeLeft" << this->_sizeLeft << std::endl;
    if (p_posi.x - static_cast<int>(p_posi.x) <= -0.5)
        this->true_x -= 1;
    if (p_posi.x - static_cast<int>(p_posi.x) >= 0.5)
        this->true_x += 1;
    if (p_posi.z - static_cast<int>(p_posi.z) <= -0.5)
        this->true_z -= 1;
    if (p_posi.z - static_cast<int>(p_posi.z) >= 0.5)
        this->true_z += 1;
    this->true_x += _map_split.at(0).size() / 2;
    if (_map_split.size() % 2 == 0)
        this->true_x -= 1;
    this->true_z += _map_split.size() / 2;
    this->delta_x = p_posi.x - static_cast<int>(p_posi.x);
    this->delta_z = p_posi.z - static_cast<int>(p_posi.z);
}

bool Player::isSpeedBoosted()
{
    if (*this->speed == 0.07f)
        return (true);
    return (false);
}

void Player::dead()
{
    if (this->lives > 0) {
        if (*this->can_be_touch) {
            this->lives -= 1;
            this->threads.push_back(std::thread(this->recoverFromDamages, this->can_be_touch));
        }
        return;
    }
    this->model.get()->changeAnimation(5);
    this->isDead = true;
    this->model.get()->_loopAnimation = false;
    this->model.get()->resetAnimation();
}

Vector3 Player::getTruePos(std::vector<std::string> _map_split)
{
    Vector3 ret = this->model.get()->getPosition();
    int x = ret.x;
    int z = ret.z;

    if (ret.x - static_cast<int>(ret.x) <= -0.5)
        x -= 1;
    if (ret.x - static_cast<int>(ret.x) >= 0.5)
        x += 1;
    if (ret.z - static_cast<int>(ret.z) <= -0.5)
        z -= 1;
    if (ret.z - static_cast<int>(ret.z) >= 0.5)
        z += 1;
    if (_map_split.size() % 2 == 0)
        x -= 1;
    ret.x = x;
    ret.z = z;
    return (ret);
}

std::shared_ptr<Bomb> Player::dropBomb(std::vector<std::string> _map_split, std::vector<std::shared_ptr<Bomb>> _bombs, CoreScreen screen, std::shared_ptr<Tools> tools)
{
    if (!(*this->nb_bombs > 0))
        return (NULL);
    this->moveModel(_map_split);
    this->true_x -= _map_split.at(0).size() / 2;
    if (_map_split.size() % 2 == 0)
        this->true_x += 1;
    this->true_z -= _map_split.size() / 2;
    bool already = false;
    for (int i = 0; i < _bombs.size(); i++) {
        if (_bombs[i].get()->model->getPosition().x == this->true_x && _bombs[i].get()->model->getPosition().z == this->true_z)
            already = true;
    }
    if (!already)
    {
        std::shared_ptr<Bomb> bomba = std::make_shared<Bomb>();
        bomba.get()->model = tools.get()->newModel(
            screen,
            "../assets/Bomb/tnt/source/TNT/TNT.obj", "../assets/Bomb/tnt/source/TNT/TNT.png",
            {static_cast<float>(this->true_x), .0f, static_cast<float>(this->true_z)},
            {.04f, .04f, .04f}, {.0f, -2.5f, 0.0f},
            -90.0f);
        bomba.get()->setIndex(_bombs.size());
        this->threads.push_back(std::thread(this->recoverBomb, this->nb_bombs));
        return (bomba);
    }
    return (NULL);
}

bool Player::haveColitionWithPoint(Vector3 point, std::vector<std::string> _map_split)
{
    if (_map_split[point.z + this->_sizeTop][point.x + this->_sizeLeft] == ' ')
        return (false);
    return (true);
}

bool Player::haveColition(Vector3 newPos, std::vector<std::string> _map_split)
{
    for (int y = 0; y < _map_split.size(); y++) {
        for (int x = 0; x < _map_split[y].size(); x++) {
            if (haveColitionWithPoint(newPos, _map_split) || // check top left
                haveColitionWithPoint({ newPos.x, .0f, newPos.z + this->_sizeBox}, _map_split) || // check top right
                haveColitionWithPoint({ newPos.x + this->_sizeBox, .0f, newPos.z }, _map_split) || // check bot left
                haveColitionWithPoint({ newPos.x + this->_sizeBox, .0f, newPos.z + this->_sizeBox}, _map_split) ) { // check bot right
                return (true);
            }
        }
    }
    return (false);
}

void Player::moveLeft(std::vector<std::string> _map_split)
{
    this->moveModel(_map_split);
    Vector3 newPos = {(this->p_posi.x + 0.1f) - *this->speed.get(), 0, this->p_posi.z};
    if (!this->haveColition(newPos ,_map_split))
        this->model.get()->setX(this->model.get()->getPosition().x - *this->speed.get());
    this->model.get()->setRotationAngle(0.0f);
    this->model.get()->changeAnimation(0);
}

void Player::moveRight(std::vector<std::string> _map_split)
{
    this->moveModel(_map_split);
    Vector3 newPos = {(this->p_posi.x + 0.1f) + *this->speed.get(), 0, this->p_posi.z};
    if (!this->haveColition(newPos ,_map_split))
        this->model.get()->setX(this->model.get()->getPosition().x + *this->speed.get());
    this->model.get()->setRotationAngle(180.0f);
    this->model->changeAnimation(0);
}

void Player::moveUp(std::vector<std::string> _map_split)
{
    this->moveModel(_map_split);
    Vector3 newPos = {(this->p_posi.x + 0.1f), 0, this->p_posi.z - *this->speed.get() - *this->speed.get()};
    if (!this->haveColition(newPos ,_map_split))
        this->model.get()->setZ(this->model.get()->getPosition().z - *this->speed.get());
    this->model.get()->setRotationAngle(90.0f);
    this->model->changeAnimation(0);
}

void Player::moveDown(std::vector<std::string> _map_split)
{
    this->moveModel(_map_split);
    Vector3 newPos = {(this->p_posi.x + 0.1f), 0, this->p_posi.z + *this->speed.get()};
    if (!this->haveColition(newPos ,_map_split))
        this->model.get()->setZ(this->model.get()->getPosition().z + *this->speed.get());
    this->model.get()->setRotationAngle(-90.0f);
    this->model->changeAnimation(0);
}

void Player::updatePlayer()
{
    this->model->updateAnimation();
    if (this->isDead && this->model->isLastAnimation()) {
        this->model->_display = false;
    }
}
void Player::speedBoost()
{
    *this->speed = 0.07f;
    this->threads.push_back(std::thread(this->speedBoostTime, this->speed));
}

void Player::speedBoostTime(std::shared_ptr<float> speed)
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 5000) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    *speed = 0.05f;
}

void Player::recoverBomb(std::shared_ptr<int> nb_bombs)
{
    *nb_bombs = *nb_bombs - 1;
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 7000)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (*nb_bombs < 3)
        *nb_bombs = *nb_bombs + 1;
    if (*nb_bombs > 3)
        *nb_bombs = 3;
}

void Player::recoverFromDamages(std::shared_ptr<bool> can_be_touch)
{
    *can_be_touch = false;
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_start).count() < 2000)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    *can_be_touch = true;
}
