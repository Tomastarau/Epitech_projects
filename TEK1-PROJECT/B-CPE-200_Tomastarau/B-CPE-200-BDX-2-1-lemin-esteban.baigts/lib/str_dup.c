/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_dup
*/

#include "../include/str_utils.h"
#include <stdlib.h>

char *str_dup(char const *src)
{
    int len = str_len(src);
    char *copy = malloc(len + 1);
    str_cpy(copy, src);
    return copy;
}
