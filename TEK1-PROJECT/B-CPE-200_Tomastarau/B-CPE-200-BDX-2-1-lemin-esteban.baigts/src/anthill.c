/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** anthill
*/

#include <stdio.h>

#include "../include/anthill.h"
#include "../include/lib.h"

context_t *create_context(void)
{
    context_t *ctx = malloc(sizeof(context_t));
    if (!ctx)
        return 0;

    ctx->nb_ants = 0;
    ctx->start = 0;
    ctx->end = 0;
    reset_list((list_t *)(&ctx->rooms));
    reset_list((list_t *)(&ctx->links));
    return ctx;
}

void display_anthill(context_t *ctx)
{
    print_buf("#number_of_ants", '\n');
    print_nbr(ctx->nb_ants, '\n');
    print_buf("#rooms", '\n');
    for (room_t *room = ctx->rooms.nodes; room; room = room->next) {
        if (room == ctx->start)
            print_buf("##start", '\n');

        if (room == ctx->end)
            print_buf("##end", '\n');

        print_buf(room->name, ' ');
        print_nbr(room->x, ' ');
        print_nbr(room->y, '\n');
    }

    print_buf("#tunnels", '\n');
    for (link_node_t *link = ctx->links.nodes; link; link = link->next) {
        print_buf(link->from->name, '-');
        print_buf(link->to->name, '\n');
    }
}

void destroy_anthill(context_t *ctx)
{
    room_t *rooms = (&ctx->rooms)->nodes;
    for (; rooms;) {
        room_t *next = rooms->next;
        free(rooms->name);
        free(rooms);
        rooms = next;
    }

    free_list((list_t *)(&ctx->links));
    free(ctx);
}
