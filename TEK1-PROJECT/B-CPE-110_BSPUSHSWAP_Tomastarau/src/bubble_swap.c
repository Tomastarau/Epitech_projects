/*
** EPITECH PROJECT, 2022
** bubble_swap
** File description:
** bubble swap
*/

#include "swap.h"
#include "printf.h"
#include "my.h"

int *swap_if(int * array, int y)
{
    int i = 0;
    if (array[y] > array[y + 1]){
        swap_elem(array, y, y + 1);
    }
    return array;
}

void bubble_sort_array(int *array , int size)
{
    int x, y, i;
    for (x = 0; x < size - 1 ; x++){
        for (y = 0; y < size - 1; y++){
            swap_if(array, y);
        }
    }
    my_printf("{");
    for (i = 0; i < size - 1; i++){
        my_printf("%d, ", array[i]);
    }
    my_printf("%d", array[size - 1]);
    my_printf("}");
    my_printf("\n");
}
