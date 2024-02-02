/*
** EPITECH PROJECT, 2022
** move fonction
** File description:
** move fonction
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my_sokoban.h"
#include "my.h"

void move_right(char **tab, sokomap_t *sokoban, int key)
{
    char temp = ' ';
    if (tab[sokoban->P_x][sokoban->P_y + 1] == 'X' && \
tab[sokoban->P_x][sokoban->P_y + 2] == '#' || \
tab[sokoban->P_x][sokoban->P_y + 1] == 'X' && \
tab[sokoban->P_x][sokoban->P_y + 2] == 'X'){
        return;
    }
    if (tab[sokoban->P_x][sokoban->P_y + 1] == 'X' && \
tab[sokoban->P_x][sokoban->P_y + 2] != '#'){
        tab[sokoban->P_x][sokoban->P_y + 1] = 'P';
        tab[sokoban->P_x][sokoban->P_y + 2] = 'X';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    } else {
        move_right_2(tab, sokoban);
    }
}

void move_left(char **tab, sokomap_t *sokoban, int key)
{
    char temp = ' ';
    if (tab[sokoban->P_x][sokoban->P_y - 1] == 'X' && \
tab[sokoban->P_x][sokoban->P_y - 2] == '#' || \
tab[sokoban->P_x][sokoban->P_y - 1] == 'X' && \
tab[sokoban->P_x][sokoban->P_y - 2] == 'X'){
        return;
    }
    if ((key == KEY_LEFT) && tab[sokoban->P_x][sokoban->P_y - 1] \
== 'X' && tab[sokoban->P_x][sokoban->P_y - 2] != '#') {
        tab[sokoban->P_x][sokoban->P_y - 1] = 'P';
        tab[sokoban->P_x][sokoban->P_y - 2] = 'X';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    } else {
        move_left_2(tab, sokoban);
    }
}

void move_up(char **tab, sokomap_t *sokoban, int key)
{
    char temp = ' ';
    if (tab[sokoban->P_x - 1][sokoban->P_y] == 'X' && \
tab[sokoban->P_x - 2][sokoban->P_y] == '#' || \
tab[sokoban->P_x - 1][sokoban->P_y] == 'X' && \
tab[sokoban->P_x - 2][sokoban->P_y] == 'X'){
        return;
    }
    if ((key == KEY_UP) && tab[sokoban->P_x - 1][sokoban->P_y] \
== 'X' && tab[sokoban->P_x - 2][sokoban->P_y] != '#') {
        tab[sokoban->P_x - 1][sokoban->P_y] = 'P';
        tab[sokoban->P_x - 2][sokoban->P_y] = 'X';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    } else {
        move_up_2(tab, sokoban);
    }
}

void move_down(char **tab, sokomap_t *sokoban, int key)
{
    char temp = ' ';
    if (tab[sokoban->P_x + 1][sokoban->P_y] == 'X' && \
tab[sokoban->P_x + 2][sokoban->P_y] == '#' || \
tab[sokoban->P_x + 1][sokoban->P_y] == 'X' && \
tab[sokoban->P_x + 2][sokoban->P_y] == 'X'){
        return;
    }
    if ((key == KEY_DOWN) && tab[sokoban->P_x + 1][sokoban->P_y] \
== 'X' && tab[sokoban->P_x + 2][sokoban->P_y] != '#'){
        tab[sokoban->P_x + 1][sokoban->P_y] = 'P';
        tab[sokoban->P_x + 2][sokoban->P_y] = 'X';
        tab[sokoban->P_x][sokoban->P_y] = temp;
        show_map(tab);
        locate_player(tab, sokoban);
    } else {
        move_down_2(tab, sokoban);
    }
}

void analyse_event(char **tab, sokomap_t *sokoban, int key)
{
    keypad(stdscr, TRUE);
    if ((key == KEY_RIGHT) && tab[sokoban->P_x][sokoban->P_y + 1] \
!= '#'){
        move_right(tab, sokoban, key);
    }
    if ((key == KEY_LEFT) && tab[sokoban->P_x][sokoban->P_y - 1] \
!= '#'){
        move_left(tab, sokoban, key);
    }
    if ((key == KEY_UP) && tab[sokoban->P_x - 1][sokoban->P_y] \
!= '#'){
        move_up(tab, sokoban, key);
    }
    if ((key == KEY_DOWN) && tab[sokoban->P_x + 1][sokoban->P_y] \
!= '#' ) {
        move_down(tab, sokoban, key);
    }
    
}
