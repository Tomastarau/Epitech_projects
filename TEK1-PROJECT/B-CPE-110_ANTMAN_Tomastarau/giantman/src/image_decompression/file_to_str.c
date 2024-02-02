/*
** EPITECH PROJECT, 2022
** file_to_str.c
** File description:
** Take a file in params and transform it into a string
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
#include "../../../include/my.h"
#include "../../../include/my_printf.h"
#include "../../../include/my_antman.h"

char *file_to_str(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Error parameter file\n", 22);
    }
    struct stat s;
    stat(filepath, &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    close(fd);
    buffer[s.st_size] = '\0';
    return buffer;
}
