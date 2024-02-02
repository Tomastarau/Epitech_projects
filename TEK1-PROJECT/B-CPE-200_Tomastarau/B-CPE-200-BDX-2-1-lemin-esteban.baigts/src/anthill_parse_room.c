/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** parse_anthill_room
*/

#include "../include/anthill.h"
#include "../include/parser.h"
#include "../include/lib.h"

static int parse_start_room(context_t *ctx)
{
    char *buffer = parser_get_next_line();
    if (buffer == 0)
        return -1;

    room_t *room = create_room(buffer);
    free(buffer);

    if (room == 0) {
        print_error("Could not parse start room", '\n');
        return -1;
    }

    add_to_list((list_t *)(&ctx->rooms), room);
    ctx->start = room;
    return 0;
}

static int parse_end_room(context_t *ctx)
{
    char *buffer = parser_get_next_line();
    if (buffer == 0)
        return -1;

    room_t *room = create_room(buffer);
    free(buffer);

    if (room == 0) {
        print_error("Could not parse end room", '\n');
        return -1;
    }

    add_to_list((list_t *)(&ctx->rooms), room);
    ctx->end = room;
    return 0;
}

int parse_anthill_room(context_t *ctx, char *buffer)
{
    if (str_cmp(buffer, "##start") == 0) {
        if (!ctx->start)
            return parse_start_room(ctx);

        return print_error("Invalid map parsing", '\n');
    }

    if (str_cmp(buffer, "##end") == 0) {
        if (!ctx->end)
            return parse_end_room(ctx);

        return print_error("Invalid map parsing", '\n');
    }

    room_t *room = create_room(buffer);
    if (room == 0)
        return print_error("Could not parse room", '\n');

    add_to_list((list_t *)(&ctx->rooms), room);
    return 0;
}
