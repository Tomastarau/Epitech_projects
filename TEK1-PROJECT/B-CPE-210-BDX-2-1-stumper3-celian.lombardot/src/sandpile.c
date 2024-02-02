/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** sandpile
*/

#include <unistd.h>
#include <stdlib.h>
#include "sandpile.h"
#include "macro_errors.h"

static int get_nb(const char *str)
{
    int nb = 0;

    if (str == NULL)
        return -1;

    for (int i = 0; str[i] != '\0'; i += 1)
        nb = nb * 10 + (str[i] - '0');

    return nb;
}

static void free_tab(int **map)
{
    for (int i = 0; i < 3; i += 1)
        free(map[i]);
    free(map);
}

int sandpile(const char *argv[])
{
    int **map = NULL;
    int nb_turn = 0;

    if (argv == NULL)
        return ERROR;
    if ((nb_turn = get_nb(argv[3])) <= 0)
        return ERROR;

    if ((map = get_map(argv[1], argv[2])) == NULL)
        return ERROR;

    for (int i = 0; i < nb_turn; i += 1) {
        if (drop_sand(map) == ERROR)
            return ERROR;
    }

    if (display_tab((const int **)map, argv[2]) == ERROR)
        return ERROR;
    free_tab(map);
    return SUCCESS;
}
