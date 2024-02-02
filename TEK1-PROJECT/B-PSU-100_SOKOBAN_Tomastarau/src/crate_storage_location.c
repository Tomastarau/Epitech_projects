/*
** EPITECH PROJECT, 2022
** crate storage location
** File description:
** crate storage location fonction
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_sokoban.h"
#include "my.h"

int locate_storage_pos(int nb_storage, char** tab, storage_pos_t **loc_storage)
{
    // (loc_storage[1])->S_y = 42;
    int i = 0, i_storage = 0, j = 0;

    while (tab[i] != NULL){
        while (tab[i][j] != '\0'){
            if (tab[i][j] == 'O'){
                printf("oui %d i: %d j: %d\n", i_storage, i ,j);
                (loc_storage[i_storage])->S_x = i;
                (loc_storage[i_storage])->S_y = j;
                i_storage++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return 1;
}

int if_index_is_storage(char *tab)
{
    int j = 0;
    int nb_storage = 0;
    while (tab[j] != '\0'){
        if (tab[j] == 'O'){
            nb_storage++;
        }
        j++;
    }
    return nb_storage;
}

int number_of_storage(char **tab)
{
    int i = 0;
    int nb_storage = 0;
    while (tab[i] != NULL){
        nb_storage = nb_storage + if_index_is_storage(tab[i]);
        i++;
    }
    if (nb_storage != 0)
        return nb_storage;
    write(2, "ERROR INVALID MAP\n", 19);
    exit(84);
}
