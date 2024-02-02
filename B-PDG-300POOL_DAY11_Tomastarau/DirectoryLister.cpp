/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
    : _path(path), _hidden(hidden), _dirStream(nullptr) {
    open(path, hidden);
}

DirectoryLister::DirectoryLister() : _hidden(false), _dirStream(nullptr) {}

DirectoryLister::~DirectoryLister() {
    if (_dirStream) {
        closedir(_dirStream);
    }
}

bool DirectoryLister::open(const std::string &path, bool hidden) {
    if (_dirStream) {
        closedir(_dirStream);
    }
    _dirStream = opendir(path.c_str());
    _hidden = hidden;
    if (!_dirStream) {
        perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get() {
    if (!_dirStream) return "";
    struct dirent *entry;
    while ((entry = readdir(_dirStream)) != nullptr) {
        std::string filename = entry->d_name;
        if (!_hidden && filename[0] == '.')
            continue;
        return filename;
    }
    return "";
}