/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string& name, int power)
    : _name(name), _power(power), _Hp(100) {
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

int Peasant::attack()
{
    if(_Hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if((_power - 10) <= 0) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << _name << " tosses a stone." << std::endl;
    _power -= 10;
    return 5;
}

int Peasant::special()
{
    if(_Hp == 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if(_power == 0) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (_Hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    _power = std::min(100, _power + 30);
    std::cout << _name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    _Hp = std::max(0, _Hp - damage);
    if (_Hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
    } else {
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    }
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _Hp;
}