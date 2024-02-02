/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
    : _type(type), _name(name) {
    _picture.getPictureFromFile(filename);
}

Toy::Toy()
    : _type(BASIC_TOY), _name("toy") {
}

Toy::Toy(const Toy& other) 
    : _picture(other._picture), _type(other._type), _name(other._name) {
}

Toy::~Toy() {}

const std::string &Toy::getName() const {
    return _name;
}

Toy::ToyType Toy::getType() const {
    return _type;
}

void Toy::speak(const std::string &statement)
{
    std::cout << _name << " \"" << statement << "\"" <<std::endl;
}

const std::string &Toy::getAscii() const {
    return _picture.data;
}

bool Toy::setAscii(const std::string &filename) {
    return _picture.getPictureFromFile(filename);
}

void Toy::setName(const std::string &name) {
    _name = name;
}

Toy& Toy::operator=(const Toy& other) {
    if (this != &other) {
        _picture = other._picture;
        _type = other._type;
        _name = other._name;
    }
    return *this;
}
