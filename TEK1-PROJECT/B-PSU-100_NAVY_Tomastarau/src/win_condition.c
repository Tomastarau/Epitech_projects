/*
** EPITECH PROJECT, 2023
** win_condition.c
** File description:
** condition for a player to end the game, W or L
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/my_navy.h"

int if_x(char **map, int i, int j)
{
    if (map[i][j] == 'X') {
        return 1;
    }
    return 0;
}

int win_condition(char **map, char **argv)
{
    int result = 0;
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 10; j++) {
            result = result + if_X(map, i, j);
        }
    }
    if (result != 14) {
        return 1;
    }
    return 0;
}
