/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
#define ORANGE_HPP_

#include "ACitrus.hpp"

class Orange : public ACitrus {
    public:
        Orange(const std::string &name = "orange", unsigned int vitamins = 7);
        ~Orange();
        std::ostream& print(std::ostream& os) const override;
};

#endif /* !ORANGE_HPP_ */
