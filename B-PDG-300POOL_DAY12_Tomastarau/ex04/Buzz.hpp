/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy{
    public:
        Buzz(const std::string &name, const std::string &filename = "buzz.txt");
        void speak(const std::string &statement) override;
        ~Buzz();
};

#endif /* !BUZZ_HPP_ */
