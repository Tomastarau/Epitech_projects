/*
** EPITECH PROJECT, 2023
** my_str_to_word_array_2_2
** File description:
** my_str_to_word_array_2_2
*/

#include <stdlib.h>
#include <stdio.h>

int is_a_character_2(char c)
{
    if ((c > ' ' && c <= '~')) {
        return 1;
    } else if (c < 0 || c > 127) {
        return 2;
    } else {
        return 0;
    }
}

int	count_word_number_2(char const *str)
{
    if (!str){
        return 84;
    }
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0') {
        if (((is_a_character_2(str[a]) == 1 && is_a_character_2(str[a + 1]) \
== 0)) || ((is_a_character_2(str[a]) == 2 && is_a_character_2(str[a + 1]) \
== 0)) || ((is_a_character_2(str[a]) == 2 && is_a_character_2(str[a + 1]) \
== 1)) || ((is_a_character_2(str[a]) == 1 && is_a_character_2(str[a + 1]) \
== 2))){
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

int len_of_word_2(char const *str, int i)
{
    if (!str){
        return 84;
    }
    int a = i;
    while (str[i] != '\0') {
            if (is_a_character_2(str[i]) != 1){
                    return (i - a);
            }
            i++;
    }
    return (i - a);
}

int space_correction_2(char const *str, int i)
{
    if (!str){
        return 84;
    }
    while (is_a_character_2(str[i]) != 1){
        i++;
    }
    return i;
}

char **my_str_to_word_array_2(char const *str)
{
    int y = count_word_number_2(str);
    char **result = malloc(sizeof(char *) * (y + 1));
    int a = space_correction_2(str, 0), b = 0, c = 0;
    while (b < y){
        c = 0;
        result[b] = malloc(sizeof(char) * (len_of_word_2(str, a) + 1));
        while (str[a] != '\0' && is_a_character_2(str[a]) != 0) {
            result[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        result[b][c] = '\0';
        a = space_correction_2(str, a);
        b = b + 1;
    }
    result[b] = NULL;
    return result;
}
