/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-tom.bouisset
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial)
    : _serial(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")) {
        std::cout << "Droid '" << _serial << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other)
    : _serial(other._serial), _energy(other._energy), _attack(other._attack), _toughness(other._toughness), _status(new std::string(*(other._status))) {
        std::cout << "Droid '" << _serial << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete _status;
    std::cout << "Droid '" << _serial << "' Destroyed" << std::endl;

}

Droid& Droid::operator=(const Droid& other)
{
    if (this != &other) {
        _serial = other._serial;
        _energy = other._energy;
        if (_status != nullptr) {
            delete _status;
        }
        _status = new std::string(*(other._status));
    }
    return *this;
}

bool Droid::operator==(const Droid &other) const {
    return _serial == other._serial &&
           _energy == other._energy &&
           _attack == other._attack &&
           _toughness == other._toughness &&
           *(_status) == *(other._status);
}

bool Droid::operator!=(const Droid &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Droid &droid) {
    os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
    return os;
}

Droid& Droid::operator<<(size_t &energySource) {
    if (energySource > 1000) {
        energySource = 0;
    }
    if (_energy < 100) {
        size_t neededEnergy = 100 - _energy;
        size_t rechargeAmount = (energySource >= neededEnergy) ? neededEnergy : energySource;
        _energy += rechargeAmount;
        if (energySource > rechargeAmount) {
            energySource -= rechargeAmount;
        } else {
            energySource = 0;
        }
    }
    return *this;
}
