/*
** EPITECH PROJECT, 2022
** fs_print_first_line
** File description:
** fs_print_first_line
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>

void fs_print_first_line (char const *filepath)
{
    int fd;
    char buffer[500] = {0};
    int size = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    while (size = read(fd, buffer, 500) != 0){
        for (int y = 0; buffer[y] != 0; y++){
            if (buffer[y] == '\n'){
                return;
            }
            write (1, &buffer[y], 1);
        }
    }
    close(fd);
}