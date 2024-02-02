/*
** EPITECH PROJECT, 2024
** ex04 third part
** File description:
** ex04_b
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *temp;

    if (*front_ptr == NULL) {
        return false;
    }
    temp = *front_ptr;
    *front_ptr = temp->next;
    free(temp);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *current;

    if (*front_ptr == NULL) {
        return false;
    }
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    current = *front_ptr;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *current;
    list_t *temp;

    if (*front_ptr == NULL || (position == 0 && (*front_ptr)->next == NULL))
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    current = *front_ptr;
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }
    temp = current->next;
    if (temp == NULL)
        return false;
    current->next = temp->next;
    free(temp);
    return true;
}

void list_clear(list_t **front_ptr)
{
    list_t *current = *front_ptr;
    list_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *front_ptr = NULL;
}
