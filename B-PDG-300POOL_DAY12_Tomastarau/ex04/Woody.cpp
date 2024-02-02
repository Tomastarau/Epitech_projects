/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &filename)
    : Toy(Toy::WOODY, name, filename) {
}

void Woody::speak(const std::string& statement) {
    std::cout << "WOODY: " << getName() << " \"" << statement << "\"" << std::endl;
}