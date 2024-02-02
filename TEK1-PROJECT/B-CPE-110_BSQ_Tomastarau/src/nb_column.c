/*
** EPITECH PROJECT, 2022
** nb_column
** File description:
** nb_column
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"

int nb_column(char ** tableau)
{
    int colonne = my_strlen(tableau[1]);
    return (colonne);
}
