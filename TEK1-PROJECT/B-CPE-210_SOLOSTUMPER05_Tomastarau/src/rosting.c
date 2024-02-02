/*
** EPITECH PROJECT, 2023
** stumper4 functions
** File description:
** stumper4 fonction
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int len_of_tab(char** tab)
{
    int i = 0;
    while (tab[i] != NULL){
        i++;
    }
    return i;
}

int rotate_string(char **rev_tab, int len_tab)
{
    int i = 0;
    if (write(1, rev_tab[len_tab - 1], my_strlen(rev_tab[len_tab - 1])) \
== -1 || write(1, " ", 1) == -1) {
        return 84;
    }
    while (i != len_tab - 2) {
        if (write(1, rev_tab[i], my_strlen(rev_tab[i])) == -1 || \
write(1, " ", 1) == -1) {
            return 84;
        }
        i++;
    }
    return 0;
}

int reverse(char* str)
{
    int len_tab = 0;
    char **rev_tab = my_str_to_word_array_2(str);
    len_tab = len_of_tab(rev_tab);
    if (!str) {
        return 84;
    }
    if (len_tab == 1) {
        if (write(1, rev_tab[0], my_strlen(rev_tab[0])) == -1) {
            return 84;
        }
        return 0;
    }
    if ((rotate_string(rev_tab, len_tab)) == 84){
        return 84;
    }
    if (write(1, rev_tab[len_tab - 2], my_strlen(rev_tab[len_tab - 2])) == -1) {
        return 84;
    }
    return 0;
}
