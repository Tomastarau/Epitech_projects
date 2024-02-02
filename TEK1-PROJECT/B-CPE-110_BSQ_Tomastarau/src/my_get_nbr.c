/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** my_get_nbr
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"

int my_get_nbr(char *valeur)
{
    int i = 0;
    int nombre = 0;
    int mul = 1;
    while (valeur[i] != '\0'){
        nombre = nombre * mul + (valeur[i] - '0');
        mul = 10;
        i++;
    }
    return nombre;
}
