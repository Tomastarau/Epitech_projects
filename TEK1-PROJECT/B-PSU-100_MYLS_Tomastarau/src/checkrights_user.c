/*
** EPITECH PROJECT, 2022
** checkrights_user
** File description:
** checkrights_user
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

void checkrights_user(struct stat stats)
{
    if (stats.st_mode & S_IRUSR)
        my_printf("r");
    else
        my_printf("-");
    if (stats.st_mode & S_IWUSR)
        my_printf("w");
    else
        my_printf("-");
    if (stats.st_mode & S_IXUSR)
        my_printf("x");
    else
        my_printf("-");
}
