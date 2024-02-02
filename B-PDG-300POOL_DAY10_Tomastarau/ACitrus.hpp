/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
#define ACITRUS_HPP_

#include "AFruit.hpp"

class ACitrus : public AFruit{
    public:
        ACitrus(const std::string &name, unsigned int vitamins);
        ~ACitrus();
};

#endif /* !ACITRUS_HPP_ */
