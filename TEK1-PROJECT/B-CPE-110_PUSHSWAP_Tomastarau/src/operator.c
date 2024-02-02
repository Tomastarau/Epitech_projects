/*
** EPITECH PROJECT, 2022
** all operator fonction
** File description:
** sa ra rb sb etc...
*/
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include "swap.h"
#include "printf.h"
#include "my.h"

/*elt_t *operator_sa_and_sb(elt_t *list)
{
    elt_t *node = list;
    int temp = list->data;
    if (list->next == NULL){
        write(2, "ERROR Too less argument to swap\n", 33);
        return (84);
    }
    list->data = list->next->data;
    list->next->data = temp;
    return list;

}*/

elt_t *operator_ra_and_rb(elt_t *list)
{
    elt_t *new_list = list;
    elt_t *final_list = malloc(sizeof(elt_t));
    int last_cell = new_list->data;
    new_list = new_list->next;
    final_list->data = new_list->data;
    new_list = new_list->next;
    while (new_list != NULL){
        final_list = add_node_at_end(final_list, new_list->data);
        new_list = new_list->next;
    }
    final_list = add_node_at_end(final_list, list->data);
    return final_list;
}

elt_t *operator_rra_and_rrb(elt_t *list)
{
    elt_t *temp = list;
    elt_t *current = list;
    elt_t *new_list = list;
    elt_t *final_list = malloc(sizeof(elt_t));
    int last_cell = 0;
    while (temp->next != NULL){
        temp = temp->next;
        temp->previous = current;
        current = temp;
    }
    last_cell = temp->data;
    final_list->data = last_cell;
    while (new_list->next != NULL){
        final_list = add_node_at_end(final_list, new_list->data);
        new_list = new_list->next;
    }
    return final_list;
}

elt_t *operator_pb(elt_t *list_a, elt_t **list_b)
{
    elt_t *new_node = malloc(sizeof(elt_t));
    elt_t **temp_listb = list_b;
    elt_t *new_list = list_a;
    new_node->data = list_a->data;
    new_node->next = *temp_listb;
    *temp_listb = new_node;
    new_list = new_list->next;
    my_printf("pb ");
    return new_list;
}

elt_t *operator_pa(elt_t **list_a, elt_t *list_b)
{
    elt_t *new_node = malloc(sizeof(elt_t));
    elt_t **temp_listb = list_a;
    elt_t *new_list = list_b;
    new_node->data = list_b->data;
    new_node->next = *temp_listb;
    *temp_listb = new_node;
    new_list = new_list->next;
    return new_list;
}
