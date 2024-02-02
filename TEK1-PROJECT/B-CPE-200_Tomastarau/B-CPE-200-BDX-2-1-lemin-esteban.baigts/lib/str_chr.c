/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_chr
*/

#include "../include/str_utils.h"

char *str_chr(char const *str, int ch)
{
    if (!str)
        return 0;

    for (; *str; str++) {
        if (*str == ch)
            return (char *)str;
    }

    return 0;
}
