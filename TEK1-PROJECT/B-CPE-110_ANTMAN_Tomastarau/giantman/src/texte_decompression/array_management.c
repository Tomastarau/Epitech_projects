/*
** EPITECH PROJECT, 2023
** array_management
** File description:
** array_management
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include "../../../include/my.h"
#include "../../../include/my_printf.h"
#include "../../../include/my_antman.h"

int my_strstrlen(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        i++;
    }
    return i;
}

char *concatenate_double_array_bis(char **tab, char **tab_of_dup, char *new_str)
{
    int i_output = 0;
    char *output = malloc(sizeof(char) * \
my_strlen(tab[my_strstrlen(tab_of_dup)]) - 1);
    for (int i = 1; i < my_strlen(tab[my_strstrlen(tab_of_dup)]); i++) {
            output[i_output] = tab[my_strstrlen(tab_of_dup)][i];
            i_output++;
    }
    my_strcat(new_str, output);
    return output;
}

char *concatenate_double_array_giant(char **tab, char **tab_of_dup)
{
    int strlen = 0, j = 0;
    char *new_str;
    for (int i = 0; tab[i] != NULL; i++){
        strlen = strlen + my_strlen(tab[i]);
        j++;
    }
    new_str = malloc(sizeof(char) * strlen);
    if (my_strcmp(tab[my_strstrlen(tab_of_dup)], "\n") == 0){
        for (int i = my_strstrlen(tab_of_dup) + 1; i < j; i++){
            my_strcat(new_str, tab[i]);
        }
    } else {
        concatenate_double_array_bis(tab, tab_of_dup, new_str);
        for (int i = my_strstrlen(tab_of_dup) + 1; i < j; i++){
            my_strcat(new_str, tab[i]);
        }
    }
    return new_str;
}
