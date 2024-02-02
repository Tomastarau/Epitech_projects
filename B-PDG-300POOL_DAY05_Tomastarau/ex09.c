/*
** EPITECH PROJECT, 2024
** B-PDG-300-BDX-3-1-PDGD05-tom.bouisset
** File description:
** ex09
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this && this->str) {
        if (strlen(this->str) == 0) {
            return 1;
        }
    }
    return 0;
}
