/*
** EPITECH PROJECT, 2022
** second file for move fonction
** File description:
** second file for move fonction
*/
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_sokoban.h"
#include "my.h"

void move_right_2(char **tab, sokomap_t *sokoban)
{
    char temp = ' ';

    if (tab[sokoban->P_x][sokoban->P_y + 1] != '#') {
        tab[sokoban->P_x][sokoban->P_y + 1] = 'P';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    }
}

void move_left_2(char **tab, sokomap_t *sokoban)
{
    char temp = ' ';
    if (tab[sokoban->P_x][sokoban->P_y - 1] != '#') {
        tab[sokoban->P_x][sokoban->P_y - 1] = 'P';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    }
}

void move_up_2(char **tab, sokomap_t *sokoban)
{
    char temp = ' ';
    if (tab[sokoban->P_x - 1][sokoban->P_y] != '#') {
        tab[sokoban->P_x - 1][sokoban->P_y] = 'P';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    }
}

void move_down_2(char **tab, sokomap_t *sokoban)
{
    char temp = ' ';
    if (tab[sokoban->P_x + 1][sokoban->P_y] != '#') {
        tab[sokoban->P_x + 1][sokoban->P_y] = 'P';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    }
}
