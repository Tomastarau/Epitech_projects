/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_

#include <string>
#include <iostream>

class IFruit {
    public:
        virtual ~IFruit() = default;
        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;
        virtual std::ostream& print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const IFruit& fruit);

#endif /* !IFRUIT_HPP_ */
