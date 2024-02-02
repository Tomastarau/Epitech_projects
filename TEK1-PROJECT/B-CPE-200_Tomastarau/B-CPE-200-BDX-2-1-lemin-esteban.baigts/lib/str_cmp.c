/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_cmp
*/

#include "../include/str_utils.h"

int str_cmp(char const *s1, char const *s2)
{
    if (str_len(s1) > str_len(s2))
        return 1;

    if (str_len(s1) < str_len(s2))
        return -1;

    int idx = 0;
    for (idx; s1[idx] == s2[idx]; idx++) {
        if (s2[idx] == 0)
            return 0;
    }

    return s1[idx] - s2[idx];
}
