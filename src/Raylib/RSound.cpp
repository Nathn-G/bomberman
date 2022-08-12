/*
** EPITECH PROJECT, 2022
** indie
** File description:
** RSound
*/

#include "RSound.hpp"

RSound::RSound(std::string path)
{
    this->_sound = LoadSound(path.c_str());
}

RSound::~RSound()
{
    UnloadSound(this->_sound);
}

void RSound::Play()
{
    PlaySound(this->_sound);
}

void RSound::Stop()
{
    StopSound(this->_sound);
}

void RSound::Pause()
{
    PauseSound(this->_sound);
}

void RSound::Resume()
{
    ResumeSound(this->_sound);
}

void RSound::PlayMulti()
{
    PlaySoundMulti(this->_sound);
}

void RSound::StopMulti(void)
{
    StopSoundMulti();
}

int RSound::GetsPlaying(void)
{
    return (GetSoundsPlaying());
}

bool RSound::IsPlaying()
{
    return (IsSoundPlaying(this->_sound));
}

void RSound::SetVolume(float volume)
{
    SetSoundVolume(this->_sound, volume);
}
