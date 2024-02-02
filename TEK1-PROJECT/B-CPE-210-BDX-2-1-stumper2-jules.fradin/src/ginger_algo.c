/*
** EPITECH PROJECT, 2023
** ginger algo
** File description:
** ginger algo
*/

#include <stdlib.h>
#include <stddef.h>
#include "ginger.h"

static int ginger_position(ginger_t *ginger_stats, coords_t *coord, int y)
{
    if (!ginger_stats->map){
        return (84);
    }
    for (int x = 0; ginger_stats->map[y][x] != '\0'; x++){
        if (ginger_stats->map[y][x] == 'G'){
            coord->x = x;
            coord->y = y;
            return 0;
        }
    }
    return 0;
}

static int ginger_scan_near(ginger_t *ginger_stats, coords_t *coord_g,
    int i_x, int i_y)
{
    if (!ginger_stats->map)
        return(84);
    if (ginger_stats->map[coord_g->y + i_y][coord_g->x + i_x] != '.'
    && ginger_stats->map[coord_g->y + i_y][coord_g->x + i_x] != 'G'){
        if (i_x != 0 && i_y !=0){
            ginger_stats->map[coord_g->y + i_y][coord_g->x] = 'G';
            ginger_stats->map[coord_g->y][coord_g->x] = '.';
            ginger_stats->mv--;
            print_game(ginger_stats);
            ginger_stats->map[coord_g->y + i_y][coord_g->x] = '.';
        }
        if (ginger_stats->map[coord_g->y + i_y][coord_g->x + i_x] == 'T')
            ginger_stats->tokens++;
        if (ginger_stats->map[coord_g->y + i_y][coord_g->x + i_x] == 'F')
            ginger_stats->mv = ginger_stats->mv + ginger_stats->mv_init;
        ginger_stats->map[coord_g->y + i_y][coord_g->x + i_x] = 'G';
        ginger_stats->map[coord_g->y][coord_g->x] = '.';
        coord_g->y = coord_g->y + i_y;
        coord_g->x = coord_g->x + i_x;
        ginger_stats->mv--;
        return(print_game(ginger_stats));
    }
    return 0;
}

int ginger_algo(ginger_t *ginger_stats, coords_t *coord_g)
{
    if (!ginger_stats->map){
        return (84);
    }
    for (int y = 0; ginger_stats->map[y] != NULL; y++){
        if (ginger_position(ginger_stats, coord_g, y) == 84){
            return 84;
        }
    }
    for (int i_y = -1; i_y != 2; i_y++){
        for (int i_x = -1; i_x != 2; i_x++){
            ginger_scan_near(ginger_stats, coord_g, i_x, i_y);
        }
    }
    return 0;
}
