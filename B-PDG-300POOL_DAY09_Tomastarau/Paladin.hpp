/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string& name, int power);
        ~Paladin();
        int attack() override;
        int special() override;
        void rest() override;
};

#endif /* !PALADIN_HPP_ */
