/*
** EPITECH PROJECT, 2024
** exercice 2
** File description:
** ex02
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    int_list_t *current = list;

    if (list == NULL) {
        return 0;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    return current->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t *current = list;

    if (list == NULL) {
        return 0;
    }
    if (position == 0) {
        return int_list_get_elem_at_front(list);
    }
    for (unsigned int i = 0; i < position; ++i) {
        if (current == NULL) {
            return 0;
        }
        current = current->next;
    }
    if (current == NULL) {
        return 0;
    }
    return current->value;
}
