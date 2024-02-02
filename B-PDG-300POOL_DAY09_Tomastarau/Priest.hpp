/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"
#include "Peasant.hpp"

class Priest : public Enchanter{
    public:
        Priest(const std::string& name, int power);
        ~Priest();
        int attack() override;
        int special() override;
        void rest() override;
};

#endif /* !PRIEST_HPP_ */
