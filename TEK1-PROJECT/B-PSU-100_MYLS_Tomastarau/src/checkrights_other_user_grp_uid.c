/*
** EPITECH PROJECT, 2022
** checkrights_other_user_grp_uid
** File description:
** checkrights_other_user_grp_uid
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

void checkrights_other_user_grp_uid(struct stat stats)
{
    struct passwd *p = getpwuid(stats.st_uid);
    struct group *grp = getgrgid(stats.st_gid);
    uid_t  uid = 0;

    if (stats.st_mode & S_IROTH)
        my_printf("r");
    else
        my_printf("-");
    if (stats.st_mode & S_IWOTH)
        my_printf("w");
    else
        my_printf("-");
    if (stats.st_mode & S_IXOTH)
        my_printf("x.");
    else
        my_printf("-.");
    my_printf(" %d", stats.st_nlink);
    my_printf(" %s", p->pw_name);
    my_printf(" %s", grp->gr_name);
}
