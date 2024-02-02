/*
** EPITECH PROJECT, 2024
** concat.c
** File description:
** concat
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(strlen(str1) + strlen(str2) + 1);
    if (*res == NULL) {
        printf("Error res == NULL");
        return;
    }
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    str->res = malloc(strlen(str->str1) + strlen(str->str2) + 1);
    if (str->res == NULL) {
        printf("Error res == NULL");
        return;
    }
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}
