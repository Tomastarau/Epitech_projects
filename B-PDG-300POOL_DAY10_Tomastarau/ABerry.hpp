/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
#define ABERRY_HPP_

#include "AFruit.hpp"

class ABerry : public AFruit{
    public:
        ABerry(const std::string &name, unsigned int vitamins);
        ~ABerry();
        bool isPeeled() const override;
};

#endif /* !ABERRY_HPP_ */
