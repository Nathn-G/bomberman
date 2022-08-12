/*
** EPITECH PROJECT, 2022
** indie
** File description:
** KeyEvent
*/

#ifndef KEYEVENT_HPP_
    #define KEYEVENT_HPP_

    #include "../Utils.hpp"
    #include "../Raylib/Raylib.hpp"
    #include <iostream>
    #include <map>
    #include <memory>
    #include <functional>

class KeyEvent {
    public:
        KeyEvent();
        void setRaylib(std::shared_ptr<Raylib> raylib);
        void addKeyEvent(CoreScreen CoreScreen, int key, std::function<void(int)> func);
        void addAnyEvent(CoreScreen CoreScreen, std::function<void(int)> func);
        void checkKeyEvent(CoreScreen CoreScreen);
        ~KeyEvent();

    private:
        std::map<CoreScreen, std::map<int, std::function<void(int)>>> _ketMap;
        std::map<CoreScreen, std::function<void(int)>> _anyMap;
        std::shared_ptr<Raylib> _raylib;
};

#endif /* !KEYEVENT_HPP_ */
