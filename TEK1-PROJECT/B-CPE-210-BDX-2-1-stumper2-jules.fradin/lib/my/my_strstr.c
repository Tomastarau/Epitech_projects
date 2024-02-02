/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** find str in str
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int check = 0;
    int taille_str = 0;
    int taille_to_find = 0;

    while (to_find[taille_to_find] != '\0')
        taille_to_find++;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[check])
            check += 1;
        if (check == taille_to_find)
            return &str[i - check];
        if (str[i] != to_find[check])
            check = 0;
    }

    return NULL;
}
