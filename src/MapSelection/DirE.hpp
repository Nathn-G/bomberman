/*
** EPITECH PROJECT, 2022
** DirE
** File description:
** DirE
*/

#ifndef __DIRE_HPP__
    #define __DIRE_HPP__

    #include <iostream>
    #include <dirent.h>

class DirE {
    public:
        DirE(std::string name);
        ~DirE();
        DIR *dir;
        struct dirent *dp;
        bool readdirE();
        std::string getName();

    protected:
    private:
};

#endif /* !__DIRE_HPP__ */
