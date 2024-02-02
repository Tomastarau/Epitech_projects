/*
** EPITECH PROJECT, 2022
** fs_understand_return_of_read
** File description:
** fs_understand_return_of_read
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    if (read(fd, buffer, size) == -1){
        my_putstr("read failed\n");
    }
    if (read(fd, buffer, size) == 0){
    my_putstr("read ha nothing more to read\n");
    }
    if (read(fd, buffer, size) < size){
        my_putstr("read didnt complete the entire buffer\n");
    }
    if (read(fd, buffer, size) == size){
        my_putstr("read complete the entire buffer\n");
    }
}