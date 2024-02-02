/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD12-tom.bouisset
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <iostream>
#include <string>

class Toy {
public:
    enum ToyType { BASIC_TOY, ALIEN, BUZZ, WOODY };

    Toy();
    Toy(ToyType type, const std::string &name, const std::string &filename);
    Toy(const Toy& other);
    Toy& operator=(const Toy& other);
    ~Toy();

    ToyType getType() const;
    virtual void speak(const std::string &statement);
    const std::string& getName() const;
    const std::string& getAscii() const;
    bool setAscii(const std::string &filename);
    void setName(const std::string &name);

private:
    Picture _picture;
    ToyType _type;
    std::string _name;
};

#endif // TOY_HPP_
