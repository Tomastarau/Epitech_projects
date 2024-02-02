/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-tom.bouisset
** File description:
** Student
*/

#include "Student.hpp"
#include <iostream>
#include <algorithm>

Student::Student(const std::string &name) : name(name), energy(100)
{
    std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(const std::string &text)
{
    if (energy >= 42) {
        energy -= 42;
        std::cout << "Student " << name << ": " << text << std::endl;
        return true;
    } else {
        std::string modifiedText = text;
        size_t pos = 0;
        while ((pos = modifiedText.find("C++", pos)) != std::string::npos) {
            modifiedText.replace(pos, 3, "shit");
            pos += 4;
        }
        std::cout << "Student " << name << ": " << modifiedText << std::endl;
        return false;
    }
}

void Student::drink(const std::string &drinkName)
{
    if (drinkName == "Red Bull") {
        energy = std::min(energy + 32, 100);
        std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
    } else if (drinkName == "Monster") {
        energy = std::min(energy + 64, 100);
        std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
    } else {
        energy = std::min(energy + 1, 100);
        std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;
    }
}


