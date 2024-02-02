/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my.h"
#include <stdio.h>

void array_1d_print_chars(char const* arr);
void array_1d_print_ints(int const *arr, int size);
int array_1d_sum(int const *arr, int size);
int array_2d_sum(int **arr, int nb_rows, int nb_cols);

int main (void)
{
    int **tab = malloc(sizeof(int *) * 3);
    tab[0] = malloc(sizeof(int) * 4);
    tab[1] = malloc(sizeof(int) * 4);
    tab[2] = NULL;

    tab[0][0] = 10;
    tab[0][1] = 10;
    tab[0][2] = 10;
    tab[0][3] = 10;

    tab[1][0] = 10;
    tab[1][1] = 10;
    tab[1][2] = 10;
    tab[1][3] = 10;

    int disp[2][4] = {
    {10, 11, 12, 13},
    {14, 15, 16, 17}
};
    printf("%d\n", array_2d_sum(tab, 2, 4));
    return 0;
    }
