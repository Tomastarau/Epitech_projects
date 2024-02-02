/*
** EPITECH PROJECT, 2023
** convert_tab
** File description:
** convert_tab
*/

#include <unistd.h>
#include "macro_errors.h"

static int display_line(const int *line, const char *to_display)
{
    char c;

    for (int i = 0; i < 3; i += 1) {
        c = to_display[line[i]];
        if (write(1, &c, 1) < 0)
            return ERROR;
    }
    if (write(1, "\n", 1) < 0)
        return ERROR;
    return SUCCESS;
}

int display_tab(const int **map, const char *to_display)
{
    if (!map || !to_display) {
        return ERROR;
    }
    for (int i = 0; i < 3; i += 1) {
        if (display_line(map[i], to_display) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
