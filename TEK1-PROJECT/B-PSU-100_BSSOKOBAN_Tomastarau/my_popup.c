/*
** EPITECH PROJECT, 2022
** my_popup
** File description:
** my_popup
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

int my_popup(char * affiche)
{
    char *msg = affiche;
    int taille = my_strlen(msg);
    int space;

    initscr ();
    while (TRUE) {
        clear();
        mvprintw(LINES / 2, (COLS / 2) - (taille / 2), msg);
        if ((space = getch()) == ' ')
            break;
    }
    endwin();
    return 0;
}
