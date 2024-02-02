/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <string>
#include <iostream>
#include "Icharacter.hpp"

class Peasant : public ICharacter{
    public:
        Peasant(const std::string& name, int power);
        ~Peasant();
        int attack() override;
        int special() override;
        void rest() override;
        void damage(int damage) override;
        const std::string &getName() const override;
        int getPower() const override;
        int getHp() const override;

    protected:
        const std::string &_name;
        int _power;
        int _Hp;
};

#endif /* !PEASANT_HPP_ */
