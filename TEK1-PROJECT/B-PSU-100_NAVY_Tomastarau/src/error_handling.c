/*
** EPITECH PROJECT, 2023
** all function for error handling
** File description:
** error_handling
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

int parse_input(int argc, char **argv, char** map)
{
    if (argc == 2) {
        if (my_strlen(folder_into_1d_array(argv[1])) != 31 || add_map_boat(argv\
[1], map) == 84){
            return 84;
        }
    } else if ((argc == 3 && my_strlen(folder_into_1d_array(argv[2])) != 31) \
|| add_map_boat(argv[2], map) == 84) {
        return 84;
    } else {
        return 0;
    }
    return 0;
}

int letter_to_number_check(char letter)
{
    int number = 0;
    int i = 64;
    while (i != letter){
        number++;
        i++;
    }
    return number;
}

int verif_game_integrity(int argc, char* argv[])
{
    char *arg_to_check;
    if (argc > 3 || argc < 2) {
        return 84;
    }
    if (argc == 2) {
        arg_to_check = argv[1];
    } else {
        arg_to_check = argv[2];
    }
    if (open(arg_to_check, O_RDONLY) == -1 || \
my_strlen(folder_into_1d_array(arg_to_check)) != 31) {
        return 84;
    }
    if (check_boat_integrity(arg_to_check) == 84) {
        return 84;
    }
    return 0;
}

int check_boat_integrity(char* pos_folder)
{
    char *pos = folder_into_1d_array(pos_folder);
    char **array_pos = my_str_to_word_array_2(pos);
    int taille = 0;
    for (int i = 0; i != 4; i++) {
        taille = char_to_int(array_pos[i][0]);
        if (taille == -1 || taille != i + 2 || array_pos[i][1] != ':' || \
array_pos[i][4] != ':' || (char_to_int(array_pos[i][3]) != \
char_to_int(array_pos[i][6]) && letter_to_number_check(array_pos[i][2]) != \
letter_to_number_check(array_pos[i][5])) || (((((char_to_int(array_pos[i][3])) \
- 1) + taille) != char_to_int(array_pos[i][6])) && \
(((char_to_int(array_pos[i][3])) + 1) - taille) != \
char_to_int(array_pos[i][6]) && (((letter_to_number_check(array_pos[i][2]) - \
1) + taille) != letter_to_number_check(array_pos[i][5])) && \
((letter_to_number_check(array_pos[i][2]) + 1) - taille) != \
letter_to_number_check(array_pos[i][5]))){
            return 84;
        }
    }
    return 0;
}
