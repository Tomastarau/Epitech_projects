/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my_sokoban.h"
#include "my.h"



char *folder_into_1d_array(char const *filepath);

const char *h_option(void)
{
    char *sokoban_info = "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     \
map file representing the warehouse map, containing '#' for walls,             \
'P' for the player, 'X' for boxes and 'O' for storage locations.";
    return sokoban_info;
}

void error_recognition(int argc, char const *argv[])
{
    struct stat stats;

    if (argc < 2){
        write(2, KRED"Please reffer to ./my_sokoban -h command\n"KNRM, 51);
        exit(84);
    }
    if (argc >= 2 && stat((argv[1]), &stats) != -1){
        if (S_ISREG(stats.st_mode) == 0 ){
            write(2, KRED"Please use a regular file as map\n"KNRM, 43);
            exit(84);
        }
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0){
        my_printf("%s%s%s\n", KMAG, h_option(), KNRM);
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    error_recognition(argc, argv);
    //len_of_biggest_word(my_str_to_word_array(folder_into_1d_array(argv[1])));
    my_sokoban(my_str_to_word_array(folder_into_1d_array(argv[1])));
    return 0;
}
