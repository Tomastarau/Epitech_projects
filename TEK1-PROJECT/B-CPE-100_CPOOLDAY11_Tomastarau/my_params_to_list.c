/*
** EPITECH PROJECT, 2022
** my parameters to list
** File description:
** chained list
*/


#include <stdlib.h>
#include "./include/mylist.h"
#include <stddef.h>

linked_list_t *add_node(char *param, linked_list_t **head);

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *head = NULL;
    linked_list_t *index = NULL;

    if (ac == 1){
        return NULL;
    }
    head = add_node(av[ac - 1], &head);
    index = head;
    int i = ac - 2;
    while (i >= 0){
        index = add_node(av[i], &head);
        i = i - 1;
    }
    return head;
}
