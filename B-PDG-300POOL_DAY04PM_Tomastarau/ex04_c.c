/*
** EPITECH PROJECT, 2024
** ex04 fourth part
** File description:
** ex04_c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void list_dump(list_t *list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        printf("\n");
        list = list->next;
    }
}
