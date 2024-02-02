/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03
*/
#include <stdlib.h>

void my_putchar(char c);

int my_strlen(const char *str)
{
    int i = 0;
    if (!str)
        return -1;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
