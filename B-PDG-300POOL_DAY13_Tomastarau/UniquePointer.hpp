/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** UniquePointer
*/

// UniquePointer.hpp

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

template<typename Type>
class UniquePointer {
public:
    explicit UniquePointer(Type* ptr = nullptr) : pointer(ptr) {}

    ~UniquePointer() {
        delete pointer;
    }

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& moving) noexcept : pointer(moving.pointer) {
        moving.pointer = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& moving) noexcept {
        if (this != &moving) {
            delete pointer;
            pointer = moving.pointer;
            moving.pointer = nullptr;
        }
        return *this;
    }

    void reset() {
        delete pointer;
        pointer = nullptr;
    }

    Type* get() const {
        return pointer;
    }

    Type* operator->() const {
        return pointer;
    }

    Type& operator*() const {
        return *pointer;
    }

    UniquePointer& operator=(Type* rawPointer) {
        if (pointer != rawPointer) {
            delete pointer;
            pointer = rawPointer;
        }
        return *this;
    }

private:
    Type* pointer;
};

#endif // UNIQUEPOINTER_HPP
