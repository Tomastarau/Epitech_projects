/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD13-tom.bouisset
** File description:
** Command
*/


#include "Command.hpp"

void Command::registerCommand(const std::string& name, const std::function<void()>& function) {
    if (commands.find(name) != commands.end()) {
        throw Error("Already registered command");
    }
    commands[name] = function;
}

void Command::executeCommand(const std::string& name) {
    auto commandIterator = commands.find(name);
    if (commandIterator == commands.end()) {
        throw Error("Unknow command");
    }
    commandIterator->second();
}

