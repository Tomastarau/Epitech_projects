/*
** EPITECH PROJECT, 2023
** workshop.c
** File description:
** c'est le workshop
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

int main(int argc, char* argv[])
{
    char **map = my_str_to_word_array_2(folder_into_1d_array("init_map"));
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        h_option();
        return 0;
    }
    if (verif_game_integrity(argc, argv) == 84 || parse_input(argc, argv, map) \
== 84) {
        write(1, "Error, please type ./navy -h for more information\n", 51);
        return 84;
    } else {
        connection(argc, argv);
        my_navy(argc, argv);
        return 0;
    }
    return 1;
}
