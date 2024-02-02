/*
** EPITECH PROJECT, 2023
** full_path fonctions
** File description:
** full_path
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

static char* fill_final_path(char* final_path, char **path, char** path_env, \
int i)
{
    my_memset(final_path, '\0', my_strlen(path_env[i]) + \
my_strlen(path[len_of_2d_array(path) - 1]) + 2);
    my_strcat(final_path, path_env[i]);
    my_strcat(final_path, "/");
    my_strcat(final_path, path[len_of_2d_array(path) - 1]);
    return final_path;
}

int path_handling(char* pathname, char** args, char** env)
{
    char** path = my_str_slash_to_word_array(args[0]);
    char** path_env = my_str_to_word_array(search_env("PATH=", env));
    char* final_path = malloc(sizeof(char) * (my_strlen(path_env[0]) + \
my_strlen(path[len_of_2d_array(path) - 1]) + 2));
    int i = 0;
    if (is_slash(args[0]) == 0 && access(pathname, F_OK) != -1) {
        execve(pathname, args, env);
        exit (0);
    }
    while (path_env[i] != NULL){
        final_path = fill_final_path(final_path, path, path_env, i);
        if (access(final_path, F_OK) != -1) {
            execve(final_path, args, env);
            exit(0);
        }
        i++;
    }
    free(final_path);
    return 84;
}

int is_slash(char* str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '/') {
            return 1;
        }
        i++;
    }
    return 0;
}
