/*
** EPITECH PROJECT, 2022
** fs_open_file
** File description:
** fs_open_file
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int fs_open_file(char const *filepath)
{
    int fd;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
        return 84;
    }
    my_putstr("SUCCESS\n");
    close(fd);
    return fd;
}