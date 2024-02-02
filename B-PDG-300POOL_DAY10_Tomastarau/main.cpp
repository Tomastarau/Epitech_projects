/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** main
*/
#include <iostream>
#include "IFruit.hpp"
#include "AFruit.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"
#include "ANut.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Strawberry.hpp"
#include "Almond.hpp"

int main() {
    Orange o("Marvin", 21);
    IFruit& f = o;
    std::cout << f << std::endl;
}