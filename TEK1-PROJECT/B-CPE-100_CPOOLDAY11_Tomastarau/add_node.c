/*
** EPITECH PROJECT, 2022
** add node
** File description:
** add node to chained list
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "./include/mylist.h"

linked_list_t *add_node(char *param, linked_list_t **head)
{
    linked_list_t *new_node = NULL;
    linked_list_t *index = *head;

    if (!(new_node = malloc(sizeof(linked_list_t)))){
        return NULL;
    }
    new_node->data = param;
    new_node->next = NULL;
    if ((*head) == NULL){
        *head = new_node;
    }else{
        while (index->next != NULL){
            index = index->next;
        }
        index->next = new_node;
    }
    return new_node;
}
