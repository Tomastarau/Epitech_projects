/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * len + 1);
    if (dest == NULL) {
        return NULL;
    }
    my_strcpy(dest, src);
    dest[len] = '\0';
    return dest;
}
