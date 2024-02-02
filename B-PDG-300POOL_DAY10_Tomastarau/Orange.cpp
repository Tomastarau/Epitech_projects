/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Orange
*/

#include "Orange.hpp"

Orange::Orange(const std::string &name, unsigned int vitamins)
    : ACitrus(name, vitamins) {}

Orange::~Orange()
{
}

std::ostream& Orange::print(std::ostream& os) const {
    os << "[name: \"" << getName() << "\", vitamins: " << getVitamins() << ", peeled: " << (isPeeled() ? "true" : "false") << "]";
    return os;
}