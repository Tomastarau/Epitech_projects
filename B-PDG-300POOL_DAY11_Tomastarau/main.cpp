/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD11-tom.bouisset
** File description:
** main
*/

#include "DirectoryLister.hpp"
#include "SafeDirectoryLister.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void myLs(const std::string& directory) {
    try {
        SafeDirectoryLister dl(directory, false);
        std::cout << directory << ":" << std::endl;
        for (std::string file = dl.get(); true; file = dl.get())
            std::cout << file << std::endl;
    } catch (const IDirectoryLister::NoMoreFileException& e) {
        return;
    }
    throw std::runtime_error("should not happen");
}

int main(void) {
    try {
        myLs("./test/");
        myLs("./not_exist/");
        myLs("./test/");
    } catch (const IDirectoryLister::OpenFailureException& e) {
        std::cerr << "failure: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "unexpected error: " << e.what() << std::endl;
    }
    return 0;
}