/*
** EPITECH PROJECT, 2024
** exerice 4
** File description:
** ex04
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

unsigned int list_get_size(list_t *list)
{
    unsigned int count = 0;

    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

bool list_is_empty(list_t *list)
{
    return list == NULL;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL) {
        return false;
    }
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *current;

    if (new_node == NULL) {
        return false;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return true;
    }
    current = *front_ptr;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return true;
}
