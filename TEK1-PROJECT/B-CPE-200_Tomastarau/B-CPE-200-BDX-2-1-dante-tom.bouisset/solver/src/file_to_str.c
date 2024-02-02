/*
** EPITECH PROJECT, 2022
** file_to_str.c
** File description:
** transform a file into a string
*/

#include "my.h"
#include "my_dante.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *file_to_str(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Error file\n", 12);
        exit(84);
    }
    struct stat s;
    stat(filepath, &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    close(fd);
    buffer[s.st_size - 1] = '\0';
    return buffer;
}
