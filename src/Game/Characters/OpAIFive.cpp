/*
** EPITECH PROJECT, 2022
** indie
** File description:
** OpAIFive
*/

#include "Player.hpp"

// E-D-C-B-A countdown for bomb out simulation
// 4-3-2-1-0 countdown for bomb in simulation

Vector2D Player::updateVector2DPosition(std::vector<std::string> map_split)
{
    int x = this->p_posi.x;
    int y = this->p_posi.z;

    if (p_posi.x - static_cast<int>(p_posi.x) <= -0.5)
        x -= 1;
    if (p_posi.x - static_cast<int>(p_posi.x) >= 0.5)
        x += 1;
    if (p_posi.z - static_cast<int>(p_posi.z) <= -0.5)
        y -= 1;
    if (p_posi.z - static_cast<int>(p_posi.z) >= 0.5)
        y += 1;
    x += map_split.at(0).size() / 2;
    if (map_split.size() % 2 == 0)
        x -= 1;
    y += map_split.size() / 2;
    return {x, y};
}

Vector2D Player::getNewVector2DPosition(Vector2D pos, AIAction action, std::vector<std::string> map)
{
    Vector2D dest = {0, 0};
    // std::cout << "\n\npos = {" << pos.x << ", " << pos.y << "}" << std::endl;
    // std::cout << "AIAction::" << action << std::endl;

    if (action == AIAction::LEFT) {
        // std::cout << "left " << pos.x << " " << pos.y << std::endl;
        dest.x = pos.x - 1;
        dest.y = pos.y;

    } else if (action == AIAction::RIGHT) {
        // std::cout << "right" << pos.x << " " << pos.y << std::endl;
        dest.x = pos.x + 1;
        dest.y = pos.y;
    } else if (action == AIAction::DOWN) {
        // std::cout << "down" << pos.x << " " << pos.y << std::endl;
        dest.x = pos.x;
        dest.y = pos.y + 1;
    } else if (action == AIAction::UP) {
        // std::cout << "up" << pos.x << " " << pos.y << std::endl;
        dest.x = pos.x;
        dest.y = pos.y - 1;
    }
    dest.x -= map.at(0).size() / 2;
    if (map.size() % 2 == 0)
        dest.x += 1;
    dest.y -= map.size() / 2;
    return dest;
}

void Player::updateAI(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, CoreScreen screen, std::shared_ptr<Tools> tools)
{
    Vector2D pos = updateVector2DPosition(map_split);

    if (newRecursive()) {
        AIAction action = recursive(pos, map_split, bombs);
        this->_lastMove = action;
        if (action == AIAction::NOTHING) {
            return;
        }
        if (action == AIAction::BOMB) {
            std::shared_ptr<Bomb> bomb = this->dropBomb(map_split, *bombs.get(), screen, tools);
            if (bomb != NULL) {
                bombs->push_back(bomb);
            }
        } else {
            this->_destination = getNewVector2DPosition(pos, action, map_split);
        }
    }
    moveAI(map_split);
}

void Player::moveAI(std::vector<std::string> map)
{
    float diffx = this->p_posi.x - (this->_destination.x + 0.1f);
    float diffy = this->p_posi.z - (this->_destination.y + 0.1f);
    bool haveMoved = false;

    if (diffx < 0 && -diffx >= *this->speed.get()) {
        moveRight(map);
        haveMoved = true;
    } 
    if (diffx >= 0 && diffx >= *this->speed.get()) {
        moveLeft(map);
        haveMoved = true;
    }
    if (diffy < 0 && -diffy >= *this->speed.get()) {
        moveDown(map);
        haveMoved = true;
    }
    if (diffy >= 0 && diffy >= *this->speed.get()) {
        moveUp(map);
        haveMoved = true;
    }
    if (!haveMoved)
        this->moveModel(map);
}

bool Player::newRecursive()
{
    if (this->_destination.x == 0 && this->_destination.y == 0)
        return (true);
    float diffx = this->p_posi.x - (this->_destination.x + 0.1f);
    float diffy = this->p_posi.z - (this->_destination.y + 0.1f);

    if (diffx < 0)
        diffx = diffx * -1;
    if (diffy < 0)
        diffy = diffy * -1;

    if (diffx < *this->speed.get() && diffy < *this->speed.get())
        return (true);
    return (false);
}

std::vector<std::string> Player::initMap(std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, std::vector<std::string> map) 
{
    Vector3 posBomb;
    std::string stringTime;

    this->_sizeLeft = map.at(0).size() / 2;
    this->_sizeTop = map.size() / 2;
    if (map.size() % 2 == 0) {
        this->_sizeLeft -= 1;
    }

    for (auto &bomb : *bombs.get()) {
        posBomb = bomb->model->getPosition();
        stringTime = bomb->getSecondAI();
        map[posBomb.z + this->_sizeTop][posBomb.x + this->_sizeLeft] = stringTime[0];
    }
    // for (auto line : map) {
    //     std::cout << line << std::endl;
    // }
    return (map);
}

AIAction Player::recursive(Vector2D pos, std::vector<std::string> map, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs)
{
    std::string warningBlock = "Ff#O";
    int simuLeft = 0;
    int simuRight = 0;
    int simuTop = 0;
    int simuBot = 0;
    int simuBomb = 0;

    
    std::vector<std::string> newMap = this->initMap(bombs, map);

    if (warningBlock.find(newMap[pos.y][pos.x - 1]) == std::string::npos && this->_lastMove != AIAction::RIGHT)
        simuLeft = recursiveLoop({pos.x - 1, pos.y}, newMap, 0, AIAction::LEFT);
    if (warningBlock.find(newMap[pos.y][pos.x + 1]) == std::string::npos && this->_lastMove != AIAction::LEFT)
        simuRight = recursiveLoop({pos.x + 1, pos.y}, newMap, 0, AIAction::RIGHT);
    if (warningBlock.find(newMap[pos.y - 1][pos.x]) == std::string::npos && this->_lastMove != AIAction::DOWN)
        simuTop = recursiveLoop({pos.x, pos.y - 1}, newMap, 0, AIAction::UP);
    if (warningBlock.find(newMap[pos.y + 1][pos.x]) == std::string::npos && this->_lastMove != AIAction::UP)
        simuBot = recursiveLoop({pos.x, pos.y + 1}, newMap, 0, AIAction::DOWN);
    if (warningBlock.find(newMap[pos.y][pos.x]) == std::string::npos && this->_lastMove != AIAction::BOMB)
        simuBomb = recursiveLoop({pos.x, pos.y}, newMap, 0, AIAction::BOMB);

    if (simuLeft >= simuRight && simuLeft >= simuTop && simuLeft >= simuBot && simuLeft >= simuBomb)
        return (AIAction::LEFT);
    if (simuRight >= simuLeft && simuRight >= simuTop && simuRight >= simuBot && simuRight >= simuBomb)
        return (AIAction::RIGHT);
    if (simuTop >= simuRight && simuTop >= simuLeft && simuTop >= simuBot && simuTop >= simuBomb)
        return (AIAction::UP);
    if (simuBot >= simuRight && simuBot >= simuTop && simuBot >= simuLeft && simuBot >= simuBomb)
        return (AIAction::DOWN);
    if (simuBomb >= simuRight && simuBomb >= simuTop && simuBomb >= simuBot && simuBomb >= simuLeft)
        return (AIAction::BOMB);
    return (AIAction::UP);
}

std::vector<std::string> Player::dupMap(std::vector<std::string> map)
{
    std::vector<std::string> newMap;
    for (int t = 0; t < map.size(); t++) {
        newMap.push_back(std::string (map[t]));
    }
    return (newMap);
}

int Player::recursiveLoop(Vector2D pos, std::vector<std::string> map, int deep, AIAction last)
{
    int simuLeft = 0;
    int simuRight = 0;
    int simuTop = 0;
    int simuBot = 0;
    int simuBomb = 0;

    if (deep > 10)
        return (0);
    std::shared_ptr<std::vector<std::string>> newMap = std::make_shared<std::vector<std::string>>(dupMap(map));
    if (last == AIAction::BOMB) {
        (*newMap.get())[pos.y][pos.x] = '4';
    }
    int curentScore = simulateMap(newMap) + POINT_PER_LOOP;
    std::string warningBlock = "Ff#O"; // if no warning charter is found go to simulation

    if ((*newMap.get())[pos.y][pos.x] == 'F' || (*newMap.get())[pos.y][pos.x] == 'f') {
        return (POINT_PER_DETH);
    }
    if (warningBlock.find((*newMap.get())[pos.y][pos.x - 1]) == std::string::npos) { // check left
        simuLeft = recursiveLoop({pos.x - 1, pos.y}, (*newMap.get()), deep + 1, AIAction::LEFT);
    }
    if (warningBlock.find((*newMap.get())[pos.y][pos.x + 1]) == std::string::npos) { // check right
        simuRight = recursiveLoop({pos.x + 1, pos.y}, (*newMap.get()), deep + 1, AIAction::RIGHT);
    }
    if (warningBlock.find((*newMap.get())[pos.y - 1][pos.x]) == std::string::npos) { // check top
        simuTop = recursiveLoop({pos.x, pos.y - 1}, (*newMap.get()), deep + 1, AIAction::UP);
    }
    if (warningBlock.find((*newMap.get())[pos.y + 1][pos.x]) == std::string::npos) { // check bot
        simuBot = recursiveLoop({pos.x, pos.y + 1}, (*newMap.get()), deep + 1, AIAction::DOWN);
    }
    if ((*newMap.get())[pos.y][pos.y] == ' ' && last != AIAction::BOMB) { // check bomb
        simuBomb = recursiveLoop({pos.x, pos.y}, (*newMap.get()), deep + 1, AIAction::BOMB);
    }

    int maxPoint = std::max({simuLeft, simuRight, simuTop, simuBot, simuBomb});

    return (maxPoint + curentScore);
}

int Player::simulateMap(std::shared_ptr<std::vector<std::string>> map) // decrement bomb end brek wall went bomb explotion
{
    int score = 0;
    for (int y = 0; y < map->size(); y++) {
        for (int x = 0; x < (*map.get())[y].size(); x++) {
            if ((*map.get())[y][x] == '0') {
                score += bombToFire({x, y}, map); // bomb of simulation
                continue;
            }
            if ((*map.get())[y][x] == 'A') {
                bombToFire({x, y}, map); // bomb out simulation
                continue;
            }
            if ((*map.get())[y][x] >= 49 && (*map.get())[y][x] <= 52)
                (*map.get())[y][x] = (*map.get())[y][x] - 1;
            if ((*map.get())[y][x] >= 66 && (*map.get())[y][x] <= 69)
                (*map.get())[y][x] = (*map.get())[y][x] - 1;
            if ((*map.get())[y][x] == 'f')
                (*map.get())[y][x] = ' ';
            if ((*map.get())[y][x] == 'F')
                (*map.get())[y][x] = 'f';
        }   
    }
    return (score);
}

int Player::bombToFire(Vector2D pos, std::shared_ptr<std::vector<std::string>> map) // check bomb explotion
{
    int score = 0;
    // std::cout << "explotion de map before" << std::endl;
    std::string warningBlock = "12345ABCDE";
    // for (auto line : (*map.get())) {
    //     std::cout << line << std::endl;
    // }
    (*map.get())[pos.y][pos.x] = 'F';

    for (int x = 0; x < 5; x++) { // fire right
        if ((*map.get())[pos.y][pos.x + x] == '#')
            break;
        if ((*map.get())[pos.y][pos.x + x] == 'O') {
            score += POINT_PER_BOX_BREK;
            (*map.get())[pos.y][pos.x + x] = 'F';
            break;
        }
        if (warningBlock.find((*map.get())[pos.y][pos.x + x]) != std::string::npos)
            score += bombToFire({pos.x + x, pos.y}, map);
        (*map.get())[pos.y][pos.x + x] = 'F';
    }
    for (int x = 0; x < 5; x++) { // fire left
        if ((*map.get())[pos.y][pos.x - x] == '#')
            break;
        if ((*map.get())[pos.y][pos.x - x] == 'O')
            score += POINT_PER_BOX_BREK;
        if (warningBlock.find((*map.get())[pos.y][pos.x - x]) != std::string::npos)
            score += bombToFire({pos.x - x, pos.y}, map);
        (*map.get())[pos.y][pos.x - x] = 'F';
    }
    for (int y = 0; y < 5; y++) { // fire bottom
        if ((*map.get())[pos.y + y][pos.x] == '#')
            break;
        if ((*map.get())[pos.y + y][pos.x] == 'O')
            score += POINT_PER_BOX_BREK;
        if (warningBlock.find((*map.get())[pos.y + y][pos.x]) != std::string::npos)
            score += bombToFire({pos.x, pos.y + y}, map);
        (*map.get())[pos.y + y][pos.x] = 'F';
    }
    for (int y = 0; y < 5; y++) { // fire top
        if ((*map.get())[pos.y - y][pos.x] == '#')
            break;
        if ((*map.get())[pos.y - y][pos.x] == 'O')
            score += POINT_PER_BOX_BREK;
        if (warningBlock.find((*map.get())[pos.y - y][pos.x]) != std::string::npos)
            score += bombToFire({pos.x, pos.y - y}, map);
        (*map.get())[pos.y - y][pos.x] = 'F';
    }
    // std::cout << "explotion de map" << std::endl;
    // for (auto line : (*map.get())) {
    //     std::cout << line << std::endl;
    // }
    return (score);
}