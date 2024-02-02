/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD09-tom.bouisset
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"


class Knight : virtual public Peasant {
public:
    Knight(const std::string& name, int power);
    ~Knight();

    int attack() override;
    int special() override;
    void rest() override;
};

#endif /* !KNIGHT_HPP_ */
