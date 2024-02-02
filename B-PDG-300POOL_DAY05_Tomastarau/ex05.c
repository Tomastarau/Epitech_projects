/*
** EPITECH PROJECT, 2024
** ex05
** File description:
** ex05
*/

#include "string.h"

int length(const string_t *this)
{
    if (this && this->str) {
        return strlen(this->str);
    }
    return -1;
}
