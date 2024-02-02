/*
** EPITECH PROJECT, 2023
** get_map
** File description:
** get_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "macro_errors.h"

static int get_ind(const char *str, char letter)
{
    int ind = 0;
    if (str == NULL)
        return ERROR;

    for (; str[ind] != '\0'; ind += 1) {
        if (str[ind] == letter)
            return ind;
    }
    return ERROR;
}

static int fill_line(int *line, int fd, const char *str)
{
    int ind = 0;
    char buf;

    if (line == NULL || str == NULL)
        return ERROR;

    for (int i = 0; i < 3; i += 1) {
        if (read(fd, &buf, 1) < 1)
            return ERROR;
        if ((ind = get_ind(str, buf)) == ERROR)
            return ERROR;
        line[i] = ind;
    }
    if (read(fd, &buf, 1) < 1)
        return ERROR;
    if (buf != '\n')
        return ERROR;
    return SUCCESS;
}

static int fill_map(int **map, const char *path, const char *str)
{
    int fd = 0;
    char buf;

    if (map == NULL || path == NULL || str == NULL)
        return ERROR;
    if ((fd = open(path, O_RDONLY)) == -1)
        return ERROR;
    for (int i = 0; i < 3; i += 1) {
        if (fill_line(map[i], fd, str) == ERROR)
            return ERROR;
    }
    if (read(fd, &buf, 1) < 0)
        return ERROR;
    if (buf != '\0')
        return ERROR;
    if (close(fd) == -1)
        return ERROR;
    return SUCCESS;
}

int **get_map(const char *path, const char *str)
{
    int ** map = malloc(sizeof(int *) * 3);

    if (map == NULL || path == NULL || str == NULL)
        return NULL;

    for (int i = 0; i < 3; i += 1) {
        map[i] = malloc(sizeof(int) * 3);
        if (map[i] == NULL)
            return NULL;
    }

    if (fill_map(map, path, str) == ERROR)
        return NULL;
    return map;
}
