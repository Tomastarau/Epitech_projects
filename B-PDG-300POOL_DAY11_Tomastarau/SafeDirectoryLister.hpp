/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister();
        SafeDirectoryLister(const std::string& path, bool hidden);
        SafeDirectoryLister(const SafeDirectoryLister&) = delete;
        SafeDirectoryLister& operator=(const SafeDirectoryLister&) = delete;
        ~SafeDirectoryLister() override;
        bool open(const std::string& path, bool hidden) override;
        std::string get() override;

    private:
        std::string _path;
        bool _hidden;
        DIR* _dirStream;
        void closeDirectory();
    };

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
