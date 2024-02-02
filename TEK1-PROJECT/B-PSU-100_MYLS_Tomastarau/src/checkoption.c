/*
** EPITECH PROJECT, 2022
** checkoption
** File description:
** checkoption
*/
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include "my_ls.h"

void print_l_folder(char const *argv[], struct stat stats, \
struct dirent *dirp, int i)
{
    DIR *dir;
    if (!dir) {
        perror("Unable to read dir");
        exit (84);
    }
    dir = opendir(argv[i]);
    while ((dirp = readdir(dir)) != NULL){
        if (dirp->d_name[0] != '.'){
            stat(my_strcat(my_strcat(argv[i], "/"), dirp->d_name), &stats);
            printfileproperties_argv(stats, dirp->d_name);
        }
    }
}

void checkoption_l(int argc , char const *argv[], DIR *directory)
{
    struct dirent *dirp;
    struct stat stats;
    int i = 2, total = 0;
    while (stat(argv[i], &stats) == 0 && argc > 2){
        if ((stats.st_mode & S_IFDIR) == 0){
            printfileproperties_argv(stats, argv[i]);
        }
        if (stats.st_mode & S_IFDIR){
            print_l_folder(argv, stats, dirp, i);
        }
        i++;
    }
    while ((dirp = readdir(directory)) != NULL && i == 2){
        if (stat(dirp->d_name,\
        &stats) == 0 && dirp->d_name[0] != '.' && argv[1][0] == '-'){
            printfileproperties(stats, dirp);
        }
    }
}

void checkoption_a(int argc , char const *argv[], DIR *directory)
{
    struct dirent *dirp;
    struct stat stats;

    while ((dirp = readdir(directory)) != NULL){
        my_printf("%s  ", dirp->d_name);
    }
    my_printf("\n");
}
