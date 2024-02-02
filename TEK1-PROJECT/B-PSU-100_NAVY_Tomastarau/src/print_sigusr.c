/*
** EPITECH PROJECT, 2023
** print_sigusr.c
** File description:
** print the mesage for the start with the connection
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/my_navy.h"

void print_sigusr1(pid_t pid_1)
{
    my_printf("my pid: %i\n", pid_1);
    my_printf("waiting for enemy connection...\n\n");
}

void print_sigusr2(pid_t pid_2)
{
    my_printf("my pid: %i\n", pid_2);
    my_printf("successfully connected\n\n");
}
