/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/

#include <stdio.h>

int my_strlen(const char *str);

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i = i + 1;
    }
    if (i == n) {
        return 0;
    }
    if (s1[i] == '\0' && s2[i] != '\0') {
        return -1;
    }
    if (s1[i] != '\0' && s2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}
