/*
** EPITECH PROJECT, 2022
** step 1 IV
** File description:
** step1 IV
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

char *load_file_in_mem(char const *filepath)
{
    int fd;
    struct stat sb;
    char buffer[100000] = {0};
    int y = 0, size = 0;
    stat(filepath, &sb);
    char * content = malloc(sizeof(char) * sb.st_size);

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
        exit(84);
    }
    while ((size = read(fd, buffer, sb.st_size)) != 0){
        while (buffer[y] != 0){
            content[y] = buffer[y];
            y++;
        }
    }
    close(fd);
    free(content);
    return (content);
}
