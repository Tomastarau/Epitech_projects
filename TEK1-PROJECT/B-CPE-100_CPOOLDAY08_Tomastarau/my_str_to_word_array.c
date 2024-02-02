/*
** EPITECH PROJECT, 2022
** my str to array
** File description:
** temp
*/
#include <unistd.h>

int my_strlen(char const *str);

int my_str_isalphanum(char const * str);

int len_tab(char *str)
{
    int i = 0;
    int nb_word = 0;
    while (i < my_strlen(str)){
        if (my_str_isalphanum(str[i]) && !my_str_isalphanum(str[i + 1])){
                nb_word = nb_word + 1;
        }
        i = i + 1;
    }
    return (nb_word);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int nb_tab = 0;
    char **final = malloc(sizeof(char*) * (nb_word + 1));
    while(nb_tab < len_tab){
        char * = malloc(sizeof(char) * my_strlen(final[nb_tab]));
        final[nb_tab][i] = 
    return (final_str);
}

