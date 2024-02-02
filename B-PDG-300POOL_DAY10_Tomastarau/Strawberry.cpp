/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Strawberry
*/

#include "Strawberry.hpp"

Strawberry::Strawberry(const std::string &name, unsigned int vitamins)
    :   ABerry(name, vitamins) {}

Strawberry::~Strawberry()
{
}

std::ostream& Strawberry::print(std::ostream& os) const {
    os << "[name: \"" << getName() << "\", vitamins: " << getVitamins() << ", peeled: " << (isPeeled() ? "true" : "false") << "]";
    return os;
}