/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value) {
    data.push(value);
}

double Stack::pop() {
    if (data.empty()) {
        throw Error("Empty stack");
    }
    double topValue = data.top();
    data.pop();
    return topValue;
}

double Stack::top() const {
    if (data.empty()) {
        throw Error("Empty stack");
    }
    return data.top();
}

void Stack::add() {
    checkSizeForOperation();
    double a = pop();
    double b = pop();
    push(a + b);
}

void Stack::sub() {
    checkSizeForOperation();
    double a = pop();
    double b = pop();
    push(a - b);
}

void Stack::mul() {
    checkSizeForOperation();
    double a = pop();
    double b = pop();
    push(a * b);
}

void Stack::div() {
    checkSizeForOperation();
    double a = pop();
    double b = pop();
    if (a == 0) {
        throw Error("Division by zero");
    }
    push(a / b);
}

void Stack::checkSizeForOperation() const {
    if (data.size() < 2) {
        throw Error("Not enough operands");
    }
}

