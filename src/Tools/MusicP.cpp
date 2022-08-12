/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Music
*/

#include "MusicP.hpp"

MusicP::MusicP(std::string path, bool loop) : _music(path)
{
    this->_loop = loop;
}

void MusicP::update()
{
    this->_music.UpdateMusicStreamE();
    if (this->_loop && this->_music.GetMusicTimePlayedE() >= this->_music.GetMusicTimeLengthE()) {
        this->_music.StopMusicStreamE();
        this->_music.PlayMusicStreamE();
    }
}

void MusicP::play()
{
    this->_music.PlayMusicStreamE();
}

void MusicP::stop()
{
    this->_music.StopMusicStreamE();
}

MusicP::~MusicP()
{
}
