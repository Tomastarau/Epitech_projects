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
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/my_antman.h"

int my_antman(char *argv[], struct stat stats)
{
    char *str;
    if (my_strcmp(argv[2], "1") == 0 || my_strcmp(argv[2], "2") == 0){
        str = folder_into_1d_array(argv[1]);
        if (stats.st_size > 50) {
            my_text_compression(str);
        } else {
            send_same_file(str);
        }
        return 0;
    }
    if (my_strcmp(argv[2], "3") == 0){
        image_compression(argv[1]);
        return 0;
    } else {
        write(2, "Erreur\n", 8);
        return 84;
    }
    return 0;
}
