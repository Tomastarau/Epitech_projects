/*
** EPITECH PROJECT, 2023
** ginger
** File description:
** retrieve arguments
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ginger.h"
#include "my.h"

static long retrieve_file_size(char *const filepath)
{
    int fd;
    FILE *stream;
    long size = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1){
        return -1;
    }
    stream = fopen(filepath, "r");
    fseek(stream, 0, SEEK_END);
    size = lseek(fd, 0, SEEK_END);
    close(fd);
    fclose(stream);
    return size;
}

static int retrieve_mv_number(ginger_t *ginger_stats, char *str)
{
    if (str == NULL || ginger_stats == NULL) return 84;
    int nbr = my_getnbr(str);
    if (nbr <= 0) {
        return 84;
    } else {
        ginger_stats->mv_init = nbr;
        ginger_stats->mv = nbr;
    }
    return 0;
}

static int retrieve_int_map(ginger_t *ginger_stats, char *path)
{
    long size = retrieve_file_size(path);
    int fd = open(path, O_RDONLY);
    char *map = malloc(sizeof(size + 1));
    if (read(fd, map, size) == -1) return 84;
    map[size] = '\0';
    char **str_map = my_str_to_word_array(map);
    if (!str_map) return 84;
    ginger_stats->map = str_map;
    return 0;
}

int retrieve_args(int const argc, char *const *const argv,
    ginger_t *ginger_stats)
{
    if (argv == NULL || ginger_stats == NULL) return 84;
    int mv_number_err = 0;
    int retrieve_file_err = 0;
    for (int it_on_argc = 1; it_on_argc != (argc - 1); it_on_argc++) {
        if (!my_strncmp(argv[it_on_argc], "-m", 2)) {
            mv_number_err = retrieve_mv_number(ginger_stats,
            argv[it_on_argc + 1]);
        }
        if (!my_strncmp(argv[it_on_argc], "-f", 2)) {
            retrieve_file_err = retrieve_int_map(ginger_stats,
            argv[it_on_argc + 1]);
        }
    }
    if (mv_number_err || retrieve_file_err) {
        write(2, "Bad arguments: -m must be followed by a valid,\
positive number; -f by a valid file.\n", 82);
        return 84;
    }
    return 0;
}
