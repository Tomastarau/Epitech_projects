/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils
*/

#include "my.h"

int my_strlen(const char *str)
{
    int len = 0;
    if (!str)
        return -1;
    while (str[len]){
        len++;
    }
    return len;
}
