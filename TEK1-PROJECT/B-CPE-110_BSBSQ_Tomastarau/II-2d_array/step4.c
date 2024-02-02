/*
** EPITECH PROJECT, 2022
** step4 II
** File description:
** step4 II
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int row = 0;
    int col = 0;
    int somme = 0;

    while (row != nb_rows){
        while (col != nb_cols){
            somme = somme + arr[row][col];
            col++;
        }
        row++;
        col = 0;
    }
    return (somme);
}