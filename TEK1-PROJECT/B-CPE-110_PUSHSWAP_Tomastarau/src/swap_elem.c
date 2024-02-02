/*
** EPITECH PROJECT, 2022
** swap element
** File description:
** swap element
*/

#include "swap.h"
#include "printf.h"
#include "my.h"

void swap_elem(int *array, int index1, int index2)
{
    int i1 = array[index1];
    int i2 = array[index2];
    array[index1] = i2;
    array[index2] = i1;
}
