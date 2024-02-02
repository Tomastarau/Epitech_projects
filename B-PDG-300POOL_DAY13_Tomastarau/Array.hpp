/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** Array
*/

// Array.hpp

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <functional>

template<typename Type, std::size_t Size>
class Array {
    public:
        Array() : data() {}

        Type& operator[](std::size_t index) {
            if (index >= Size) {
                throw std::out_of_range("Out of range");
            }
            return data[index];
        }

        const Type& operator[](std::size_t index) const {
            if (index >= Size) {
                throw std::out_of_range("Out of range");
            }
            return data[index];
        }

        std::size_t size() const {
            return Size;
        }

        void forEach(const std::function<void(const Type&)>& task) const {
            for (std::size_t i = 0; i < Size; ++i) {
                task(data[i]);
            }
        }

        template <typename U>
        Array<U, Size> convert(const std::function<U(const Type&)>& converter) const {
            Array<U, Size> result;
            for (std::size_t i = 0; i < Size; ++i) {
                result[i] = converter(data[i]);
            }
            return result;
        }

    private:
        Type data[Size];
};

template<typename Type, std::size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& arr) {
    os << "[";
    for (std::size_t i = 0; i < Size; ++i) {
        os << arr[i];
        if (i < Size - 1) os << ", ";
    }
    os << "]";
    return os;
}

#endif // ARRAY_HPP
