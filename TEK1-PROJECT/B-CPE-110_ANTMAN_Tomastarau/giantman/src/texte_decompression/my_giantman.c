/*
** EPITECH PROJECT, 2023
** my_antman
** File description:
** my_antman
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

int my_giantman(char *argv[], struct stat stats)
{
    char const *str;
    if (my_strcmp(argv[2], "1") == 0 || my_strcmp(argv[2], "1") == 2){
        str = folder_into_1d_array(argv[1]);
        if (stats.st_size > 50) {
            my_text_decompression(str);
        } else {
            write (1, str, my_strlen(str));
        }
        return 0;
    }
    if (my_strcmp(argv[2], "3") == 0){
        image_file_decompression(argv[1]);
        return 0;
    } else {
        write(2, "Erreur\n", 8);
        return 84;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct stat stats;
    if (argc == 3 && my_str_isnum(argv[2]) && stat(argv[1], &stats) == 0 && \
(S_ISREG(stats.st_mode))){
        my_giantman(argv, stats);
    } else {
        write(2, "Error\n", 7);
        return 84;
    }
    return 0;
}
