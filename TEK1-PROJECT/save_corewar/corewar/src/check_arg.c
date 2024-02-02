/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** check_arg
*/


/* system INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "utils.h"
#include "lib.h"
#include "print.h"

static int check_flags(char const *arg, int const argc, int i)
{
    if (i + 1 >= argc) {
        my_put_strerr("Error: Invalid number of arguments.\n");
        return ERROR;
    } if (my_strcmp(arg, "-dump") == 0) {
        return SUCCESS;
    } if (my_strcmp(arg, "-n") == 0) {
        return SUCCESS;
    } if (my_strcmp(arg, "-a") == 0) {
        return SUCCESS;
    } else {
        my_put_strerr("Error: Invalid argument.\n");
        return ERROR;
    }
    return SUCCESS;
}

static int check_file(char const *arg)
{
    FILE *stream = fopen(arg, "r");

    if (stream == NULL) {
        my_put_strerr("Error: Cannot open or read file.\n");
        return ERROR;
    }
    if (fclose(stream) == ERROR) {
        my_put_strerr("Error: Cannot close file.\n");
        return ERROR;
    }
    return SUCCESS;
}

static int check_path(char const *path)
{
    int i = 0;

    for (; path[i]; i++);
    if (i <= 4 || my_strcmp(path + (i - 4), ".cor") != 0) {
        my_put_strerr("Incorect file extension. \".cor\" needed.\n");
        return ERROR;
    }
    return SUCCESS;
}

static int check_loop(int const argc, char const *arg, int i)
{
    if (arg[0] == '-') {
        if (check_flags(arg, argc, i) == ERROR)
            return ERROR;
    } else {
        if (check_path(arg) == ERROR || check_file(arg) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int check_arg(int const argc, char const *argv[])
{
    if (argc < 2) {
        my_put_strerr("Error: Bad arguments.\n");
        return ERROR;
    } if (my_strcmp(argv[1], "-h") == 0) {
        if (print_help() == ERROR)
            return ERROR;
        return SUCCESS;
    }
    for (int i = 1; i < argc; i++)
        if (check_loop(argc, argv[i], i) == ERROR)
            return ERROR;
    return SUCCESS;
}
