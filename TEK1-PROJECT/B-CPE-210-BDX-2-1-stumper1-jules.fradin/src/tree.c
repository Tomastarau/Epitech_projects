/*
** EPITECH PROJECT, 2023
** tree
** File description:
** tree
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include "tree.h"

static options get_options(int const argc, char const *const *argv)
{
    options tree_options = (options) {
            .a = false,
            .d = false,
            .L = false,
            .f = false,
    };
    if (argc == 1) {
        return tree_options;
    }
    for (int cross_argv = 1; argv[cross_argv] != NULL; cross_argv++) {
        if (my_strstr(argv[cross_argv], "a")) tree_options.a = true;
        if (my_strstr(argv[cross_argv], "d")) tree_options.d = true;
        if (my_strstr(argv[cross_argv], "L")) tree_options.L = true;
        if (my_strstr(argv[cross_argv], "f")) tree_options.f = true;
    }
    return tree_options;
}

int tree(int const argc, char const *const *argv)
{
    options tree_options = get_options(argc, argv);
    struct dirent *dirp;
    DIR *dir = opendir(".");
    dirp = readdir(dir);
    print_file_folder(argc, ".", dirp);
    return 0;
}
