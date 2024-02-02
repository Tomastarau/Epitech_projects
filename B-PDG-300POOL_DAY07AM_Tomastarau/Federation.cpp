/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-tom.bouisset
** File description:
** Federation
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include <iostream>

namespace Federation
{

    Ship::Ship(int length, int width, std::string name)
        : _length(length), _width(width), _name(name), _maxWarp(1), _core(nullptr), _isStarfleet(false)
        {
            std::cout << "The independent ship " << _name << " just finished its construction.\n"
                      << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
        }

    void Ship::setupCore(WarpSystem::Core *core) {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        if (_core && _core->checkReactor()->isStable()) {
            std::cout << _name << ": The core is stable at the time." << std::endl;
        } else {
            std::cout << _name << ": The core is unstable at the time." << std::endl;
        }
    }

    namespace Starfleet
    {

        Ship::Ship(int length, int width, std::string name, short maxWarp)
            : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _core(nullptr)
            {
                std::cout << "The ship USS " << _name << " has been finished.\n"
                          << "It is " << _length << " m in length and " << _width << " m in width.\n"
                          << "It can go to Warp " << _maxWarp << "!" << std::endl;
            }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            _core = core;
            std::cout << "USS " << _name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            if (_core && _core->checkReactor()->isStable()) {
                std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
            } else {
                std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
            }
        }
    }
}
