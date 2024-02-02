/*
** EPITECH PROJECT, 2024
** ex00
** File description:
** ex00
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this) {
        this->str = malloc(strlen(s) + 1);
        if (this->str) {
            strcpy(this->str, s);
        }
        this->assign_s = assign_s;
        this->assign_c = assign_c;
    }
}

void string_destroy(string_t *this)
{
    if (this) {
        free(this->str);
        this->str = NULL;
    }
}
