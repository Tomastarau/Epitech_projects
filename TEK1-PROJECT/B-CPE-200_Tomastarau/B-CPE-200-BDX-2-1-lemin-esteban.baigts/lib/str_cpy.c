/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_cpy
*/

#include "../include/str_utils.h"

char *str_cpy(char *dest, char const *src)
{
    char *ptr = dest;
    while (*src != 0) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = 0;
    return ptr;
}

char *strn_cpy(char *dest, char const *src, int n)
{
    int i = 0;
    for (; i < n; i++) {
        if (src[i] == 0)
            break;

        dest[i] = src[i];
    }

    for (; i < n; i++)
        dest[i] = 0;

    return dest;
}
