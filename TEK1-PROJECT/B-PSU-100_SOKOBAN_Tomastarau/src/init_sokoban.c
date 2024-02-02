/*
** EPITECH PROJECT, 2022
** sokomap
** File description:
** sokomap
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "my_sokoban.h"

sokomap_t *init_sokomap(void)
{
    sokomap_t *sokoban = malloc(sizeof(sokomap_t));
    sokoban->P_x = 0;
    sokoban->P_y = 0;
    return sokoban;
}

storage_pos_t **init_storage_pos(int nb_storage)
{
    printf("nb_storage: %d\n", nb_storage);
    storage_pos_t **storage_loc = malloc(sizeof(storage_pos_t *) * (nb_storage + 1));
    if (storage_loc == NULL)
        return NULL;
    storage_loc[nb_storage] = NULL;

    for (int i = 0; i < nb_storage; i++) {
        storage_loc[i] = malloc(sizeof(storage_pos_t));
        if (storage_loc[i] == NULL)
            return NULL;
        storage_loc[i]->S_x = 0;
        storage_loc[i]->S_y = 0;
    }
    return storage_loc;
}
