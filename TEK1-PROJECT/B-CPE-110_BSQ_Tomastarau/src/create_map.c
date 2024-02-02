/*
** EPITECH PROJECT, 2022
** create map
** File description:
** create map
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"

int if_end(char c, int a)
{
    if (c == '\0'){
        int a = 0;
        return a;
    }
    return a;
}

void create_map(char *taille, char *pattern)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int taille1 = my_get_nbr(taille);
    char **map = malloc(sizeof(char *) * (taille1 + 1));
    while (j < taille1){
        map[j] = malloc(sizeof(char) * taille1 + 1);
        while (i != taille1){
            a = if_end(pattern[a], a);
            map[j][i] = pattern[a];
            i++;
            a++;
        }
        map[j][i] = '\0';
        i = 0;
        my_printf("%s\n", map[j]);
        j++;
    }
    free(map);
}
