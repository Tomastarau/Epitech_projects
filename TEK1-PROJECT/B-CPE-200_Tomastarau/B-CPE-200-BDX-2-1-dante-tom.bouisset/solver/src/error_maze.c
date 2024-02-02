/*
** EPITECH PROJECT, 2023
** error_maze.c
** File description:
** handle the errors of the maze (map)
*/

#include "solver.h"
#include "my.h"
#include "my_printf.h"

int error_maze(char *filepath)
{
    for (int i = 0; filepath[i] != '\0'; i++) {
        if (filepath[i] != 'X' && filepath[i] != '*' && filepath[i] != '\n') {
            return 84;
        }
    }
    return 0;
}
