/*
** EPITECH PROJECT, 2022
** Utils
** File description:
** Utils
*/

#ifndef __UTILS_HPP__
    #define __UTILS_HPP__

    #include <iostream>
    #include <vector>

enum CoreScreen {
    MENU = 0,
    HOW_TO_PLAY,
    MAP_SELECTION,
    GAMEPLAY,
    ENDING,
    PAUSE,
    SETTINGS,
    LOADSAVE,
};

class Utils {
    public:
        static std::vector<std::string> split(std::string str, char delim);

    protected:
    private:
};

#endif /* !__UTILS_HPP__ */