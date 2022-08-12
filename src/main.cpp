/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "Core/Core.hpp"
#include "AError.hpp"

int main(void)
{
    Core core;

    try {
        core.init();
        core.loop();
    } catch (Indie::AError &err) {
        err.printError();
        return (84);
    }

    return 0;
}