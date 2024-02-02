/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07pm-tom.bouisset
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include <string>

KoalaBot::KoalaBot(std::string serial)
        : _serial(serial)
{

}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

bool KoalaBot::status() const
{
    return _arms.isFunctional() && _legs.isFunctional() && _head.isFunctional();
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.information();
    _legs.information();
    _head.information();
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms temp = _arms;
    _arms = arms;
    arms = temp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs temp = _legs;
    _legs = legs;
    legs = temp;
}

void KoalaBot::swapParts(Head &head)
{
    Head temp = _head;
    _head = head;
    head = temp;
}
