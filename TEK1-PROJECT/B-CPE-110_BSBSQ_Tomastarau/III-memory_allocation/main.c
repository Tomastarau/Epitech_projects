/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include <stdio.h>

char *mem_alloc(char const *a, char const *b);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);

int main (void)
{
    printf("%d\n", mem_alloc_2d_array(5, 10));
    return 0;
}
