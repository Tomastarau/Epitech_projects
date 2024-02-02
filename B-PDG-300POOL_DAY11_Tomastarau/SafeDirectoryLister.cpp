/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"
#include "IDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() : _hidden(false), _dirStream(nullptr) {}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden) : _path(path), _hidden(hidden), _dirStream(nullptr) {
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister() {
    closeDirectory();
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden) {
    closeDirectory();
    _dirStream = opendir(path.c_str());
    _hidden = hidden;

    if (!_dirStream) {
        throw IDirectoryLister::OpenFailureException("No such file or directory");
    }

    return true;
}

std::string SafeDirectoryLister::get() {
    if (!_dirStream) {
        return "";
    }

    struct dirent* entry;

    while ((entry = readdir(_dirStream)) != nullptr) {
        std::string filename = entry->d_name;

        if (!_hidden && filename[0] == '.') {
            continue;
        }

        return filename;
    }

    throw IDirectoryLister::NoMoreFileException();
}

void SafeDirectoryLister::closeDirectory() {
    if (_dirStream) {
        closedir(_dirStream);
        _dirStream = nullptr;
    }
}