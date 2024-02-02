/*
** EPITECH PROJECT, 2022
** add a node at the end of the chained list
** File description:
** add_node_end
*/
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include "swap.h"
#include "printf.h"
#include "my.h"

int	my_getnbr(char *str)
{
    int nb = 0, isneg = 1, i = 0;

    if (str[i] == '-') {
        isneg = isneg * -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else {
            return (nb * isneg);
        }
    }
    return (nb * isneg);
}

int add_arg_to_list(int argc, char *argv[])
{
    int i = 2, node_value = 0;
    elt_t *node = malloc(sizeof(elt_t));
    node->data = my_getnbr(argv[1]);

    while (i < argc){
        if (my_str_isnum(argv[i])){
            node_value = my_getnbr(argv[i]);
            node = add_node_at_end(node, node_value);
            i++;
        } else {
            write(2, "Error please use int as parameter to the \
./push_swap command\n", 62);
            return (84);
        }
    }
    algo_tri(node);
    return 1;
}

void algo_tri(elt_t *list_a)
{
    elt_t *temp = list_a, *list_b = NULL;
    int lowest_value = find_lowest(list_a);
    while (list_a->next != NULL){
        while (list_a->data != lowest_value) {
            my_printf("ra ");
            list_a = operator_ra_and_rb(list_a);
        }
        list_a = operator_pb(list_a, &list_b);
        lowest_value = find_lowest(list_a);
    }
    while (list_b->next != NULL){
        my_printf("pa ");
        list_b = operator_pa(&list_a, list_b);
    }
    my_printf("pa\n");
    list_b = operator_pa(&list_a, list_b);
    delete_list(&list_b);
    return;
}

int find_lowest(elt_t *list)
{
    int lowest_val = list->data;
    elt_t *temp = list;
    while (temp != NULL){
        if (temp->data <= lowest_val){
            lowest_val = temp->data;
        }
        temp = temp->next;
    }
    return lowest_val;
}
