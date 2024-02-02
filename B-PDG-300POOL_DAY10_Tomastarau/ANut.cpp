/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** ANut
*/

#include "ANut.hpp"
#include "IFruit.hpp"
#include "Orange.hpp"
#include "Strawberry.hpp"
#include "Almond.hpp"

ANut::ANut(const std::string &name, unsigned int vitamins)
    : AFruit(name, vitamins) {}

ANut::~ANut()
{
}
