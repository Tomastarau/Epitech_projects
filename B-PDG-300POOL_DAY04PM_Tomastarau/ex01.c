/*
** EPITECH PROJECT, 2024
** ex01
** File description:
** Exercice 1
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));

    if (new_node == NULL) {
        return false;
    }
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    int_list_t *new_node;
    int_list_t *current;

    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    new_node = malloc(sizeof(int_list_t));
    current = *front_ptr;
    if (new_node == NULL)
        return false;
    new_node->value = elem;
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (current == NULL || current->next == NULL) {
            free(new_node);
            return false;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return true;
}
