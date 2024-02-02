/*
** EPITECH PROJECT, 2022
** step2 IV
** File description:
** step2 IV
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int fd;
    int y = 0, i = 0, size = 0;
    char buffer[1000000] = {0};
    char **content = malloc(sizeof(char *) * nb_rows + 1);

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    content[i] = malloc(sizeof(char) * nb_cols);
    while (i != nb_rows){
        size = read(fd, buffer, nb_cols);
        while (y != nb_cols){
            content[i][y] = buffer[y];
            y++;
        }
        printf("%s", content[i]);
        i++;
        y = 0;
        content[i] = malloc(sizeof(char) * nb_cols);
    }
    close(fd);
    return (content);
}