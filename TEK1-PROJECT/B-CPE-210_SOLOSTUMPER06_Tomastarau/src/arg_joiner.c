/*
** EPITECH PROJECT, 2023
** stumper4 functions
** File description:
** stumper4 fonction
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "stumper.h"

int len_of_tab(const char* tab[])
{
    int i = 0;
    if (!tab) {
        return -1;
    }
    while (tab[i] != NULL){
        if (!tab[i]) {
            return -1;
        }
        i++;
    }
    return i;
}

int arg_joiner_inner_loop(int i, const char* argv[], const char* sep, const \
char* final_sep)
{
    int len_tab = len_of_tab(argv);
    if (len_tab == -1) {
        return 84;
    }
    if (!sep || !final_sep)
        return 84;
    if (i < (len_tab - 4)) {
        if (write(1, argv[i], my_strlen(argv[i])) == -1 || write(1, sep, \
my_strlen(sep)) == -1) {
            return 84;
        }
        i++;
        return 0;
    }
    if (write(1, argv[i], my_strlen(argv[i])) == -1 || write(1, final_sep, \
my_strlen(final_sep)) == -1 || write(1, argv[i + 1], my_strlen(argv[i + \
1])) == -1) {
        return 84;
    }
    return 0;
}

int arg_joiner(const char* argv[])
{
    int i = 1;
    const char *sep = NULL;
    const char *final_sep = NULL;
    int len_tab = len_of_tab(argv);
    if (len_tab == -1) {
        return 84;
    }
    if (len_tab == 1 || len_tab == 2 || len_tab == 3){
        return 0;
    }
    sep = argv[len_tab - 2];
    final_sep = argv[len_tab - 1];
    while (i != len_tab - 3) {
        if (arg_joiner_inner_loop(i, argv, sep, final_sep) == 84)
            return 84;
        i++;
    }
    return 0;
}
