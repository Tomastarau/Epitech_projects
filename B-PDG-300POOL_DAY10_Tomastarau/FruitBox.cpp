/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size) : size(size), count(0) {
    fruits = new IFruit*[size];
    for (unsigned int i = 0; i < size; ++i) {
        fruits[i] = nullptr;
    }
}

FruitBox::~FruitBox() {
    for (unsigned int i = 0; i < count; ++i) {
        delete fruits[i];
    }
    delete[] fruits;
}

unsigned int FruitBox::getSize() const {
    return size;
}

unsigned int FruitBox::nbFruits() const {
    return count;
}

bool FruitBox::pushFruit(IFruit* fruit) {
    if (count >= size || fruit == nullptr) {
        return false;
    }

    for (unsigned int i = 0; i < count; ++i) {
        if (fruits[i] == fruit) {
            return false;
        }
    }

    fruits[count++] = fruit;
    return true;
}

IFruit* FruitBox::popFruit() {
    if (count == 0) {
        return nullptr;
    }

    IFruit* poppedFruit = fruits[0];
    for (unsigned int i = 1; i < count; ++i) {
        fruits[i - 1] = fruits[i];
    }
    fruits[--count] = nullptr;

    return poppedFruit;
}

std::ostream& FruitBox::print(std::ostream& os) const {
    os << "[";
    for (unsigned int i = 0; i < count; ++i) {
        os << "[" << fruits[i]->getName() << "]";
        if (i < count - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FruitBox& box) {
    return box.print(os);
}
