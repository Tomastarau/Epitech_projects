/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
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

int main (int argc, char** argv, char** env)
{
    char** new_env = create_new_env(env);
    if (argc != 1) {
        write(2, "too much arguments !\n", 22);
        return 84;
    }
    (void) argv;
    mysh(new_env);
    return 0;
}
