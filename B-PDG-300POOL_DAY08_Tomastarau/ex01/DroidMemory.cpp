/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-tom.bouisset
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"
#include <cstdlib>

DroidMemory::DroidMemory()
    : _FingerPrint(rand()), _Exp(0){
}

DroidMemory::~DroidMemory() {
}

DroidMemory& DroidMemory::operator<<(const DroidMemory &other)
{
    _Exp += other._Exp;
    _FingerPrint ^= other._FingerPrint;
    return *this;
}

DroidMemory& DroidMemory::operator>>(DroidMemory &other)
{
    other._Exp += this->_Exp;
    other._FingerPrint ^= this->_FingerPrint;
    return other;
}

DroidMemory& DroidMemory::operator+=(const DroidMemory &other)
{
    *this << other;
    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t exp)
{
    _Exp += exp;
    _FingerPrint ^= exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &other) const
{
    DroidMemory newMemory = *this;
    newMemory += other;
    return newMemory;
}

DroidMemory DroidMemory::operator+(size_t exp) const
{
    DroidMemory newMemory = *this;
    newMemory += exp;
    return newMemory;
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &memory)
{
    os << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
    return os;
}
