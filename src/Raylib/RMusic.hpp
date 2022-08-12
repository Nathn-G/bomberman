/*
** EPITECH PROJECT, 2022
** RMusic
** File description:
** RMusic
*/

#ifndef __RMUSIC_HPP__
    #define __RMUSIC_HPP__

    #include "raylib.h"
    #include <iostream>

class RMusic {
    public:
        RMusic(std::string path);
        ~RMusic();
        void PlayMusicStreamE();
        void UpdateMusicStreamE();
        void StopMusicStreamE();
        float GetMusicTimePlayedE();
        float GetMusicTimeLengthE();

    protected:
    private:
        Music music;
};

#endif /* !__RMUSIC_HPP__ */
