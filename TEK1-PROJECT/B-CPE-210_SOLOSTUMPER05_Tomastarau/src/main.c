/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "stumper.h"

int main(int argc, char* argv[])
{
    if (argc != 2){
        write(1, "\n", 1);
        return 84;
    }
    if (reverse(argv[1]) == 84){
        write (2, "Error\n", 6);
        return 84;
    }
    write (1, "\n", 1);
    return 0;
}
