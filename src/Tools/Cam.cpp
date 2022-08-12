/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Cam
*/

#include "Cam.hpp"

Cam::Cam() : _clockAnim(ANIM_CLOCK_FRAME)
{
    this->_camera = {0};
    this->_camera.position = { 0.0f, 15.0f, 6.0f }; // Camera position
    this->_camera.target = { 0.0f, -2.0f, 0.0f };      // Camera looking at point
    this->_camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    this->_camera.fovy = 45.0f;                                // Camera field-of-view Y
    this->_camera.projection = CAMERA_PERSPECTIVE;            // Camera mode type
    this->_Mode3D = false;
    this->_isSet = false;
    this->_loopLeftAnim = 0;
    this->_inAnim = false;
}

void Cam::setPosition(Vector3 position)
{
    this->_camera.position = position;
}

void Cam::setTarget(Vector3 target)
{
    this->_camera.target = target;
}

void Cam::setUp(Vector3 up)
{
    this->_camera.up = up;
}

void Cam::setFovy(float fovy)
{
    this->_camera.fovy = fovy;
}

void Cam::setProjection(CameraProjection projection)
{
    this->_camera.projection = projection;
}

void Cam::update(CoreScreen screen)
{
    this->animate();
    if (this->_isSet == false) {
        SetCameraMode(this->_camera, CAMERA_FREE);
        this->_isSet = true;
    }
    UpdateCamera(&this->_camera);
}

Camera Cam::getCam()
{
    return (this->_camera);
}

void Cam::setAnim(Vector3 position, Vector3 target, float time)
{
    this->_clockAnim.reset();
    this->_inAnim = true;
    this->_animateClock = std::make_shared<Pclock>(time);
    this->_loopLeftAnim = time / ANIM_CLOCK_FRAME;
    this->_positionAnimTarget = position;
    this->_targetAnimTarget = target;
}

void Cam::animate()
{
    if (!this->_inAnim == true || !this->_clockAnim.check())
        return;
    if (this->_loopLeftAnim <= 0) {
        this->_inAnim = false;
        return;
    }
    this->_camera.position.x += (this->_positionAnimTarget.x - this->_camera.position.x) / this->_loopLeftAnim;
    this->_camera.position.y += (this->_positionAnimTarget.y - this->_camera.position.y) / this->_loopLeftAnim;
    this->_camera.position.z += (this->_positionAnimTarget.z - this->_camera.position.z) / this->_loopLeftAnim;

    this->_camera.target.x += (_targetAnimTarget.x - this->_camera.target.x) / this->_loopLeftAnim;
    this->_camera.target.y += (_targetAnimTarget.y - this->_camera.target.y) / this->_loopLeftAnim;
    this->_camera.target.z += (_targetAnimTarget.z - this->_camera.target.z) / this->_loopLeftAnim;

    this->_loopLeftAnim -= 1;
}

Cam::~Cam()
{
}