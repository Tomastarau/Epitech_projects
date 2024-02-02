/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string& name, int power)
    : Peasant(name, power), Enchanter(name, power){
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << getName() << " finds peace." << std::endl;
}

int Priest::attack() {
    return Enchanter::attack();
}

int Priest::special() {
    return Enchanter::special();
}

void Priest::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }
    _Hp = std::min(100, getHp() + 100);
    _power = std::min(100, getPower() + 100);
    std::cout << getName() << " prays." << std::endl;
}
