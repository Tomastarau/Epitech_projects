/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit(const std::string &name, unsigned int vitamins)
    : _name(name), _vitamins(vitamins), _isPeeled(false) {}

AFruit::~AFruit() {}

unsigned int AFruit::getVitamins() const {
    return _isPeeled ? _vitamins : 0;
}

std::string AFruit::getName() const {
    return _name;
}

bool AFruit::isPeeled() const {
    return _isPeeled;
}

void AFruit::peel() {
    _isPeeled = true;
}
