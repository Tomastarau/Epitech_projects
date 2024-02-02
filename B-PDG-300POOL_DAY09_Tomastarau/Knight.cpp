/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Knight
*/

#include "Knight.hpp"


Knight::Knight(const std::string& name, int power) : Peasant(name, power) {
    std::cout << name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight() {
    std::cout << getName() << " takes off his armor." << std::endl;
}

int Knight::attack() {
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if (getPower() < 10) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
    std::cout << getName() << " strikes with his sword." << std::endl;
    _power -= 10;
    return 20;
}

int Knight::special()
{
    if(getHp() == 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }
    if((getPower() - 30) <= 0) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }
    std::cout << getName() << " impales his enemy." << std::endl;
    _power -= 30;
    return 50;
}

void Knight::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    _power = std::min(100, getPower() + 50);
    std::cout << getName() << " eats." << std::endl;
}
