/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"

IDirectoryLister::OpenFailureException::OpenFailureException(const std::string &message)
    : _message(message) {
}

const char* IDirectoryLister::OpenFailureException::what() const noexcept {
    return _message.c_str();
}

const char* IDirectoryLister::NoMoreFileException::what() const noexcept {
    return "End of stream";
}