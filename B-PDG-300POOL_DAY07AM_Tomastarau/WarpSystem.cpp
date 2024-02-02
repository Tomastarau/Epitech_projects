/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-tom.bouisset
** File description:
** WarpSystem
*/

#include "Federation.hpp"
#include <iostream>

namespace WarpSystem {
    bool QuantumReactor::isStable()
    {
        return _stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }

    Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor) {}

    QuantumReactor* Core::checkReactor() {
        return _coreReactor;
    }
}
