/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-tom.bouisset
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream file;
    std::string line;

    if (argc == 1) {
        while (std::getline(std::cin, line)) {
            std::cout << line << std::endl;
        }
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        file.open(argv[i]);
        if (!file) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            return 84;
        }
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    return 0;
}
