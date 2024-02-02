

/*
** EPITECH PROJECT, 2023
** ginger
** File description:
** ginger
*/

#include <stdio.h>
#include <stdlib.h>
#include "ginger.h"
#include "my.h"

coords_t define_coord(void)
{
    coords_t coord_g = (coords_t){
        .y = 0,
        .x = 0,
    };
    return coord_g;
}

int ginger(int const argc, char *const *const argv)
{
    if (!argv){
        return 84;
    }
    ginger_t *ginger_stats = malloc(sizeof(ginger_t));
    coords_t coord_g = define_coord();
    if (retrieve_args(argc, argv, ginger_stats)) {
        return 84;
    }
    if (retrieve_token_number(ginger_stats)) return 84;
    if (print_game(ginger_stats)) return 84;
    while ((ginger_stats->total_tokens != ginger_stats->tokens) && (ginger_stats->mv != 0)) {
        ginger_algo(ginger_stats, &coord_g);
    }
    ginger_stats->mv == 0 ? printf("Ginger is too old for that!\n") : 0;
    (ginger_stats->total_tokens == ginger_stats->tokens) ? printf("Ginger never\
 loses!\n") : 0;
    if (free_str_tab(ginger_stats->map)) return 84;
    free(ginger_stats);
    return 0;
}
