/*
** EPITECH PROJECT, 2023
** gdubernat
** File description:
** main functions
*/

#include "lib.h"

char **str_to_word_array(char *str, char *separator)
{
    if (str == NULL || separator == NULL)
        return NULL;
    char *pstr = my_strdup(str);
    char *token = strtok(pstr, separator);
    char **tab = NULL;
    int nb_words = count_words(str, separator);
    int i = 0;

    if (nb_words == -1 || separator == NULL)
        return NULL;
    tab = malloc(sizeof(char *) * (nb_words + 1));
    if (tab == NULL)
        return NULL;
    for (; token != NULL; i++) {
        if ((tab[i] = my_strdup(token)) == NULL)
            return NULL;
        token = strtok(NULL, separator);
    }
    tab[i] = NULL;
    return tab;
}
