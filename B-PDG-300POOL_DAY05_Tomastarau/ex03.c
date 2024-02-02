/*
** EPITECH PROJECT, 2024
** ex03
** File description:
** ex03
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    size_t len;

    if (this) {
        len = strlen(this->str);
        if (pos >= len) {
            return (char)-1;
        }
        return this->str[pos];
    }
    return (char)-1;
}
