/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** main
*/

#include "main.h"

int main(const int argc, const char * argv[])
{
    if (check_args(argc, argv) == ERROR)
        return ERROR;
    return sandpile(argv);
}
