/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "ACitrus.hpp"

class Lemon : public ACitrus{
    public:
        Lemon(const std::string &name = "lemon", unsigned int vitamins = 4);
        ~Lemon();
        std::ostream& print(std::ostream& os) const override;

};

#endif /* !LEMON_HPP_ */
