/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>
#include <stddef.h>
#include "./include/mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av);

int my_list_size(linked_list_t const * begin);

void print(linked_list_t *list)
{
    while (list != NULL){
        printf("%s\n", list->data);
        list = list->next;
    }
}

int main(int argc, char *const * argv)
{
    linked_list_t *node = NULL;
    printf("%d\n", my_list_size(my_params_to_list(argc, argv)));
    return 0;
}
