/*
** EPITECH PROJECT, 2023
** maze_length.c
** File description:
** calculate the widht and height of the maze
*/

#include "solver.h"
#include "my.h"
#include "my_printf.h"

int height_maze(char *filepath)
{
    int result = 0;
    for (int i = 0; filepath[i] != '\0'; i++) {
        if (filepath[i] == '\n')
            result++;
    }
    return result;
}

int widht_maze(char *filepath)
{
    int result = 0;
    for (int i = 0; filepath[i] != '\n'; i++) {
        result++;
    }
    return result;
}
