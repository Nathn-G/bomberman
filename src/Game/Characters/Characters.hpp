/*
** EPITECH PROJECT, 2022
** Characters
** File description:
** Characters
*/

#ifndef __CHARACTERS_HPP__
    #define __CHARACTERS_HPP__

    #include "../../Tools/Model3D.hpp"

class Characters {
    public:
        Characters();
        ~Characters();
        virtual void moveModel(std::vector<std::string> _map_split) = 0;
        virtual void dead() = 0;
        std::shared_ptr<Model3D> model;
        bool isDead;
        bool isBot;

    protected:
    private:
};

#endif /* !__CHARACTERS_HPP__ */
