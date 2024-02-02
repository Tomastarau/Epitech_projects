/*
** EPITECH PROJECT, 2023
** setenv no value
** File description:
** set_env_no_value
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

int check_cd_error_exist(char **argv, int argc, char ***env)
{
    if (argc > 1 && my_strcmp(argv[1], "-") != 0){
        if (folder_exist(argv) == 84) {
            return 84;
        }
    }
    if (argc > 1 && my_strcmp(argv[1], "-") == 0){
        if (!opendir(search_env("OLDPWD=", *env)) && \
my_strcmp(search_env("OLDPWD=", *env), "") == 0){
            return 84;
        }
    }
    if (argc == 1) {
        if (!opendir(search_env("HOME=", *env))) {
            write(2, "failed to reach HOME directory\n", 32);
            return 84;
        }
    }
    return 0;
}

char **modif_pwd_env(char **env)
{
    char *variable = "PWD=";
    char *pwd = getcwd(NULL, 0);
    char *new_pwd = malloc(sizeof(char) * (my_strlen(variable) + my_strlen(\
pwd) + 1));
    my_memset(new_pwd, '\0', my_strlen(variable) + my_strlen(pwd) + 1);
    int var_len = my_strlen(variable), i = 0;
    my_strcat(new_pwd, variable);
    my_strcat(new_pwd, pwd);
    while (env[i] != NULL) {
        if (my_strncmp(env[i], variable, var_len) == 0 && my_strcmp(new_pwd\
, env[i]) != 0) {
            env[i] = new_pwd;
        }
        i++;
    }
    return env;
}

char* name_string(const char *name)
{
    char *new_name = malloc(sizeof(char) * (my_strlen(name) + 2));
    my_memset(new_name, '\0', (my_strlen(name) + 2));
    my_strcat(new_name, name);
    my_strcat(new_name, "=");
    return new_name;
}

char** re_write_env_no_val(char **new_env, char* name, int i)
{
    int name_len = my_strlen(name);
    new_env[i] = malloc(sizeof(char) * (name_len + 1));
    my_memset(new_env[i], '\0', name_len + 1);
    my_strcat(new_env[i], name);
    return new_env;
}

char** set_new_env_no_value(char *name, char** env)
{
    int len_ev = len_of_2d_array(env), i = 0, j = 0;
    char **new_env = malloc(sizeof(char *) * (len_ev + 2));
    char *new_name = name_string(name);
    while (env[i] != NULL) {
        if (set_env_verification(env, name, 1, i) == 1){
            new_env = re_write_env(new_env, new_name, i);
            j++;
            i++;
            continue;
        }
        if (set_env_verification(env, name, 2, i) == 2) {
            return final_var_len_ev(new_env, new_name, i, len_ev);
        }
        new_env = sub_set_new_env(env, new_env, i);
        i++;
    }
    if (j == 0)
        return final_var_len_ev_1(new_env, new_name, i, len_ev);
    new_env[i] = NULL;
    return new_env;
}
