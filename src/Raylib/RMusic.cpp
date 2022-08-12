/*
** EPITECH PROJECT, 2022
** RMusic
** File description:
** RMusic
*/

#include "RMusic.hpp"

RMusic::RMusic(std::string path)
{
    this->music = LoadMusicStream(path.c_str());
}

RMusic::~RMusic()
{
}

void RMusic::PlayMusicStreamE()
{
    SetMusicVolume(this->music, 0.08f);
    PlayMusicStream(this->music);
}

void RMusic::UpdateMusicStreamE()
{
    UpdateMusicStream(this->music);
}

void RMusic::StopMusicStreamE()
{
    StopMusicStream(this->music);
}

float RMusic::GetMusicTimePlayedE()
{
    return GetMusicTimePlayed(this->music);
}

float RMusic::GetMusicTimeLengthE()
{
    return GetMusicTimeLength(this->music);
}
