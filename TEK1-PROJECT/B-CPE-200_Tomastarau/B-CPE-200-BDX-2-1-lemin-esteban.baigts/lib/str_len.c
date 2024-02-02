/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_len
*/

#include "../include/str_utils.h"

int str_len(char const *str)
{
    if (!str)
        return 0;

    int ret = 0;
    for (; str[ret]; ret++);
    return ret;
}
