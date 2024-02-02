/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <fstream>
#include <sstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        Picture(const Picture& other);
        Picture& operator=(const Picture& other);
        ~Picture();

        bool getPictureFromFile(const std::string &file);
        std::string data;

    private:
        void copyData(const Picture& other);
};

#endif // PICTURE_HPP_

