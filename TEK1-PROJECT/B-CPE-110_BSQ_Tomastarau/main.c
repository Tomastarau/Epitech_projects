/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int ac, char *av[])
{
    char **tab = my_str_to_word_array(folder_into_1d_array(av[1]));
    if (ac != 2 && ac != 3){
        write(2, "ERROR / Wrong usage\n", 21);
        return 84;
    }
    if (ac == 3){
        create_map(av[1], av[2]);
    }
    if (ac == 2){
        bsq(tab);
    }
    return 0;
}
