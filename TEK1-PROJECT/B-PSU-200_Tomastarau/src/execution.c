/*
** EPITECH PROJECT, 2023
** execution functions
** File description:
** execution
*/

/*
** EPITECH PROJECT, 2023
** create new env and execution builtin
** File description:
** env_and_execution
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

int check_exec_exist(char* executable_name)
{
    char* path = malloc(sizeof(char) * my_strlen(executable_name) + \
my_strlen("/bin/") + 1);
    my_memset(path, '\0', my_strlen(executable_name) + \
my_strlen("/bin/") + 1);
    my_strcat(path, "/bin/");
    my_strcat(path, executable_name);
    if (access(path, F_OK) != -1) {
        free(path);
        return 84;
    } else {
        free(path);
        return 0;
    }
}

int chdir_access_error(char **argv, int argc, char*** env)
{
    char *cwd = getcwd(NULL, 0);
    if (argc == 1 || (argc == 2 && my_strcmp(argv[1], "~") == 0)) {
        if (chdir(search_env("HOME=", *env)) != 0){
            write(2, "Failed to change directory\n", 28);
            return 84;
        }
        *env = replace_env_oldpwd(*env, cwd);
    }
    if (argc == 2) {
        if (my_strcmp(argv[1], "-") != 0) {
            chdir(argv[1]);
            *env = replace_env_oldpwd(*env, cwd);
            return 0;
        }
        if (my_strcmp(argv[1], "-") == 0) {
            chdir(search_env("OLDPWD=", *env));
            *env = replace_env_oldpwd(*env, cwd);
        }
    }
    return 0;
}

int folder_exist(char **argv)
{
    struct stat stats;
    stat(argv[1], &stats);
    if (stat(argv[1], &stats) != 0) {
        write(2, argv[1], my_strlen(argv[1]));
        write(2, ": No such file or directory.\n", 30);
        return (84);
    }
    if (S_ISDIR(stats.st_mode) == 0) {
        write(2, argv[1], my_strlen(argv[1]));
        write(2, ": Not a directory.\n", 20);
        return (84);
    }
    return 0;
}

int exec_env_command(char** argv, char** env)
{
    if (!argv || !env){
        exit(84);
    }
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
    return 0;
}

int exec_builtin(char **argv, int argc, char*** env)
{
    if (argc != 0) {
        *env = modif_pwd_env(*env);
        if (my_strcmp(argv[0], "cd") == 0 && check_cd_error_exist(argv, argc, \
env) == 0) {
            chdir_access_error(argv, argc, env);
            return 0;
        }
        if (env_fonction(argv, env, argc) == 1){
            return 0;
        }
        if (my_strcmp(argv[0], "exit") == 0) {
            handle_exit(argv, argc);
            return 0;
        }
    }
    return 0;
}
