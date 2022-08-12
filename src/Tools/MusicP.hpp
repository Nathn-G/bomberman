/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Music
*/

#ifndef MUSICP_HPP_
    #define MUSICP_HPP_

    #include "../Raylib/RMusic.hpp"

class MusicP {
    public:
        MusicP(std::string path, bool loop);
        ~MusicP();

        void update();
        void play();
        void stop();

        bool _loop;
    private:
        RMusic _music;
};

#endif /* !MUSIC_HPP_ */
