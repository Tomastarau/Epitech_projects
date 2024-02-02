/*
** EPITECH PROJECT, 2022
** step6 I
** File description:
** step6 I
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my.h"
#include "printf.h"

char *folder_into_1d_array(char const *filepath)
{
    int fd;
    char *buffer;
    int size = 0;
    struct stat sb;
    stat(filepath, &sb);

    buffer = malloc(sizeof(char) * sb.st_size + 1);
    buffer[sb.st_size] = '\0';
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    size = read(fd, buffer, sb.st_size);
    return buffer;
}
