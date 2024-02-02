/*
** EPITECH PROJECT, 2024
** ex02
** File description:
** ex02
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    size_t this_len = 0;
    size_t ap_len = 0;

    if (this && ap && ap->str) {
        this_len = this->str ? strlen(this->str) : 0;
        ap_len = ap->str ? strlen(ap->str) : 0;
        this->str = realloc(this->str, this_len + ap_len + 1);
        if (this->str) {
            strcat(this->str, ap->str);
        }
    }
}

void append_c(string_t *this, const char *ap)
{
    size_t this_len = 0;
    size_t ap_len = 0;

    if (this == NULL || ap == NULL)
        return;
    this_len = (this->str) ? strlen(this->str) : 0;
    ap_len = (ap) ? strlen(ap) : 0;
    this->str = realloc(this->str, this_len + ap_len + 1);
    if (this->str) {
        strcat(this->str, ap);
    }
}
