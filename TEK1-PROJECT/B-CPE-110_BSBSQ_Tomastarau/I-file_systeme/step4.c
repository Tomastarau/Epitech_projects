#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>


void fs_cat_x_bytes (char const *filepath, int x)
{
    int fd;
    char *buffer;
    int size = 0;

    buffer = malloc(sizeof(char) * x);
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
    }
    size = read(fd, buffer, x);
    write (1, buffer, size);
    close(fd);
    free(buffer);
}