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
        explicit Picture(const std::string &file);
        Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
};

#endif /* !PICTURE_HPP_ */
