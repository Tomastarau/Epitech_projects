/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_lemin.h"

void print_link(link_t* link)
{
    printf("%d\n", link->data);
}

int main (int argc, char** argv, char** env)
{
    (void) argc;
    (void) argv;
    (void) env;
    link_t* new_elem = malloc(sizeof(link_t));
    new_elem->data = 99;
    new_elem->next = NULL;
    print_link(new_elem);
    return 0;
}
