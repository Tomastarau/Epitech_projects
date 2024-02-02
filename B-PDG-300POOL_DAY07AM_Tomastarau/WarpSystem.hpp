/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD07am-tom.bouisset
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        private:
            bool _stability = true;

        public:
            QuantumReactor() = default;
            bool isStable();
            void setStability(bool stability);
    };

    class Core {
        private:
            QuantumReactor *_coreReactor;

        public:
            Core(QuantumReactor *coreReactor);
            QuantumReactor* checkReactor();
    };
}

#endif /* !WARPSYSTEM_HPP_ */
