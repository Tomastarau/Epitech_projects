/*
** EPITECH PROJECT, 2024
** Exercice 00
** File description:
** ex00
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *current = *front_ptr;

    if (new_node == NULL) {
        return false;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

void int_list_dump(int_list_t *list)
{
    int_list_t *current = list;

    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    int_list_t *current = list;
    unsigned int len = 0;

    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}

bool int_list_is_empty(int_list_t *list)
{
    if (list == NULL) {
        return true;
    } else {
        return false;
    }
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *current = *front_ptr;
    int_list_t *next_node;

    if (front_ptr == NULL || *front_ptr == NULL) {
        return;
    }
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *front_ptr = NULL;
}
