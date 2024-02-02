/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD08-tom.bouisset
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>

class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &other);
        bool isIdentical(const Droid &firstDroid, const Droid &secondDroid);
        ~Droid();
        Droid& operator=(const Droid& other);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        Droid& operator<<(size_t &energySource);

        std::string getId() const
        {
            return _serial;
        }

        size_t getEnergy() const
        {
            return _energy;
        }

        size_t getAttack() const
        {
            return _attack;
        }
        size_t getToughness() const
        {
            return _toughness;
        }

        std::string* getStatus() const
        {
            return _status;
        }

        void setId(const std::string& id)
        {
            _serial = id;
        }

        void setEnergy(size_t energy)
        {
            _energy = energy;
        }

        void setStatus(std::string* status) {
            if (_status != nullptr) {
                delete _status;
            }
            _status = status;
}

    private:
        std::string _serial;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string* _status;
};

std::ostream &operator<<(std::ostream &os, const Droid &droid);

#endif /* !DROID_HPP_ */
