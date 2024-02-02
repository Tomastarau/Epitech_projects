/*
** EPITECH PROJECT, 2022
** check_which_month
** File description:
** check_which_month
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "my.h"
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

void check_which_month(struct stat stats)
{
    int i = 4;
    int index = 0;
    char *temp = ctime(&stats.st_mtime);
    char date[13];
    while (i != 16){
        date[index] = temp[i];
        index++;
        i++;
    }
    date[12] = '\0';
    my_printf("%s", date);
}
