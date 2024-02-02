/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** my_swap
*/

#ifndef SWAP_H_
    #define SWAP_H_

typedef struct elt_s {
    int data;
    struct elt_s *next;
    struct elt_s *previous;
    struct elt_s *last;
} elt_t;

elt_t *create_node(void);

elt_t *add_node_at_end(elt_t *head, int value);

elt_t *operator_sa_and_sb(elt_t *list);

elt_t *operator_ra_and_rb(elt_t *list);

elt_t *operator_rra_and_rrb(elt_t *list);

elt_t *operator_pb(elt_t *list_a, elt_t **list_b);

elt_t *operator_pa(elt_t **list_a, elt_t *list_b);

int add_arg_to_list(int argc, char *argv[]);

int	my_getnbr(char *str);

int algo_for_4_arg(int argv1, int argv2, char *argv[]);

void algo_for_3_or_4_arg(int argc, char *argv[]);

void algo_tri(elt_t *list_a);

int find_lowest(elt_t *list);

void display_list(elt_t *list);

void swap_elem(int *array, int index1, int index2);

void delete_list(elt_t **head);

void bubble_sort_array(int *array , int size);

#endif /* !SWAP_H_ */
