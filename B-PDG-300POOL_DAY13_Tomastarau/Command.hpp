#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <functional>
#include <map>
#include <exception>

class Command {
    public:
        void registerCommand(const std::string &name, const std::function<void()> &function);
        void executeCommand(const std::string &name);
        class Error : public std::exception {
            private:
                std::string message;
            public:
                explicit Error(const std::string& msg) : message(msg) {}
                const char* what() const noexcept override { return message.c_str(); }
        };
    private:
        std::map<std::string, std::function<void()>> commands;
};

#endif // COMMAND_HPP