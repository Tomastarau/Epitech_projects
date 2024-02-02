/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "stumper.h"

int main(int argc, const char* argv[])
{
    if (argc < 3) {
        return 84;
    }
    if (argc == 4) {
        if (write(1, argv[1], my_strlen(argv[1])) == -1 || \
write(1, "\n", 1) == -1) {
            return 84;
        }
        return 0;
    }
    if (arg_joiner(argv) == 84 || write(1, "\n", 1) == -1) {
        return 84;
    }
    return 0;
}
