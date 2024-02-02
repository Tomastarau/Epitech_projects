/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** check_args
*/

#include <stdio.h>
#include <unistd.h>
#include "macro_errors.h"

static int check_len(const char *str)
{
    int len = 0;
    if (str == NULL)
        return ERROR;
    for (; str[len] != '\0'; len += 1);

    if (len != 4)
        return ERROR;
    return SUCCESS;
}

static int check_str(const char *str)
{
    if (str == NULL)
        return ERROR;
    if (check_len(str) == ERROR)
        return ERROR;
    if (str[0] == str[1] || str[0] == str[2] || str[0] == str[3])
        return ERROR;
    if (str[1] == str[2] || str[1] == str[3])
        return ERROR;
    if (str[2] == str[3])
        return ERROR;
    return SUCCESS;
}

static int is_number(const char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || '9' < str[i])
            return ERROR;
    }
    return SUCCESS;
}

int check_args(const int argc, const char * argv[])
{
    if (argc != 4)
        return ERROR;
    if (argv == NULL)
        return ERROR;
    if (access(argv[1], R_OK) == -1)
        return ERROR;
    if (check_str(argv[2]) == ERROR)
        return ERROR;
    if (is_number(argv[3]) == ERROR)
        return ERROR;
    return SUCCESS;
}
