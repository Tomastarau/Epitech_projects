/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** IFruit
*/

#include "IFruit.hpp"

unsigned int IFruit::getVitamins() const {
    return 0;
}

std::string IFruit::getName() const {
    return "";
}

bool IFruit::isPeeled() const {
    return false;
}

void IFruit::peel() {

}

std::ostream& IFruit::print(std::ostream& os) const {
    os << "IFruit: Default print";
    return os;
}

std::ostream& operator<<(std::ostream& os, const IFruit& fruit) {
    return fruit.print(os);
}