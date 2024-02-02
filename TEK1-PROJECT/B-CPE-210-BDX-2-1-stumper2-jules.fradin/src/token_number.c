/*
** EPITECH PROJECT, 2023
** tokennumb
** File description:
** tokennumb
*/

#include <stddef.h>
#include "ginger.h"

static int token_numbers(ginger_t *ginger_stats, int y)
{
    if (!ginger_stats->map)
        return 84;
    for (int x = 0; ginger_stats->map[y][x] != '\0'; x++){
        if (ginger_stats->map[y][x] == 'T'){
            ginger_stats->total_tokens++;
            return 0;
        }
    }
    return 0;
}

int retrive_token_number(ginger_t *ginger_stats)
{
    if (ginger_stats->map)
        return 84;
    for (int y = 0; ginger_stats->map[y] != NULL; y++){
        if (token_numbers(ginger_stats, y) == 84)
            return 84;
    }
    return 0;
}
