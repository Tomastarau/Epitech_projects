/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Almond
*/

#include "Almond.hpp"

Almond::Almond(const std::string &name, unsigned int vitamins)
    : ANut(name, vitamins)
{
}

Almond::~Almond()
{
}

std::ostream& Almond::print(std::ostream& os) const {
    os << "[name: \"" << getName() << "\", vitamins: " << getVitamins() << ", peeled: " << (isPeeled() ? "true" : "false") << "]";
    return os;
}