/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** parse_anthill
*/

#include "../include/anthill_parse.h"
#include "../include/parser.h"
#include "../include/lib.h"

static int parse_nb_ants(context_t *ctx)
{
    char *nb_ants_buffer = parser_get_next_line();
    if (nb_ants_buffer == 0)
        return -1;

    int nb_ants = str_to_num(nb_ants_buffer);
    free(nb_ants_buffer);
    if (nb_ants <= 0)
        return -1;

    ctx->nb_ants = nb_ants;
    return 0;
}

static int process_line(context_t *ctx, char *buffer)
{
    if (str_chr(buffer, '-') != 0) {
        if (parse_anthill_link(ctx, buffer) == -1)
            return -1;

    } else if (parse_anthill_room(ctx, buffer) == -1) {
        return -1;
    }

    return 0;
}

int parse_anthill(context_t *ctx)
{
    if (parse_nb_ants(ctx) == -1)
        return print_error("Could not parse number of ants.", '\n');

    char *buffer;
    while (1) {
        buffer = parser_get_next_line();
        if (buffer == 0)
            break;

        if (process_line(ctx, buffer) == -1) {
            free(buffer);
            return -1;
        }

        free(buffer);
    }

    if (!ctx->rooms.nodes)
        return print_error("Invalid map parsing.", '\n');
    return 0;
}
