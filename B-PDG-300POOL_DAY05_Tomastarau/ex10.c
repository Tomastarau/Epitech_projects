/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-tom.bouisset
** File description:
** ex10
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    size_t len_this;
    size_t len_str;
    char *found = NULL;

    if (this && this->str && str && str->str) {
        len_this = strlen(this->str);
        len_str = strlen(str->str);
        if (pos < len_this && len_str <= len_this - pos) {
            found = strstr(this->str + pos, str->str);
        }
        if (found) {
            return (int)(found - this->str);
        }
    }
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    size_t len_this;
    size_t len_str;
    char *found = NULL;

    if (this && this->str && str) {
        len_this = strlen(this->str);
        len_str = strlen(str);
        if (pos < len_this && len_str <= len_this - pos) {
            found = strstr(this->str + pos, str);
        }
        if (found) {
            return (int)(found - this->str);
        }
    }
    return -1;
}
