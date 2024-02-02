/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Almond
*/

#ifndef ALMOND_HPP_
#define ALMOND_HPP_

#include "ANut.hpp"

class Almond : public ANut{
    public:
        Almond(const std::string &name = "almond", unsigned int vitamins = 2);
        ~Almond();
        std::ostream& print(std::ostream& os) const override;
};

#endif /* !ALMOND_HPP_ */
