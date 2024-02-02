/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-tom.bouisset
** File description:
** Student
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    Student(const std::string &name);

    ~Student();

    bool learn(const std::string &text);

    void drink(const std::string &drinkName);

private:
    std::string name;
    int energy;
};

#endif // STUDENT_HPP

