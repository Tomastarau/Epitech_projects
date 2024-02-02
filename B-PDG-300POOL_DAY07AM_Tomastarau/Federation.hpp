/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-tom.bouisset
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"

namespace Federation {
    class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core* _core;
            bool _isStarfleet;

        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
    };

    namespace Starfleet {
        class Ship {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core* _core;

            public:
                Ship(int length, int width, std::string name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore();
        };
    }
}

#endif /* FEDERATION_HPP_ */


