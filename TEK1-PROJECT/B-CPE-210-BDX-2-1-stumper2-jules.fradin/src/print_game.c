/*
** EPITECH PROJECT, 2023
** ginger
** File description:
** print map
*/

#include <stddef.h>
#include <stdio.h>
#include "ginger.h"

int print_game(ginger_t *ginger_stats)
{
    if (printf("Tokens: %d/%d\n", ginger_stats->tokens,
        ginger_stats->total_tokens) == -1 || printf("Movement points: %d\n",
        ginger_stats->mv) == -1) {
        return 84;
    }
    for (int i = 0; ginger_stats->map[i + 1] != NULL; i++) {
        if (printf("%s\n", ginger_stats->map[i]) == -1) {
            return 84;
        }
    }
    if (printf("\n") == -1) return 84;
    return 0;
}
