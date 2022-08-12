/*
** EPITECH PROJECT, 2022
** indie
** File description:
** KeyEvent
*/

#include "KeyEvent.hpp"

KeyEvent::KeyEvent()
{
}

void KeyEvent::setRaylib(std::shared_ptr<Raylib> raylib)
{
    this->_raylib = raylib;
}

void KeyEvent::addKeyEvent(CoreScreen CoreScreen, int key, std::function<void (int)> func)
{
    this->_ketMap[CoreScreen][key] = func;
}

void KeyEvent::addAnyEvent(CoreScreen CoreScreen, std::function<void(int)> func)
{
    this->_anyMap[CoreScreen] = func;
}

void KeyEvent::checkKeyEvent(CoreScreen screen)
{
    for (auto &CoreScreen : this->_ketMap) {
        for (auto &KeyEvent : CoreScreen.second) {
            if (CoreScreen.first == screen && this->_raylib->IsKeyPressedE(KeyEvent.first)) {
                KeyEvent.second(KeyEvent.first);
            }
        }
    }
    for (auto &keyEvent : this->_anyMap) {
        if (keyEvent.first == screen) {
            keyEvent.second(keyEvent.first);
        }
    }
}

KeyEvent::~KeyEvent()
{
}
