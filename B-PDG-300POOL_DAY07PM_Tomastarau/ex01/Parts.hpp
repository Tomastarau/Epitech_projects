/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07pm-tom.bouisset
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>
#include <iostream>

class Arms {
    public:
        Arms(std::string serial = "A-01", bool functional = true);
        ~Arms();
        bool isFunctional() const;
        std::string serial() const;
        void information() const;

    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial = "L-01", bool functional = true);
        ~Legs();
        bool isFunctional() const;
        std::string serial() const;
        void information() const;

    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial = "H-01", bool functional = true);
        ~Head();
        bool isFunctional() const;
        std::string serial() const;
        void information() const;

    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
