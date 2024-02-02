/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int is_a_character(char c)
{
    if ((c > ' ' && c <= '~')) {
        return 1;
    } else if (c < 0 || c > 127) {
        return 2;
    } else {
        return 0;
    }
}

int	count_word_number(char const *str)
{
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0') {
        if (((is_a_character(str[a]) == 1 && is_a_character(str[a + 1]) == 0)) \
|| ((is_a_character(str[a]) == 1 && is_a_character(str[a + 1]) == 2)) \
|| ((is_a_character(str[a]) == 0 && is_a_character(str[a + 1]) == 1)) \
|| ((is_a_character(str[a]) == 0 && is_a_character(str[a + 1]) == 2)) \
|| ((is_a_character(str[a]) == 2 && is_a_character(str[a + 1]) == 1)) \
|| ((is_a_character(str[a]) == 2 && is_a_character(str[a + 1]) == 0))){
            b = b + 1;
        }
        a = a + 1;
    }
    if (str[a] == '\0' && is_a_character(str[a - 1]) == 0){
        b++;
    }
    return (b);
}

int len_of_word(char const *str, int i)
{
    int a = i;
    if (is_a_character(str[i]) == 1){
        while (is_a_character(str[i]) == 1 && str[i] != '\0'){
            i++;
        }
        return (i - a);
    }
    if (is_a_character(str[i]) == 0){
        while (is_a_character(str[i]) == 0 && str[i] != '\0'){
            i++;
        }
        return (i - a);
    }
    if (is_a_character(str[i]) == 2){
        while (is_a_character(str[i]) == 2 && str[i] != '\0'){
            i++;
        }
        return (i - a);
    }
}

int printable_then_unprintable(char *str, int i)
{
    if (is_a_character(str[i]) == 1 && is_a_character(str[i + 1]) == 1){
        return 1;
    }
    if (is_a_character(str[i]) == 0 && is_a_character(str[i + 1]) == 0){
        return 1;
    } else {
        return 0;
    }
}

char **my_str_to_word_array(char const *str)
{
    int	y = count_word_number(str);
    char **result = malloc(sizeof(char *) * y + 1);
    int	a = 0, b = 0, c = 0, len_word = 0;
    while (b < y){
        c = 0;
        result[b] = malloc(sizeof(char) * len_of_word(str, a) + 1);
        len_word = len_of_word(str, a);
        while (str[a] != '\0' && len_word > 0) {
            result[b][c] = str[a];
            c = c + 1;
            a = a + 1;
            len_word--;
        }
        result[b][c + 1] = '\0';
        b = b + 1;
    }
    result[b] == NULL;
    return (result);
    free(result);
}
