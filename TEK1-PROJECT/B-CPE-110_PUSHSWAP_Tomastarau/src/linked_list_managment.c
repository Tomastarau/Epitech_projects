/*
** EPITECH PROJECT, 2022
** all fonction to manage linked list
** File description:
** linked_list_managment
*/
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include "swap.h"
#include "printf.h"
#include "my.h"

elt_t *create_node(void)
{
    elt_t *temp = malloc(sizeof(elt_t));
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}

elt_t *add_node_at_end(elt_t *head, int value)
{
    elt_t *temp;
    elt_t *p;
    temp = create_node();
    temp->data = value;
    if (head == NULL){
        head = temp;
    } else {
        p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void display_list(elt_t *list)
{
    elt_t *node = list;
    if (list == NULL){
        return;
    }
    while (node != NULL){
        my_printf("node = %d\n", node->data);
        node = node->next;
    }
}

void delete_list(elt_t **head)
{
    elt_t *current = *head;
    elt_t *next;
    while (current != NULL) {
        next = current->next;
        free (current);
        current = next;
    }
    *head = NULL;
}
