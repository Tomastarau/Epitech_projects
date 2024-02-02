/*
** EPITECH PROJECT, 2023
** ginger.h
** File description:
** ginger.h
*/

#ifndef GINGER_
    #define GINGER_

typedef struct {
    int x;
    int y;
} coords_t;

typedef struct{
    char **map;
    int mv_init;
    int mv;
    int tokens;
    int total_tokens;
}ginger_t;

int ginger(int const argc, char *const *const argv);
int retrieve_args(int const argc, char *const *const argv,
    ginger_t *ginger_stats);
int print_game(ginger_t *ginger_stats);

int retrieve_token_number(ginger_t *ginger_stats);

int ginger_algo(ginger_t *ginger_stats, coords_t *coord_g);

#endif
