/*
** EPITECH PROJECT, 2022
** step1 III
** File description:
** step1 III
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *mem_alloc(char const *a, char const *b)
{
    int index = 0;
    int i = 0;
    char *string = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)));

    while (index != my_strlen(a)){
        string[index] = a[index];
        index++;
    }
    while (i != my_strlen(b)){
        string[index] = b[i];
        i++;
        index++;
    }
    return string;
}