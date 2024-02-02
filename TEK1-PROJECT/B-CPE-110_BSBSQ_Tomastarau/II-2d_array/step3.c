/*
** EPITECH PROJECT, 2022
** step3 II
** File description:
** step3 II
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>

int array_1d_sum(int const *arr, int size)
{
    int i = 0;
    int somme = 0;
    while (i != size){
        somme = somme + arr[i];
        i++;
    }
    return (somme);
}