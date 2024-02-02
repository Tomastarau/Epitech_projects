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
        if (write(2, "Usage: geekNameFormatter string\n", 33) != 33)
            return 84;
        return 84;
    }
    if (geek_name(argv[1]) == 84){
        if (write(2, "Usage: geekNameFormatter string\n", 33) != 33)
            return 84;
        return 84;
    }
    return 0;
}
