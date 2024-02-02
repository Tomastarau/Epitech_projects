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
#include <errno.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

int chdir_error(int chdir_result, char* target_dir)
{
    if (chdir_result != 0) {
        perror(target_dir);
        return 84;
    }
    return 0;
}

int chdir_access_error(char **argv, int argc, node_t* env)
{
    char *cwd = getcwd(NULL, 0);
    int chdir_result, specificator = 0;
    char *target_dir = NULL;
    if (argc == 1 || (argc == 2 && my_strcmp(argv[1], "~") == 0)) {
        target_dir = search_env("HOME=", env);
        specificator++;
    } else if (argc == 2 && my_strcmp(argv[1], "-") == 0) {
        target_dir = search_env("OLDPWD=", env);
        specificator++;
    }
    if (argc == 2 && specificator == 0) {
        target_dir = argv[1];
    }
    if (target_dir) {
        chdir_result = chdir(target_dir);
        if (chdir_error(chdir_result, target_dir) == 84)
            return 84;
        replace_env_oldpwd(env, cwd);
    }
    return 0;
}

int folder_exist(char **argv)
{
    struct stat stats;
    if (stat(argv[1], &stats) != 0) {
        char *final_message = malloc(sizeof(char) * (my_strlen(argv[1]) + \
my_strlen(strerror(errno)) + 3));
        my_memset(final_message, '\0', (my_strlen(argv[1]) + \
my_strlen(strerror(errno)) + 3));
        my_strcat(final_message, argv[1]);
        my_strcat(final_message, ": ");
        my_strcat(final_message, strerror(errno));
        my_strcat(final_message, ".\n");
        write(2, final_message, my_strlen(final_message));
        return 84;
    }
    if (S_ISDIR(stats.st_mode) == 0) {
        cd_if_not_a_dir(argv);
        return 84;
    }
    return 0;
}

int exec_builtin(char **argv, int argc, node_t* env)
{
    if (argc != 0) {
        modif_pwd_env(env);
        if (my_strcmp(argv[0], "cd") == 0 && check_cd_error_exist(argv, argc, \
env) == 0) {
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

int parse_builtin(char **argv, node_t* env_list)
{
    char *pathname = malloc(sizeof(char) * (my_strlen((argv[0])) + \
my_strlen("/bin/") + 1));
    my_memset(pathname, '\0', my_strlen((argv[0])) + my_strlen("/bin/") + 1);
    my_strcat(pathname, "/bin/");
    my_strcat(pathname, (argv)[0]);
    path_handling(argv, env_list);
    return 0;
}
