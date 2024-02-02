/*
** EPITECH PROJECT, 2023
** all fonction that does multiple fonction verif
** File description:
** multiple_command_verif
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

int detect_separator(const char *str)
{
    if (!str) {
        return -84;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] == ';') return 0;
        if (str[i] == '|') return 1;
        if (str[i] == '<') return str[i + 1] == '<' ? 5 : 2;
        if (str[i] == '>') return str[i + 1] == '>' ? 4 : 3;
    }
    return -1;
}

bool is_there_this_delimiter(char *str, char which_delimiter)
{
    if (!str) {
        return false;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] == which_delimiter) {
            return true;
        }
    }
    return false;
}

bool is_delimiter(char *str)
{
    const char *delimiters[] = {"|", ";", "<", ">", ">>", "<<", NULL};
    if (!str){
        return false;
    }
    for (int i = 0; delimiters[i] != NULL; i++) {
        if (my_strcmp(str, delimiters[i]) == 0) {
            return true;
        }
    }
    return false;
}

int is_builtin(const char *command)
{
    const char *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};
    if (!command) {
        return 1;
    }
    for (int i = 0; builtins[i] != NULL; i++) {
        if (my_strcmp(command, builtins[i]) == 0) {
            return 0;
        }
    }
    return 1;
}
