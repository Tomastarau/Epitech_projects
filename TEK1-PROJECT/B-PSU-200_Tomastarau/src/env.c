/*
** EPITECH PROJECT, 2023
** all environment fonction
** File description:
** env
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

char** unset_env(const char *name, char** env)
{
    int len_env = len_of_2d_array(env), i = 0, j = 0;
    char **new_env = malloc(sizeof(char *) * (len_env + 2));
    while (env[i] != NULL) {
        if (set_env_verification(env, name, 1, i)){
            i++;
            continue;
        }
        if (set_env_verification(env, name, 2, i)){
            new_env[j] = NULL;
            return new_env;
        }
        new_env[j] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_memset(new_env[j], '\0', my_strlen(env[i]) + 1);
        my_strcat(new_env[j], env[i]);
        i++;
        j++;
    }
    new_env[j] = NULL;
    return new_env;
}

int env_fonction(char **argv, char*** env, int argc)
{
    if (my_strcmp(argv[0], "setenv") == 0 && argc == 2){
        if (env_error(argv) == 84){
            return 84;
        }
        *env = set_new_env_no_value(argv[1], *env);
        return 0;
    }
    if (my_strcmp(argv[0], "env") == 0){
        exec_env_command(argv, *env);
        return 0;
    }
    if (my_strcmp(argv[0], "setenv") == 0){
        *env = set_new_env(argv[1], argv[2], *env);
        return 0;
    }
    if (my_strcmp(argv[0], "unsetenv") == 0){
        *env = unset_env(argv[1], *env);
        return 0;
    }
    return 0;
}

char **replace_env_oldpwd(char **env, char *oldpwd)
{
    char *variable = "OLDPWD=";
    char *full_oldpwd = malloc(sizeof(char) * (my_strlen(variable) + my_strlen(\
oldpwd) + 1));
    my_memset(full_oldpwd, '\0', my_strlen(variable) + my_strlen(oldpwd) + 1);
    int var_len = my_strlen(variable), i = 0;
    char *newpwd = malloc(sizeof(char) * (my_strlen(oldpwd) + \
var_len + 1));
    my_memset(newpwd, '\0', (my_strlen(oldpwd) + var_len + 1));
    my_strcat(full_oldpwd, variable);
    my_strcat(full_oldpwd, oldpwd);
    while (env[i] != NULL) {
        if (my_strncmp(env[i], variable, var_len) == 0 && my_strcmp(full_oldpwd\
, env[i]) != 0) {
            my_strcpy(newpwd, full_oldpwd);
            env[i] = newpwd;
            break;
        }
        i++;
    }
    return env;
}

char* search_env(char* variable, char** env)
{
    char *variable_content = NULL;
    int exist = 0;
    int var_len = my_strlen(variable);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], variable, var_len) == 0) {
            variable_content = malloc(sizeof(char) * (my_strlen(env[i]) - \
var_len + 1));
            exist++;
            my_strncpy(variable_content, env[i] + var_len, \
my_strlen(env[i]) - var_len);
            variable_content[my_strlen(env[i]) - var_len] = '\0';
            break;
        }
    }
    if (exist == 0){
        return "";
    }
    return (variable_content);
}

char** create_new_env(char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char*) * (len_of_2d_array(env) + 1));
    while (env[i] != NULL){
        new_env[i] = malloc(sizeof(char) * my_strlen(env[i]));
        new_env[i] = env[i];
        i++;
    }
    new_env[i] = NULL;
    return new_env;
}
