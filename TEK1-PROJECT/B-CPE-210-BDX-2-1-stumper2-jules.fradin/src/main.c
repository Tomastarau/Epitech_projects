/*
** EPITECH PROJECT, 2023
** Ginger
** File description:
** Main file
*/

#include <stddef.h>
#include "ginger.h"

int main(int const argc, char *const *const argv)
{
    if (argv == NULL) {
        return 84;
    }
    if (argc != 5) {
        return 84;
    }
    return ginger(argc, argv);
}
