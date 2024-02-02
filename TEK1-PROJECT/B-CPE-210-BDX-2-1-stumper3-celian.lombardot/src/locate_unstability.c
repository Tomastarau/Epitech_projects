/*
** EPITECH PROJECT, 2023
** locate unstability if there_s one
** File description:
** locate_unstability
*/

#include <stddef.h>
#include "macro_errors.h"

static int check_line(const int *line, int *x)
{
    if (line == NULL || x == NULL)
        return ERROR;

    *x = -1;

    for (int i = 0; i < 3; i += 1) {
        if (line[i] >= 4) {
            *x = i;
            return SUCCESS;
        }
    }
    return FAILURE;
}

int locate_unstability(const int **map, int *x, int *y)
{
    int res = 0;

    if (map == NULL || x == NULL || y == NULL)
        return ERROR;

    *y = -1;

    for (int i = 0; i < 3; i += 1) {
        res = check_line(map[i], x);
        if (res == ERROR)
            return ERROR;
        if (res == SUCCESS) {
            *y = i;
            return SUCCESS;
        }
    }
    return FAILURE;
}
