/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** main
*/
#include "Algorithm.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include "UniquePointer.hpp"
#include "Command.hpp"

int main (void)
{
    Command command;
    Stack stack;
    try {
        command.registerCommand("push", [&stack]() {stack.push(4.2);});
        command.registerCommand ("display", [&stack]() {std::cout << stack.top() <<
        std::endl;});
        command.registerCommand ("add", [&stack]() {stack.add();});
        command.registerCommand ("sub", [&stack]() {stack.sub();});
        command.registerCommand ("mul", [&stack]() {stack.mul();});
        command.registerCommand ("div", [&stack]() {stack.div();});
        command.registerCommand ("display", [](){});
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("add");
        command.executeCommand("div");
        command.executeCommand("display");
        command.executeCommand("nau");
    }
    catch ( const std :: exception & e ) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}