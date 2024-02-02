/*
** EPITECH PROJECT, 2023
** print_function
** File description:
** print_functions
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include "../../../include/my.h"
#include "../../../include/my_printf.h"
#include "../../../include/my_antman.h"

void print_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        my_printf("%s\n", tab[i]);
        i++;
    }
}

void str_to_standard_output(char *str, char *str_of_dup)
{
    write(1, str_of_dup, my_strlen(str_of_dup));
    write(1, str, my_strlen(str));
}

void send_same_file(char * str)
{
    write (1, str, my_strlen(str));
    return;
}
