/*
** EPITECH PROJECT, 2022
** my_popup
** File description:
** my_popup
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_sokoban.h"
#include "my.h"

int my_number_of_tab(char **array_tab)
{
    int i = 0;
    int compteur = 0;

    while (array_tab[i] != NULL){
        compteur++;
        i++;
    }
    return compteur;
}

void show_map(char **affiche)
{
    int i = 0, taille = my_strlen(affiche[i]), center = my_strlen(affiche[0]);
    char *msg;

    clear();
    while (affiche[i] != NULL){
        msg = affiche[i];
        mvprintw((LINES / 2) - (my_number_of_tab(affiche) / 2) + i,\
        (COLS / 2) - (center / 2), msg);
        refresh();
        i++;
    }
}

void check_cross_storage(storage_pos_t **loc_storage, int nb_storage, char **tab)
{
    int i =0;
    while (i != nb_storage){
        if (tab[loc_storage[nb_storage]->S_x][loc_storage[nb_storage]->S_y] == ' '){
            tab[loc_storage[nb_storage]->S_x][loc_storage[nb_storage]->S_y] == 'O';
        }
        nb_storage++;
    }
}

int my_sokoban(char **affiche)
{
    sokomap_t *sokoban = init_sokomap();
    int i = number_of_storage(affiche);
    storage_pos_t **storage_pos = init_storage_pos(i);
    if (storage_pos == NULL)
        return 84;
    int key;
    locate_player(affiche, sokoban);
    locate_storage_pos(i, affiche, storage_pos);
    WINDOW * win = initscr ();
    curs_set(0);
    keypad(stdscr, true);
    while (TRUE) {
        check_cross_storage(storage_pos, i, affiche);
        show_map(affiche);
        key = getch();
        if (key == ' ')
            break;
        analyse_event(affiche, sokoban, key);
        refresh();
    }
    endwin();
    return 0;
}
