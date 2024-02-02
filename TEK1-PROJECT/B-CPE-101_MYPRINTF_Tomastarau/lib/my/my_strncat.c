/*
** EPITECH PROJECT, 2022
** mystrncat
** File description:
** task03
*/
#include <string.h>


int my_strlen(char const *str);


char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (i < nb && src[i] != '\0'){
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
