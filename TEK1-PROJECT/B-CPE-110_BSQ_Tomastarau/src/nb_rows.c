/*
** EPITECH PROJECT, 2022
** nb_rows
** File description:
** nb_rows
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"

int nb_rows(char ** tableau)
{
    int i = 0;
    int nombre = 0;
    int mul = 1;

    while (tableau[0][i] != '\0'){
        nombre = nombre * mul + (tableau[0][i] - '0');
        mul = 10;
        i++;
    }
    return nombre;
}
