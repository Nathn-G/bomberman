/*
** EPITECH PROJECT, 2022
** Player
** File description:
** Player
*/

#ifndef __PLAYER_HPP__
    #define __PLAYER_HPP__

    #include "Characters.hpp"
    #include <algorithm>
    #include "../Items/Bomb.hpp"
    #include "../Items/Fire.hpp"
    #include "../../Utils.hpp"
    #include "../../Tools/Tools.hpp"
    #include <utility>
    #include <thread>
    #include <vector>

    enum AIAction {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        BOMB,
        NOTHING
    }; 

    typedef struct Vector2D {
        int x;
        int y;
    } Vector2D;

    // AI DEFINE
    #define POINT_PER_LOOP 10
    #define POINT_PER_DETH -5000
    #define POINT_PER_BOX_BREK 100

class Player : public Characters {
    public:
        Player();
        ~Player();

        void dead();
        std::shared_ptr<Bomb> dropBomb(std::vector<std::string> _map_split, std::vector<std::shared_ptr<Bomb>> _bombs, CoreScreen screen, std::shared_ptr<Tools> tools);

        void moveModel(std::vector<std::string> _map_split);
        void moveLeft(std::vector<std::string> _map_split);
        void moveRight(std::vector<std::string> _map_split);
        void moveUp(std::vector<std::string> _map_split);
        void moveDown(std::vector<std::string> _map_split);

        Vector3 getTruePos(std::vector<std::string> _map_split);
        void updatePlayer();

        void speedBoost();
        static void speedBoostTime(std::shared_ptr<float> speed);
        static void recoverBomb(std::shared_ptr<int> nb_bombs);
        static void recoverFromDamages(std::shared_ptr<bool> can_be_touch);
        bool isSpeedBoosted();
        std::shared_ptr<int> nb_bombs;
        int lives;
        int true_x;
        int true_z;

        // new
        bool haveColitionWithPoint(Vector3 point, std::vector<std::string> _map_split);
        bool haveColition(Vector3 newPos, std::vector<std::string> _map_split);


        // AI
        AIAction recursive(Vector2D pos, std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs);
        void updateAI(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, CoreScreen screen, std::shared_ptr<Tools> tools);
        bool newRecursive();
        void moveAI(std::vector<std::string> map);
        Vector2D updateVector2DPosition(std::vector<std::string> map_split);
        Vector2D getNewVector2DPosition(Vector2D position, AIAction action, std::vector<std::string> map);
        std::vector<std::string> initMap(std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, std::vector<std::string> map);
        int recursiveLoop(Vector2D pos, std::vector<std::string> map, int deep, AIAction last);
        int simulateMap(std::shared_ptr<std::vector<std::string>>);
        int bombToFire(Vector2D pos, std::shared_ptr<std::vector<std::string>>);
        std::vector<std::string> dupMap(std::vector<std::string> map);

        //AI 2
        void updateAI2(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, CoreScreen screen, std::shared_ptr<Tools> tools, std::vector<std::shared_ptr<Fire>> fires);
        bool needActionAI2();
        void moveAI2(std::vector<std::string> map);
        Vector2D getVector2DPosition(std::vector<std::string> map_split, Vector3 position);
        void replaceFireByWall(std::shared_ptr<std::vector<std::string>> map, std::vector<std::shared_ptr<Fire>> fires);
        void SetpathFinding(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        void setCharAround(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        void printMap(std::vector<std::string> map_split, std::string message);
        void setBombMapAI(std::shared_ptr<std::vector<std::string>> map, std::vector<std::shared_ptr<Bomb>> bombs);
        void printDropBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        Vector2D findPosToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        Vector2D testPosToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        bool checkNeedHide(std::vector<std::string> map, Vector2D pos);
        void replaceBombByWall(std::shared_ptr<std::vector<std::string>> map);
        Vector2D findPathToBomb(std::shared_ptr<std::vector<std::string>> map, Vector2D pos);
        AIAction AITakeDesition(std::vector<std::string> map_split, std::shared_ptr<std::vector<std::shared_ptr<Bomb>>> bombs, std::vector<std::shared_ptr<Fire>> fires);
        AIAction cordToAction(Vector2D pos, Vector2D dir);
        Vector2D getNeareSafe(std::shared_ptr<std::vector<std::string>> map);

        bool _isAi;
        AIAction _lastMove;
        Vector3 p_posi; // the true pos

    private:
        float before_x;
        float before_z;
        float delta_x;
        float delta_z;
        std::shared_ptr<bool> can_be_touch;
        std::shared_ptr<float> speed;
        std::vector<std::thread> threads;


        // new
        float _sizeBox;
        int _sizeLeft; // size at center to left
        int _sizeTop; // size at center to rigth

        // AI
        std::vector<Vector2D> _vdest;
        Vector2D _destination;
        bool goBomb;
};

#endif /* !__PLAYER_HPP__ */
