/*
** EPITECH PROJECT, 2022
** indie
** File description:
** OpAIFive2
*/

#include "Player.hpp"

void Player::setCharAround(std::shared_ptr<std::vector<std::string>> map, Vector2D pos)
{
    char charToSet = (*map.get())[pos.y][pos.x];

    if ((*map.get())[pos.y][pos.x + 1] != '#' && (*map.get())[pos.y][pos.x + 1] != 'O' && ((*map.get())[pos.y][pos.x + 1] < 48 || (*map.get())[pos.y][pos.x + 1] > 59)) {
        (*map.get())[pos.y][pos.x + 1] = charToSet + 1;
        this->setCharAround(map, {pos.x + 1, pos.y});
    }
    if ((*map.get())[pos.y][pos.x - 1] != '#' && (*map.get())[pos.y][pos.x - 1] != 'O' && ((*map.get())[pos.y][pos.x - 1] < 48 || (*map.get())[pos.y][pos.x - 1] > 59)) {
        (*map.get())[pos.y][pos.x - 1] = charToSet + 1;
        this->setCharAround(map, {pos.x - 1, pos.y});
    }
    if ((*map.get())[pos.y + 1][pos.x] != '#' && (*map.get())[pos.y + 1][pos.x] != 'O' && ((*map.get())[pos.y + 1][pos.x] < 48 || (*map.get())[pos.y + 1][pos.x] > 59)) {
        (*map.get())[pos.y + 1][pos.x] = charToSet + 1;
        this->setCharAround(map, {pos.x, pos.y + 1});
    }
    if ((*map.get())[pos.y - 1][pos.x] != '#' && (*map.get())[pos.y - 1][pos.x] != 'O' && ((*map.get())[pos.y - 1][pos.x] < 48 || (*map.get())[pos.y - 1][pos.x] > 59)) {
        (*map.get())[pos.y - 1][pos.x] = charToSet + 1;
        this->setCharAround(map, {pos.x, pos.y - 1});
    }
}

void Player::SetpathFinding(std::shared_ptr<std::vector<std::string>> map, Vector2D pos)
{
    (*map.get())[pos.y][pos.x] = '0';
    this->setCharAround(map, pos);
}

Vector2D Player::getVector2DPosition(std::vector<std::string> map_split, Vector3 position)
{
    int x = position.x;
    int y = position.z;

    if (position.x - static_cast<int>(position.x) <= -0.5)
        x -= 1;
    if (position.x - static_cast<int>(position.x) >= 0.5)
        x += 1;
    if (position.z - static_cast<int>(position.z) <= -0.5)
        y -= 1;
    if (position.z - static_cast<int>(position.z) >= 0.5)
        y += 1;
    x += map_split.at(0).size() / 2;
    if (map_split.size() % 2 == 0)
        x -= 1;
    y += map_split.size() / 2;
    return {x, y};
}

Vector2D Player::findPathToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos)
{
    Vector2D relatPos;
    relatPos.x = pos.x;
    relatPos.y = pos.y;


    if ((*map.get())[pos.y][pos.x] == '0')
        return (pos);
    for (int t = 20; t > 1; t--) {
        if ((*map.get())[relatPos.y][relatPos.x] == t + 48) {
            if ((*map.get())[relatPos.y][relatPos.x + 1] == t + 47)
                relatPos.x += 1;
            if ((*map.get())[relatPos.y][relatPos.x - 1] == t + 47)
                relatPos.x -= 1;
            if ((*map.get())[relatPos.y][relatPos.y + 1] == t + 47)
                relatPos.y += 1;
            if ((*map.get())[relatPos.y][relatPos.y - 1] == t + 47)
                relatPos.y -= 1;
        }
    }
    return (relatPos);
}

Vector2D Player::testPosToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos) // true is drop is posible
{
    std::shared_ptr<std::vector<std::string>> mapPAth = std::make_shared<std::vector<std::string>>(this->dupMap(*map.get()));
    SetpathFinding(mapPAth, pos);
    this->printDropBomb(mapPAth, pos);
    for (int y = 0; y < mapPAth->size(); y++) {
        for (int x = 0; x < (*mapPAth.get())[0].size(); x++) {
            if ((*mapPAth.get())[y][x] == '0' || (*mapPAth.get())[y][x] == '1' || (*mapPAth.get())[y][x] == '2' || (*mapPAth.get())[y][x] == '3') {
                return (findPathToBomb(mapPAth, {x, y}));
            }
        }
    }
    return {-1, -1};
}

Vector2D Player::findPosToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos)
{
    std::shared_ptr<std::vector<std::string>> mewMap = std::make_shared<std::vector<std::string>>(this->dupMap(*map.get()));
    SetpathFinding(mewMap, pos);
    for (int t = 0; t < 20; t++) {
        for (int y = 0; y < mewMap->size(); y++) {
            for (int x = 0; x < (*mewMap.get())[0].size(); x++) {
                if ((*mewMap.get())[y][x] == t + 48) {
                    if (testPosToBomb(map, {x, y}).x != -1) {
                        return {x, y};
                    }
                }
            }
        }
    }
    return {-1, -1};
}

void Player::replaceFireByWall(std::shared_ptr<std::vector<std::string>> map, std::vector<std::shared_ptr<Fire>> fires)
{
    Vector3 position;
    Vector2D pos2D;
    
    for (std::shared_ptr<Fire> fire : fires) {
        position = fire->model->getPosition();
        pos2D = this->getVector2DPosition(*map.get(), position);
        (*map.get())[pos2D.y][pos2D.x] = '#';
    }
}

void Player::setBombMapAI(std::shared_ptr<std::vector<std::string>> map, std::vector<std::shared_ptr<Bomb>> bombs)
{
    Vector3 position;
    Vector2D pos2D;
    
    for (std::shared_ptr<Bomb> bomb : bombs) {
        position = bomb->model->getPosition();
        pos2D = this->getVector2DPosition(*map.get(), position);
        this->printDropBomb(map, pos2D);
    }
}

void Player::printDropBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos)
{
    for (int x = 0; x < 5; x++) { // fire right
        if ((*map.get())[pos.y][pos.x + x] == '#' || (*map.get())[pos.y][pos.x + x] == 'O') {
            break;
        }
        (*map.get())[pos.y][pos.x + x] = '+';
    }
    for (int x = 0; x < 5; x++) { // fire left
        if ((*map.get())[pos.y][pos.x - x] == '#' || (*map.get())[pos.y][pos.x - x] == 'O')
            break;
        (*map.get())[pos.y][pos.x - x] = '+';
    }
    for (int y = 0; y < 5; y++) { // fire bottom
        if ((*map.get())[pos.y + y][pos.x] == '#' || (*map.get())[pos.y + y][pos.x] == 'O')
            break;
        (*map.get())[pos.y + y][pos.x] = '+';
    }
    for (int y = 0; y < 5; y++) { // fire top
        if ((*map.get())[pos.y - y][pos.x] == '#' || (*map.get())[pos.y - y][pos.x] == 'O')
            break;
        (*map.get())[pos.y - y][pos.x] = '+';
    }
    (*map.get())[pos.y][pos.x] = '+';
}

void Player::printMap(std::vector<std::string> map_split, std::string message)
{
    for (auto line : map_split) {
    }
}

void Player::replaceBombByWall(std::shared_ptr<std::vector<std::string>> map)
{
    for (int y = 0; y < map->size(); y++) {
        for (int x = 0; x < (*map.get())[0].size(); x++) {
            if ((*map.get())[y][x] == '+')
                (*map.get())[y][x] = '#';
        }
    }
}

AIAction Player::cordToAction(Vector2D pos, Vector2D dir)
{
    if (pos.x < dir.x)
        return (AIAction::RIGHT);
    if (pos.x > dir.x)
        return (AIAction::LEFT);
    if (pos.y > dir.y)
        return (AIAction::UP);
    if (pos.y < dir.y)
        return (AIAction::DOWN);
    return (AIAction::NOTHING);
}

Vector2D Player::getNeareSafe(std::shared_ptr<std::vector<std::string>> map)
{
    char nearChar = '0';

    for (int i = 0; i < 27; i++) {
        for (int y = 0; y < map->size(); y++) {
            for (int x = 0; x < (*map.get())[0].size(); x++) {
                if ((*map.get())[y][x] == nearChar)
                    return {x, y};
            }
        }
        nearChar += 1;
    }
    return {-1, -1};
}

AIAction Player::AITakeDesition(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, std::vector<std::shared_ptr<Fire>> fires)
{
    Vector2D pos = updateVector2DPosition(map_split);
    
    this->printMap(map_split, "map_split");
    std::shared_ptr<std::vector<std::string>> mapFire = std::make_shared<std::vector<std::string>>(this->dupMap(map_split));
    this->replaceFireByWall(mapFire, fires);

    std::shared_ptr<std::vector<std::string>> mapPath = std::make_shared<std::vector<std::string>>(this->dupMap(*mapFire.get()));
    this->SetpathFinding(mapPath, pos);
    std::shared_ptr<std::vector<std::string>> mapBomb = std::make_shared<std::vector<std::string>>(this->dupMap(*mapFire.get()));
    this->printMap(*mapBomb.get(), "before mapBomb");
    std::shared_ptr<std::vector<std::string>> run = std::make_shared<std::vector<std::string>>(this->dupMap(*mapBomb.get()));
    this->setBombMapAI(mapBomb, *bombs.get());
    this->printMap(*mapBomb.get(), "mapBomb");
    
    if (checkNeedHide(*mapBomb.get(), pos)) {
        std::shared_ptr<std::vector<std::string>> run = std::make_shared<std::vector<std::string>>(this->dupMap(*mapBomb.get()));
        this->SetpathFinding(run, pos);
        std::shared_ptr<std::vector<std::string>> runPath = std::make_shared<std::vector<std::string>>(this->dupMap(*run.get()));
        this->setBombMapAI(run, *bombs.get());
        Vector2D close = getNeareSafe(run);
        Vector2D poseNexto = findPathToBomb(runPath, close);
        this->printMap(*run.get(), "run after");
        return (cordToAction(pos, poseNexto));
    } else if (_vdest.size() == 0) {
        this->replaceBombByWall(mapBomb);
        Vector2D posBomb = findPosToBomb(mapBomb, pos);
        if (posBomb.x == -1)
            return (AIAction::NOTHING);
        if (posBomb.x == pos.x && posBomb.y == pos.y) {
            return (AIAction::BOMB);
        }
        return (this->cordToAction(pos, posBomb));
    }
    return (AIAction::NOTHING);
    // moveAI2(map_split);
}

void Player::updateAI2(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, CoreScreen screen, std::shared_ptr<Tools> tools, std::vector<std::shared_ptr<Fire>> fires)
{
    Vector2D pos = updateVector2DPosition(map_split);

    if (newRecursive()) {
        AIAction action = this->AITakeDesition(map_split, bombs, fires);
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

bool Player::checkNeedHide(std::vector<std::string> map, Vector2D pos)
{
    if (map[pos.y][pos.x] == '+')
        return (true);
    return (false);
}

bool Player::needActionAI2()
{
    if (this->_vdest.size() == 0)
        return (true);
    float diffx = this->p_posi.x - (this->_vdest[0].x + 0.1f);
    float diffy = this->p_posi.z - (this->_vdest[0].y + 0.1f);

    if (diffx < 0)
        diffx = diffx * -1;
    if (diffy < 0)
        diffy = diffy * -1;

    if (diffx < *this->speed.get() && diffy < *this->speed.get())
        this->_vdest.erase(this->_vdest.begin());
    if (this->_vdest.size() == 0)
        return (true);
    return (false);
}

void Player::moveAI2(std::vector<std::string> map)
{
    float diffx = this->p_posi.x - (this->_destination.x + 0.1f);
    float diffy = this->p_posi.z - (this->_destination.y + 0.1f);

    if (diffx < 0 && -diffx >= *this->speed.get()) { //RIGHT
        moveRight(map);
    } 
    if (diffx >= 0 && diffx >= *this->speed.get()) { //LEFT
        moveLeft(map);
    }
    if (diffy < 0 && -diffy >= *this->speed.get()) { //DOWN
        moveDown(map);
    }
    if (diffy >= 0 && diffy >= *this->speed.get()) { //UP
        moveUp(map);
    }
}
