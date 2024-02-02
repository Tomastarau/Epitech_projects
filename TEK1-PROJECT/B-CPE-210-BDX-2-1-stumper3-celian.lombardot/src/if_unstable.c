/*
** EPITECH PROJECT, 2023
** if hour glass is unstable
** File description:
** if_unstable
*/

#include <stddef.h>
#include "macro_errors.h"

int distrib_grain(int **map, int pos_x, int pos_y)
{
    if (!map) {
        return ERROR;
    }
    map[pos_y][pos_x] = 0;

    if (pos_x - 1 >= 0) {
        map[pos_y][pos_x - 1] += 1;
    }
    if (pos_x + 1 < 3) {
        map[pos_y][pos_x + 1] += 1;
    }
    if (pos_y - 1 > -1) {
        map[pos_y - 1][pos_x] += 1;
    }
    if (pos_y + 1 < 3) {
        map[pos_y + 1][pos_x] += 1;
    }
    return SUCCESS;
}
