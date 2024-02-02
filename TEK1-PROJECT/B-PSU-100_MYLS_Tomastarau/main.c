/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include "my_ls.h"

void printFileProperties(struct stat stats);

int str_in_str(const char *haystack, const char *needle);

int my_ls(int argc , char const *argv[]);

int   my_strcmp(const char *s1, const char *s2)
{
    int  i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i]){
        i++;
    }
    return (s1[i] - s2[i]);
}

int main(int ac, char const *av[])
{
    my_ls(ac, av);
    return 0;
}
