/*
** EPITECH PROJECT, 2023
** my_antman
** File description:
** my_antman
*/

#include "my.h"
#include "my_dante.h"
#include "my_printf.h"
#include "solver.h"

int solver(char *filepath)
{
    int height = height_maze(filepath);
    int widht = widht_maze(filepath);
    char *file_str = file_to_str(filepath);
    char **maze = my_str_array(file_str);
    if (error_maze(file_str) == 84) {
        write(2, "The maze must only contain 'X' and '*'.\n", 41);
        return 84;
    }
    a_star(maze);
    return 0;
}

int main(int argc, char **argv)
{
    return 0;
}
