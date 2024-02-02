/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <string>
#include <exception>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister();
    ~DirectoryLister() override;
    DirectoryLister(const std::string &path, bool hidden);
    DirectoryLister(const DirectoryLister&) = delete;
    DirectoryLister& operator=(const DirectoryLister&) = delete;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

private:
    std::string _path;
    bool _hidden;
    DIR* _dirStream;
    void closeDirectory();
};

#endif /* !DIRECTORYLISTER_HPP_ */
