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

char* fillpath(char* final_path, char **path, char** path_env, int i)
{
    my_memset(final_path, '\0', my_strlen(path_env[i]) + \
my_strlen(path[len_of_2d_array(path) - 1]) + 2);
    my_strcat(final_path, path_env[i]);
    my_strcat(final_path, "/");
    my_strcat(final_path, path[len_of_2d_array(path) - 1]);
    return final_path;
}

int len_verification(char **args)
{
    int len_tot = 0;
    for (int i = 0; args[i] != NULL; i++){
        len_tot = len_tot + my_strlen(args[i]) + 1;
    }
    return len_tot;
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

void exec_complexe_command(char *command_array, node_t *env_list)
{
    int i = 0;
    char **no_semicolon = NULL;
    char **parsed_command = NULL;
    no_semicolon = my_str_to_word_array_minishell(command_array, ';');
    while (no_semicolon[i] != NULL && (detect_separator(no_semicolon[i]) == 0 \
|| detect_separator(no_semicolon[i]) == -1)) {
        parsed_command = my_str_to_word_array_2(no_semicolon[i]);
        handle_both(parsed_command, env_list);
        i++;
    }
}

int exec_simple_command(char *pathname, char **args, node_t *env_list, \
char **env)
{
    if (!args[0])
        return 84;
    char **path = my_str_slash_to_word_array(args[0]);
    char **path_env = my_str_to_word_array(search_env("PATH=", env_list));
    char *final_path = malloc(sizeof(char) * (my_strlen(path_env[0]) + \
my_strlen(path[len_of_2d_array(path) - 1]) + 2));
    if (is_slash(args[0]) == 0 && access(pathname, F_OK) != -1) {
        int res = trypath(pathname, args, env);
        free(final_path);
        return res;
    }
    for (int i = 0; path_env[i] != NULL; i++) {
        int res = trypath(fillpath(final_path, path, path_env, i), args, env);
        if (res == 0) {
            free(final_path);
            return res;
        }
    }
    return exec_error_simple_command(args, final_path);
}
