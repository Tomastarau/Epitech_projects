/*
** EPITECH PROJECT, 2022
** step 1 II
** File description:
** step 1 II
*/
#include <fcntl.h>
#include <unistd.h>
#include "my.h"


void array_1d_print_chars(char const* arr)
{
    int i = 0;
    while (arr[i] != '\0'){
        my_putchar(arr[i]);
        my_putchar('\n');
        i++;
    }
}