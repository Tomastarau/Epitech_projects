/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-tom.bouisset
** File description:
** ex07
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len;
    size_t max_copy_length;
    size_t num_to_copy;

    if (this == NULL || this->str == NULL || s == NULL) {
        return 0;
    }
    len = strlen(this->str);
    if (pos >= len) {
        return 0;
    }
    max_copy_length = len - pos;
    num_to_copy = (n < max_copy_length) ? n : max_copy_length;
    strncpy(s, this->str + pos, num_to_copy);
    return num_to_copy;
}
