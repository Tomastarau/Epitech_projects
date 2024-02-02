/*
** EPITECH PROJECT, 2023
** main antman
** File description:
** main
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
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/my_antman.h"

int main(int argc, char *argv[])
{
    struct stat stats;
    if (argc == 3 && my_str_isnum(argv[2]) && stat(argv[1], &stats) == 0 && \
(S_ISREG(stats.st_mode))){
        my_antman(argv, stats);
        return 0;
    } else {
        write(2, "Error\n", 7);
        return 84;
    }
    return 0;
}
