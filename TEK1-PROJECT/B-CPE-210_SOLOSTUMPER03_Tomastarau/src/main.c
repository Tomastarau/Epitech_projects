/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

int main(int argc, char* argv[])
{
    const char* error = ("Error:  the second parameter must be greater \
than the first one.\n");
    int firstdigit = 0;
    int secdigit = 0;
    if (argc != 3){
        return 84;
    }
    firstdigit = atoi(argv[1]);
    secdigit = atoi(argv[2]);
    if (firstdigit > secdigit){
        puterror(error, 84);
        return 84;
    }
    return fazzbizz(firstdigit, secdigit);
}
