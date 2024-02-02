/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
#define STRAWBERRY_HPP_

#include "ABerry.hpp"

class Strawberry : public ABerry {
    public:
        Strawberry(const std::string &name = "strawberry", unsigned int vitamins = 6);
        ~Strawberry();
        std::ostream& print(std::ostream& os) const override;
};

#endif /* !STRAWBERRY_HPP_ */
