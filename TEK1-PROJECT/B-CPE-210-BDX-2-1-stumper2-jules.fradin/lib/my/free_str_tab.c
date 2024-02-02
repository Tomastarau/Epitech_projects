/*
** EPITECH PROJECT, 2022
** B-MUL-100-BDX-1-1-myradar-jules.fradin
** File description:
** free_str_tab
*/

#include <stdlib.h>

int free_str_tab(char **str_tab)
{
    int i = 0;
    while (str_tab[i] != NULL) {
        free(str_tab[i]);
        i++;
    }
    return 0;
}
