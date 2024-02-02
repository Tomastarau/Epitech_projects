/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack() {
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() <= 0) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
    std::cout << getName() << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if(getHp() == 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if((getPower() - 50) <= 0) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
    std::cout << getName() << " casts a fireball." << std::endl;
    _power -= 50;
    return 99;
}

void Enchanter::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    if (getPower() <= 0) {
        std::cout << getName() << " is out of power." << std::endl;
        return;
    }
    _power = std::min(100, getPower() + 100);
    std::cout << getName() << " meditates." << std::endl;
}
