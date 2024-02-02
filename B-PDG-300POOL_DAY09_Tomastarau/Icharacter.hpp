/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Icharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>

class ICharacter {
public:
    ICharacter() {}
    virtual ~ICharacter() {}
    virtual int attack() = 0;
    virtual int special() = 0;
    virtual void rest() = 0;
    virtual void damage(int amount) = 0;
    virtual const std::string &getName() const = 0;
    virtual int getHp() const = 0;
    virtual int getPower() const = 0;
};

#endif // ICHARACTER_HPP_
