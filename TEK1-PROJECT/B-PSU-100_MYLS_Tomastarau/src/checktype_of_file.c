/*
** EPITECH PROJECT, 2022
** checktype_of_file
** File description:
** checktype_of_file
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

void checktype_of_file(struct stat stats)
{
    if (stats.st_mode & S_IFREG)
        my_printf("-");
    if (stats.st_mode & S_IFDIR)
        my_printf("d");
    if (stats.st_mode & S_IFCHR)
        my_printf("c");
}
