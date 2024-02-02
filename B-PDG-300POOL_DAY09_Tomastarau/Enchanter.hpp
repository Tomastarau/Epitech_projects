/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : virtual public Peasant{
    public:
        Enchanter(const std::string& name, int power);
        ~Enchanter();
        int attack() override;
        int special() override;
        void rest() override;
};

#endif /* !ENCHANTER_HPP_ */
