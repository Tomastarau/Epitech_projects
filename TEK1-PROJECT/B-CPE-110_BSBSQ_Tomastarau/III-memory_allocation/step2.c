/*
** EPITECH PROJECT, 2022
** step2 III
** File description:
** step 2 III
*/
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **array = malloc(sizeof(char *) * nb_rows + 1);

    while (i != nb_rows){
        array[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    return (array);
}