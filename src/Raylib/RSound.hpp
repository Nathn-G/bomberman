/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Rsound
*/

#ifndef RSOUND_HPP_
    #define RSOUND_HPP_

    #include "raylib.h"
    #include <iostream>

class RSound {
    public:
        RSound(std::string path);
        ~RSound();
        void Play();
        void Stop();
        void Pause();
        void Resume();
        void PlayMulti();
        void StopMulti(void);
        int GetsPlaying(void);
        bool IsPlaying();
        void SetVolume(float volume);

    protected:
    private:
        Sound _sound;
};

#endif /* !RSOUND_HPP_ */
