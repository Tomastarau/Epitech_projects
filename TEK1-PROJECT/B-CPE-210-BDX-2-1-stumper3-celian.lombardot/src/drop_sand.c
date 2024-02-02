/*
** EPITECH PROJECT, 2023
** drop_sand
** File description:
** drop a grain and g=handle unstability
*/

#include <stddef.h>
#include "macro_errors.h"
#include "sandpile.h"

int drop_sand(int **map)
{
    int unstab_x = -1;
    int unstab_y = -1;
    int res = SUCCESS;

    if (map == NULL)
        return ERROR;

    map[1][1] += 1;
    while (res == SUCCESS) {
        res = locate_unstability((const int **)map, &unstab_x, &unstab_y);
        if (res == ERROR)
            return ERROR;
        if (res == FAILURE)
            return SUCCESS;

        if (distrib_grain(map, unstab_x, unstab_y) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
