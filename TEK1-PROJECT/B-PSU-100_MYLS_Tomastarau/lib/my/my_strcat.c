/*
** EPITECH PROJECT, 2022
** my str cat
** File description:
** task02
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *final_str = malloc(sizeof(char) * src_len + dest_len + 1);
    int i = 0, j = 0;
    while (i < dest_len){
        final_str[i] = dest[i];
        i++;
    }
    while (j < src_len){
        final_str[i] = src[j];
        j++;
        i++;
    }
    final_str[src_len + dest_len] = '\0';
    return (final_str);
}
