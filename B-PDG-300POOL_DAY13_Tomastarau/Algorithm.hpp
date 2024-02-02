/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <string>
#include <iostream>

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(const T a, const T b) {
    return (a < b) ? a : b;
}

template<typename T>
T max(const T a, const T b) {
    return (a < b) ? b : a;
}

template<typename T>
T clamp(const T& value, const T& min_val, const T& max_val) {
    if (value < min_val) {
        return min_val;
    }
    if (!(value < max_val)) {
        return max_val;
    }
    return value;
}


#endif // ALGORITHM_HPP

