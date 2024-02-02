/*
** EPITECH PROJECT, 2022
** str_array_good.c
** File description:
** take str into array
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int is_a_character(char c)
{
    if (c > ' ' && c <= '~') {
        return 1;
    }
    return 0;
}

int	count_word_number(char const *str)
{
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0'){
        if (is_a_character(str[a]) == 1 && is_a_character(str[a + 1]) == 0) {
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

int len_of_word(char const *str, int i)
{
    int a = i;
    while (str[i] != '\0') {
        if (is_a_character(str[i]) != 1) {
            return (i - a);
        }
        i++;
    }
    return (i - a);
}

char **my_str_array(char const *str)
{
    int	nb_word = count_word_number(str);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int	a = 0, c = 0;

    for (int i = 0; i < nb_word; i++) {
        c = 0;
        result[i] = malloc(sizeof(char) * len_of_word(str, a) + 1);
        while (str[a] != '\0' && is_a_character(str[a]) != 0) {
            result[i][c] = str[a];
            c++;
            a++;
        }
        result[i][c] = '\0';
        a++;
    }
    result[nb_word] = NULL;
    return (result);
    free(result);
}
