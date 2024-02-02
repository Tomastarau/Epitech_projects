/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** ANut
*/

#ifndef ANUT_HPP_
#define ANUT_HPP_

#include "AFruit.hpp"

class ANut : public AFruit{
    public:
        ANut(const std::string &name, unsigned int vitamins);
        ~ANut();
};

#endif /* !ANUT_HPP_ */
