/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** task01
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * len + 1);
    while (i < len){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
