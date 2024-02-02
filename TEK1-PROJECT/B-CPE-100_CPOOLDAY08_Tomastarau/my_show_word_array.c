/*
** EPITECH PROJECT, 2022
** MY SHOW ARRAY
** File description:
** SHOW ARRAY
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);

int my_show_word_array(char * const *tab)
{
    char *str;
    int i;
    int taillmem = 0;
    while (tab[i] != 0){
        taillmem = taillmem + my_strlen(tab[i]) + 1;
        i = i + 1;
    }
    i = 0;
    str = malloc(sizeof(char) * taillmem);
    while (tab[i] != 0){
        my_strcat(str, tab[i]);
        my_strcat(str, "\n");
        i = i + 1;
    }
    my_putstr(str);
    return (0);
}
