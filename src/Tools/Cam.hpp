/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Cam
*/

#ifndef CAM_HPP_
    #define CAM_HPP_
    #include "../Raylib/Raylib.hpp"
    #include "../Utils.hpp"
    #include "Pclock.hpp"
    #include <istream>
    #include <memory>

    #define ANIM_CLOCK_FRAME 0.001f

class Cam {
    public:
        Cam();
        ~Cam();

        void update(CoreScreen screen);
        Camera getCam();

        // seter
        void setPosition(Vector3 position);
        void setTarget(Vector3 target);
        void setUp(Vector3 up);
        void setFovy(float fovy);
        void setProjection(CameraProjection projection);
        void setAnim(Vector3 position, Vector3 target, float time);
        void animate();
        
    private:
        Camera _camera;
        bool _Mode3D;
        bool _isSet;
        std::shared_ptr<Pclock> _animateClock;
        Pclock _clockAnim;
        Vector3 _positionAnimTarget;
        Vector3 _targetAnimTarget;
        int _loopLeftAnim;
        bool _inAnim;
};

#endif /* !CAM_HPP_ */