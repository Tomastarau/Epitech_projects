/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD10-tom.bouisset
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_

#include "IFruit.hpp"

class AFruit : public IFruit{
    public:
        AFruit(const std::string &name, unsigned int vitamins);
        ~AFruit();
        unsigned int getVitamins() const override;
        std::string getName() const override;
        bool isPeeled() const override;
        void peel() override;
        virtual std::ostream& print(std::ostream& os) const = 0;
    protected:
        std::string _name;
        unsigned int _vitamins;
        bool _isPeeled;
};

#endif /* !AFRUIT_HPP_ */
