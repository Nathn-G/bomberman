/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** IModuleScreen
*/

#ifndef __IMODULESCREEN_HPP__
    #define __IMODULESCREEN_HPP__

    #include <iostream>
    #include <sstream>
    #include <map>
    #include <vector>
    #include <algorithm>
    #include <functional>
    #include "Core/CoreInfo.hpp"
    #include "Tools/Tools.hpp"
    #include "Menu/Particles/Particles.hpp"

class IModuleScreen {
    public:
        virtual ~IModuleScreen() = default;

        virtual void init(std::shared_ptr<CoreInfo> core, std::shared_ptr<Cam> camera) = 0;
        virtual void destroy() = 0;
        virtual void update() = 0;
        virtual void display() = 0;
        virtual void handleEvent() = 0;
};

#endif /* !IMODULESCREEN_HPP_ */
