/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** Stack
*/

// Stack.hpp

#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
#include <exception>

class Stack {
public:
    void push(double value);
    double pop();
    double top() const;
    void add();
    void sub();
    void mul();
    void div();
    class Error : public std::exception {
    private:
        const char* message;
    public:
        explicit Error(const char* msg) : message(msg) {}
        const char* what() const noexcept override { return message; }
    };

private:
    std::stack<double> data;
    void checkSizeForOperation() const;
};

#endif // STACK_HPP
