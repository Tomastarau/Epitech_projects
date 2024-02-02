/*
** EPITECH PROJECT, 2023
** lemintest
** File description:
** list_utils
*/

#include <stdlib.h>

#include "../include/list_utils.h"

void add_to_list(list_t *list, void *buffer)
{
    list_node_t **end = &list->nodes;
    for (; *end != 0; end = &(*end)->next);

    *end = buffer;
    list->count++;
}

void reset_list(list_t *list)
{
    list->count = 0;
    list->nodes = 0;
}

void free_list(list_t *list)
{
    list_node_t *cur = list->nodes;
    for (; cur;) {
        list_node_t *next = cur->next;
        free(cur);
        cur = next;
    }
}
