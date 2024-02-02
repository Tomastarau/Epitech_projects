/*
** EPITECH PROJECT, 2023
** h_option.c
** File description:
** -h option for my_navy
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/my_navy.h"

void h_option(void)
{
    my_printf("USAGE\n \
    ./navy [first_player_pid] navy_positions\nDESCRIPTION\n \
    first_player_pid: only for 2nd player. pid of the first player.\n \
    navy_positions: file representing the positions of the ships.\n");
}
