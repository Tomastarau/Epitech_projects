/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "IFruit.hpp"

class FruitBox {
    public:
        FruitBox(unsigned int size);
        ~FruitBox();
        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit* fruit);
        IFruit* popFruit();
        std::ostream& print(std::ostream& os) const;

    private:
        unsigned int size;
        unsigned int count;
        IFruit** fruits;
};

std::ostream& operator<<(std::ostream& os, const FruitBox& box);

#endif /* !FRUITBOX_HPP_ */
