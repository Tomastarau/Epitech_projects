/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *load_file_in_mem(char const *filepath);

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);

char main (void)
{
    printf("%s", load_2d_arr_from_file("../map2.txt", 4, 11));
    return 0;

}