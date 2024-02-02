/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "printf.h"
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include "my_ls.h"

/*void error_or_folder_total(DIR *dir, struct dirent *dirp,     \
char const *argv)
{
    struct stat stats;
    int total = 0;
    if (!dir) {
        perror("Unable to read dir");
        exit (84);
    }
    while ((dirp = readdir(dir)) != NULL ){
        stat(my_strcat(my_strcat(argv, "/"), dirp->d_name), &stats);
        (dirp->d_name[0] != '.') ? total += stats.st_blocks : 0;
    }
    my_printf("total %d\n", total / 2);
}

void print_total(int argc, char const *argv)
{
    DIR *dir = opendir(".");
    int total = 0;
    struct dirent *dirp;
    struct stat stats;
    stat(argv, &stats);
    if ((stats.st_mode & __S_IFDIR) == 0)
        return;
    if (argc == 2){
        while ((dirp = readdir(dir)) != NULL){
            stat(dirp->d_name, &stats);
            (dirp->d_name[0] != '.') ? total += stats.st_blocks : 0;
        }
        my_printf("total %d\n", total / 2);
        return;
    }
    dir = opendir(argv);
    error_or_folder_total(dir, dirp, argv);
}

int my_ls(int argc , char const *argv[])
{
    struct dirent *dirp;
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Unable to read dir");
        return (84);
    }
    if (argc < 2)
        my_ls_root(argc, argv, dir);
    if (argc > 1 && argv[1][0] == '-') {
        if (str_in_str(argv[1], "l")){
            print_total(argc, argv[2]);
            checkoption_l(argc, argv, dir);
        }
        if (str_in_str(argv[1], "a"))
            checkoption_a(argc, argv, dir);
    } else if (argc > 1)
        my_ls_folder(argc, argv, dirp);
    closedir(dir);
    return 0;
    }*/
