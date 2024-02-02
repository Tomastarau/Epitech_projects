/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon(const std::string &name, unsigned int vitamins)
    : ACitrus(name, vitamins)
{
}

Lemon::~Lemon()
{
}

std::ostream& Lemon::print(std::ostream& os) const {
    os << "[name: \"" << getName() << "\", vitamins: " << getVitamins() << ", peeled: " << (isPeeled() ? "true" : "false") << "]";
    return os;
}