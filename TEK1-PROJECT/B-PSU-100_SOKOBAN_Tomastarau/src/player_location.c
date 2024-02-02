/*
** EPITECH PROJECT, 2022
** locate player fonction
** File description:
** locate player fonction
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_sokoban.h"
#include "my.h"

int if_index_is_player(char *tab, sokomap_t *sokoban, int i)
{
    int j = 0;
    while (tab[j] != '\0'){
        if (tab[j] == 'P'){
            sokoban->P_x = i;
            sokoban->P_y = j;
            return 1;
        }
        j++;
    }
    return 0;
}

int locate_player(char **tab, sokomap_t *sokoban)
{
    int i = 0;
    while (tab[i] != NULL){
        if (if_index_is_player(tab[i], sokoban, i) == 1){
            return 1;
        }
        if (if_index_is_player(tab[i], sokoban, i) == 84){
            write(2, "ERROR INVALID MAP\n", 19);
            exit(84);
        }
        i++;
    }
    write(2, "ERROR INVALID MAP\n", 19);
    exit(84);
}
