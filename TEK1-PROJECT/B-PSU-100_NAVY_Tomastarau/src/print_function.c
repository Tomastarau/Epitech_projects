/*
** EPITECH PROJECT, 2023
** print_function file
** File description:
** print_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

void if_hit(char* pos, char* map[])
{
    if (map[char_to_int(pos[1]) + 1][letter_to_number(pos[0])] != '.'){
        my_printf("C'est touché mon rhey\n");
    } else {
        my_printf("c'est raté mon G\n");
    }
}

void print_position(char **map)
{
    char **init_map = my_str_to_word_array_2(folder_into_1d_array("init_map"));
    write(1, "my positions:\n", 15);
    print_tab(map);
    write(1, "\nenemy's positions\n", 19);
    print_tab(init_map);
}

void wait_for_attack(void)
{
    my_printf("waiting for enemy's attack...\n");
    pause();
}
