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

int is_character(char c)
{
    if ((c > ' ' && c <= '~')) {
        return 1;
    } else if (c < 0 || c > 127) {
        return 2;
    } else {
        return 0;
    }
}

char *concatenate_double_array(char **tab)
{
    int strlen = 0;
    int j = 0;
    char *new_str;
    for (int i = 0; tab[i] != NULL; i++){
        strlen = strlen + my_strlen(tab[i]);
        j++;
    }
    new_str = malloc(sizeof(char) * strlen);
    for (int i = 0; i < j; i++){
        my_strcat(new_str, tab[i]);
    }
    return new_str;
}

char *concatenate_double_array_of_dup(char **tab)
{
    int strlen = 0;
    int j = 0;
    char *new_str;
    for (int i = 0; tab[i] != NULL; i++){
        strlen = strlen + my_strlen(tab[i]);
        j++;
    }
    new_str = malloc(sizeof(char) * strlen);
    for (int i = 0; i < j - 1; i++){
        my_strcat(new_str, tab[i]);
        my_strcat(new_str, " ");
    }
    my_strcat(new_str, tab[j - 1]);
    my_strcat(new_str, "\n");
    return new_str;
}

int my_strstrlen(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        i++;
    }
    return i;
}
