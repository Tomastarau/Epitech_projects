/*
** EPITECH PROJECT, 2023
** stumper2 functions
** File description:
** stumper2 fonction
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int puterror(const char* error_mess, const int error_code)
{
    if (!error_mess){
        return 84;
    }
    write(2, error_mess, my_strlen(error_mess));
    return error_code;
}

int fazzbizz(int firstdigit, const int secdigit)
{
    while (firstdigit < secdigit + 1){
        if (firstdigit % 9 == 0 && firstdigit % 10 == 0){
            printf("FazzBizz\n");
            firstdigit++;
            continue;
        }
        if (firstdigit % 10 == 0){
            printf("Fazz\n");
            firstdigit++;
            continue;
        }
        if (firstdigit % 9 == 0){
            printf("Bizz\n");
            firstdigit++;
            continue;
        }
        printf("%d\n", firstdigit);
        firstdigit++;
    }
    return 0;
}
