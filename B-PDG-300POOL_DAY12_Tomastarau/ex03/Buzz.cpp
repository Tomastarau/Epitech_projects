/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &filename)
    : Toy(Toy::BUZZ, name, filename) {
}

Buzz::~Buzz() {
}

void Buzz::speak(const std::string &statement) {
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
}