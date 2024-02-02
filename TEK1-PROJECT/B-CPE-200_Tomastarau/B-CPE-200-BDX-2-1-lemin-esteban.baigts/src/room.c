/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** room
*/

#include <stdlib.h>
#include "../include/room.h"
#include "../include/lib.h"


room_t *create_room(char *buffer)
{
    char **data = str_to_word_array(buffer, ' ');
    if (get_arr_len(data) != 3) {
        free_arr(data);
        return 0;
    }

    room_t *room = malloc(sizeof(room_t));
    room->next = 0;
    room->name = str_dup(data[0]);
    room->x = str_to_num(data[1]);
    room->y = str_to_num(data[2]);

    free_arr(data);
    return room;
}

void destroy_room(room_t *room)
{
    free(room->name);
    free(room);
}
