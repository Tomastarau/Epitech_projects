/*
** EPITECH PROJECT, 2024
** exercice 3
** File description:
** ex03
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *current;

    if (*front_ptr == NULL) {
        return false;
    }
    current = *front_ptr;
    *front_ptr = current->next;
    free(current);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *current;

    if (*front_ptr == NULL) {
        return false;
    }
    current = *front_ptr;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *current;
    int_list_t *temp;

    if (*front_ptr == NULL)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    current = *front_ptr;
    for (unsigned int i = 0; i < position - 1; ++i) {
        if (current->next == NULL)
            return false;
        current = current->next;
    }
    if (current->next == NULL)
        return false;
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}
