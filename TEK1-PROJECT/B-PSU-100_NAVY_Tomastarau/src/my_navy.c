/*
** EPITECH PROJECT, 2023
** my_navy.c
** File description:
** main file for my_navy project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

/*
void my_positions(pid_t pid)
{
    if (pid == pid) {
        //print my_position de argc 2
    } else {
        //print my_position de argc 3
    }
}

void enemy_position(pid_t pid)
{
    if (pid == pid) {
        //print enemy_position de argc 2
    } else {
        //print enemy_position de argc 3
    }
}
*/

int attack_handler(char *buffer)
{
    if (buffer[0] >= 65 && buffer[0] <= 72)
        if (buffer[1] >= 48 && buffer[1] <= 56)
            return 0;
    return 1;
}

void player_turn(char **map)
{
    write(1, "\nattack: ", 9);
    size_t buff_size = 3;
    char *buffer = (char *)malloc(sizeof(char) * buff_size);
    getline(&buffer, &buff_size, stdin);
    if (attack_handler(buffer) == 1) {
        my_printf("wrong position\n");
        return;
    }
    buffer[2] = '\0';
    if_hit(buffer, map);
}

int my_navy(int argc, char** argv)
{
    char **map = my_str_to_word_array_2(folder_into_1d_array("init_map"));
    parse_input(argc, argv, map);
    while (argc == 2) {
        print_position(map);
        player_turn(map);
        wait_for_attack();
    }
    while (argc == 3) {
        print_position(map);
        wait_for_attack();
    }
    return 0;
}
