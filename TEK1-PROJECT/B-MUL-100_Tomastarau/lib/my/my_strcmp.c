/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/
#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    int  i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
