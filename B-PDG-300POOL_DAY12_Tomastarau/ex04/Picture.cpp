/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file) {
    getPictureFromFile(file);
}

Picture::Picture(const Picture& other) {
    copyData(other);
}

Picture::Picture()
    : data("") {}

Picture::~Picture() {

}

bool Picture::getPictureFromFile(const std::string &file) {
    std::ifstream inFile(file);
    if (!inFile) {
        data = "ERROR";
        return false;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    data = buffer.str();
    return true;
}

Picture& Picture::operator=(const Picture& other) {
    if (this != &other) {
        copyData(other);
    }
    return *this;
}

void Picture::copyData(const Picture& other) {
    data = other.data;
}