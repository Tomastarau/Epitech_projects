/*
** EPITECH PROJECT, 2024
** ex01
** File description:
** ex01
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    char *new_str;

    if (this && str && str->str) {
        new_str = malloc(strlen(str->str) + 1);
        if (new_str) {
            strcpy(new_str, str->str);
            free(this->str);
            this->str = new_str;
        }
    }
}

void assign_c(string_t *this, const char *s)
{
    char *new_str;

    if (this && s) {
        new_str = malloc(strlen(s) + 1);
        if (new_str) {
            strcpy(new_str, s);
            free(this->str);
            this->str = new_str;
        }
    }
}
