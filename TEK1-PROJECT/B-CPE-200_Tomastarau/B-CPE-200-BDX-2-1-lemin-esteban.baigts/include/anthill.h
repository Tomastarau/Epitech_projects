/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** anthill
*/

#include <stdlib.h>
#include "link.h"
#include "room.h"

#ifndef ANTHILL_H
    #define ANTHILL_H

    typedef struct context_s {
        size_t nb_ants;
        room_t *start;
        room_t *end;
        rooms_t rooms;
        links_t links;
    } context_t;

    context_t *create_context(void);
    void display_anthill(context_t *ctx);
    void destroy_anthill(context_t *ctx);

#endif // !ANTHILL_H
