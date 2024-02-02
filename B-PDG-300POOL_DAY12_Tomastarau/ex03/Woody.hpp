/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy{
    public:
        Woody(const std::string &name, const std::string &filename = "woody.txt");
        ~Woody(){};
        void speak(const std::string& statement) override;
};

#endif /* !WOODY_HPP_ */
