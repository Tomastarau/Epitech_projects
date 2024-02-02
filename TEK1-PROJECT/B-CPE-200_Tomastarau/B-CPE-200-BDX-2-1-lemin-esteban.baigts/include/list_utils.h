/*
** EPITECH PROJECT, 2023
** lemintest
** File description:
** list_utils
*/

#include <stdio.h>

#ifndef LIST_UTILS_H
    #define LIST_UTILS_H

    typedef struct list_node_s {
        struct list_node_s *next;
    } list_node_t;

    typedef struct list_s {
        size_t count;
        list_node_t *nodes;
    } list_t;

    void add_to_list(list_t *list, void *buffer);
    void reset_list(list_t *list);
    void free_list(list_t *list);

#endif //!LIST_UTILS_H
