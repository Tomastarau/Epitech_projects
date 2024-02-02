/*
** EPITECH PROJECT, 2023
** MY_lemin
** File description:
** my-lemin
*/

#ifndef MY_LEMIN_H_
    #define MY_LEMIN_H_

typedef struct link
{
    int data ;
    struct link *next ;
} link_t ;

link_t* create_node(int data);
void insert_at_end(link_t** head, int data);
void display_list(link_t* head);
void free_list(link_t** head);

#endif /* !MY_LEMIN_H_ */
