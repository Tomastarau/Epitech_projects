/*
** EPITECH PROJECT, 2024
** ex04 second part
** File description:
** ex04_a
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool list_add_elem_at_position(list_t **front_ptr,
    void *elem, unsigned int position)
{
    list_t *current;
    list_t *new_node = malloc(sizeof(list_t));

    if (*front_ptr == NULL)
        return false;
    current = *front_ptr;
    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (current == NULL)
            return false;
        current = current->next;
    }
    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL) {
        return NULL;
    }
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL) {
        return NULL;
    }
    while (list->next != NULL) {
        list = list->next;
    }
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    for (unsigned int i = 0; i < position; ++i) {
        if (list == NULL) {
            return NULL;
        }
        list = list->next;
    }
    return (list != NULL) ? list->value : NULL;
}
