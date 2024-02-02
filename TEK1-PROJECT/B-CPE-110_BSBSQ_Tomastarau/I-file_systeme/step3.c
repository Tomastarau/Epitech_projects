/*
** EPITECH PROJECT, 2022
** fs_cat_500_bytes 
** File description:
** fs_cat_500_bytes 
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void fs_cat_500_bytes (char const *filepath)
{
    int fd;
    char buffer[500] = {0};
    int size = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    size = read(fd, buffer, 500);
    write (1, buffer, size);
    close(fd);
}