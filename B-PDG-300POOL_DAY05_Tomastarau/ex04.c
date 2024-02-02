/*
** EPITECH PROJECT, 2024
** ex04
** File description:
** ex04
*/

#include "string.h"

void clear(string_t *this)
{
    if (this && this->str) {
        this->str[0] = '\0';
    }
}
