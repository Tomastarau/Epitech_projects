/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** link
*/

#include <stdlib.h>
#include "../include/link.h"
#include "../include/lib.h"

static room_t *get_room_by_name(room_t *room, char *name)
{
    for (; room; room = room->next) {
        if (str_cmp(room->name, name) == 0)
            return room;
    }

    return 0;
}

link_node_t *create_link(rooms_t *rooms, char *buffer)
{
    char **data = str_to_word_array(buffer, '-');
    if (get_arr_len(data) != 2) {
        free_arr(data);
        return 0;
    }

    link_node_t *link = malloc(sizeof(link_node_t));
    link->next = 0;
    link->from = get_room_by_name(rooms->nodes, data[0]);
    link->to = get_room_by_name(rooms->nodes, data[1]);
    if (!link->to || !link->from) {
        free_arr(data);
        return 0;
    }

    free_arr(data);
    return link;
}
