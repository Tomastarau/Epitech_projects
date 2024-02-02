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

void str_to_standard_output_giant(char *str)
{
    write(1, str, my_strlen(str));
}
