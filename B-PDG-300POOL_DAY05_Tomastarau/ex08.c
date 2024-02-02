/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-tom.bouisset
** File description:
** ex08
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this != NULL) {
        return this->str;
    }
    return NULL;
}
