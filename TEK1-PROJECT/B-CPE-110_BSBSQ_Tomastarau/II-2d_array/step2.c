/*
** EPITECH PROJECT, 2022
** step2 II 
** File description:
** step 2 II
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void array_1d_print_ints(int const *arr, int size)
{
    int i = 0;

    while (i != size){
        my_put_nbr(arr[i]);
        my_putstr("\n");
        i++;
    }
}