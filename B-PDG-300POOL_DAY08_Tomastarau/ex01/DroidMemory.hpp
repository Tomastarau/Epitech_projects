/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-tom.bouisset
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>
#include <cstdlib>

class DroidMemory {
public:
    DroidMemory();
    ~DroidMemory();
    DroidMemory& operator<<(const DroidMemory &other);
    DroidMemory& operator>>(DroidMemory &other);
    DroidMemory& operator+=(const DroidMemory &other);
    DroidMemory operator+(const DroidMemory &other) const;
    DroidMemory& operator+=(size_t Exp);
    DroidMemory operator+(size_t Exp) const;
    size_t getFingerPrint() const { return _FingerPrint; }
    size_t getExp() const { return _Exp; }
    void setFingerPrint(size_t FingerPrint) { _FingerPrint = FingerPrint; }
    void setExp(size_t Exp) { _Exp = Exp; }

private:
    size_t _FingerPrint;
    size_t _Exp;
};

#endif /* !DROIDMEMORY_HPP_ */
