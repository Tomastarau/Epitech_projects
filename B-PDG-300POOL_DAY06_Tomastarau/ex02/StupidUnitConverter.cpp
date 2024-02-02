/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD06-tom.bouisset
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int main()
{
    std::string line, scale;
    double temperature;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        iss >> temperature >> scale;
        if (scale == "Fahrenheit") {
            temperature = (5.0 / 9.0) * (temperature - 32);
            scale = "Celsius";
        } else if (scale == "Celsius") {
            temperature = (9.0 / 5.0) * temperature + 32;
            scale = "Fahrenheit";
        } else {
            continue;
        }
        std::cout << std::setw(16) << std::right << std::fixed << std::setprecision(3)
          << temperature << std::setw(16) << scale << std::endl;

    }
    return 0;
}
