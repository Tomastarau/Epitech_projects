/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** room
*/


#ifndef ROOM_H
    #define ROOM_H
    #include <stdlib.h>

    typedef struct room_s {
        struct room_s *next;
        char *name;
        int x;
        int y;
    } room_t;

    typedef struct rooms_s {
        size_t count;
        room_t *nodes;
    } rooms_t;

    room_t *create_room(char *buffer);
    void destroy_room(room_t *room);

#endif // !ROOM_H
