/*
** EPITECH PROJECT, 2022
** printfileproperties
** File description:
** printfileproperties
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
#include "my_ls.h"

void printfileproperties(struct stat stats, struct dirent *dirp)
{
    struct passwd *p;
    struct group *grp;
    char *i;
    uid_t  uid = 0;

    if (stats.st_mode & S_IFMT)
        checktype_of_file(stats);
    if (stats.st_mode & S_IFMT)
        checkrights_user(stats);
        checkrights_grp(stats);
        checkrights_other_user_grp_uid(stats);
        my_printf(" %d ", stats.st_size);
        check_which_month(stats);
        my_printf(" %s\n", dirp->d_name);
}

void printfileproperties_argv(struct stat stats, const char *argv)
{
    struct passwd *p;
    struct group *grp;
    char *i;
    uid_t  uid = 0;

    if (stats.st_mode & S_IFMT)
        checktype_of_file(stats);
    if (stats.st_mode & S_IFMT)
        checkrights_user(stats);
        checkrights_grp(stats);
        checkrights_other_user_grp_uid(stats);
        my_printf(" %d ", stats.st_size);
        check_which_month(stats);
        my_printf(" %s\n", argv);
}
