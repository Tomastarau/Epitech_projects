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

int my_putstr(char const *str);

char *folder_into_1d_array(char const *filepath)
{
    int fd;
    char *buffer;
    int size = 0, bz = 0;
    struct stat sb;
    stat(filepath, &sb);
    char *string = malloc(sizeof(char) * sb.st_size);

    buffer = malloc(sizeof(char) * sb.st_size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Error\n", 7);
    }
    size = read(fd, buffer, sb.st_size);
    return buffer;
}
