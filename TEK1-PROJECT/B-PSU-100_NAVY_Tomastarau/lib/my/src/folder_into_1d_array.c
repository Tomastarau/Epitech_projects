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

int my_putstr(char const *str);

long get_file_size(char const *filepath)
{
    int fd;
    FILE *stream;
    long size = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    stream = fopen(filepath, "r");
    fseek(stream, 0, SEEK_END);
    size = lseek(fd, 0, SEEK_END);
    fclose(stream);
    return size;
}

char *folder_into_1d_array(char const *filepath)
{
    int fd;
    long file_size = get_file_size(filepath);
    char *buffer;
    int size = 0;
    buffer = malloc(sizeof(char) * file_size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    size = read(fd, buffer, file_size);
    return buffer;
}
