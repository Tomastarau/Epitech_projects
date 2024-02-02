/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** ABerry
*/

#include "ABerry.hpp"

ABerry::ABerry(const std::string &name, unsigned int vitamins)
    : AFruit(name, vitamins)
{
    _isPeeled = true;
}

ABerry::~ABerry()
{
}

bool ABerry::isPeeled() const {
    return _isPeeled;
}
