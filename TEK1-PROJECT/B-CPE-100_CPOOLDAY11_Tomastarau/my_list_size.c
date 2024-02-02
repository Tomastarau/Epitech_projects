/*
** EPITECH PROJECT, 2022
** my list size
** File description:
** task02
*/

#include <stdlib.h>
#include "./include/mylist.h"
#include <stddef.h>

linked_list_t *add_node(char *param, linked_list_t **head);

int my_list_size(linked_list_t const * begin)
{
    int count = 0;
    linked_list_t *tmp = begin;
    
    while (tmp != NULL){
        count = count + 1;
        tmp = tmp->next;
    }
    return (count);
}
