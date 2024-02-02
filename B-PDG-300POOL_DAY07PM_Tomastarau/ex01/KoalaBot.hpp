/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07pm-tom.bouisset
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <string>
#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(const Arms& arms);
        void setParts(const Legs& legs);
        void setParts(const Head& head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations() const;
        bool status() const;

    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
    };

#endif /* !KOALABOT_HPP_ */
