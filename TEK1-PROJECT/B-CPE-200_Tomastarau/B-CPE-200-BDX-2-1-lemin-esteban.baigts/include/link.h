/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** link
*/

#include <stdlib.h>
#include "room.h"

#ifndef LINK_H
    #define LINK_H

    typedef struct link_node_s {
        struct link_node_s *next;
        room_t *from;
        room_t *to;
    } link_node_t;

    typedef struct links_s {
        size_t count;
        link_node_t *nodes;
    } links_t;

    link_node_t *create_link(rooms_t *rooms, char *buffer);

#endif // !LINK_H
