/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** array_utils
*/

#include <stdlib.h>
#include "../include/array_utils.h"

int get_arr_len(char **arr)
{
    if (!arr)
        return 0;

    int ret = 0;
    for (; arr[ret]; ret++);
    return ret;
}

void free_arr(char **arr)
{
    for (int idx = 0; arr[idx] != 0; idx++) {
        free(arr[idx]);
    }

    free(arr);
}
