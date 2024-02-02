/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_

#include <string>
#include <exception>
#include <dirent.h>

class IDirectoryLister {
public:
    virtual ~IDirectoryLister() = default;
    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception {
    public:
        OpenFailureException(const std::string& message);
        const char* what() const noexcept;
    private:
        std::string _message;
    };

    class NoMoreFileException : public std::exception {
    public:
        const char* what() const noexcept;
    };
};

#endif /* IDIRECTORYLISTER_HPP_ */
