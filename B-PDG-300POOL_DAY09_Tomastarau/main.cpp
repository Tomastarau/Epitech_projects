/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** main
*/

#include <string>
#include <iostream>
#include "Icharacter.hpp"
#include "Peasant.hpp"
#include "Knight.hpp"
#include "Paladin.hpp"
#include "Priest.hpp"

int main ( void )
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    ICharacter *knight = new Knight("Arthur", 20);
    ICharacter *enchanter = new Enchanter("Merlin", 20);
    ICharacter *priest = new Priest("Trichelieu", 20);
    ICharacter *paladin = new Paladin("Uther", 99);
    enchanter->rest();
    priest->damage(21);
    std :: cout << paladin->getName() << ": "
    << paladin->getHp() << " health points , "
    << paladin->getPower() << "power points ."
    << std::endl;
    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;
}
