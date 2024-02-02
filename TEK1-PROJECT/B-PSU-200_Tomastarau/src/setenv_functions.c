/*
** EPITECH PROJECT, 2023
** setenv fonctions
** File description:
** setenv_functions
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

int set_env_verification(char **env, const char *name, int specificator, int i)
{
    int len_ev = len_of_2d_array(env), name_len = my_strlen(name);
    if (specificator == 1 && my_strncmp(name, env[i], name_len) == 0 && \
env[i][name_len] == '=' && (i != len_ev - 1)){
        return 1;
    }
    if (specificator == 2 && my_strncmp(name, env[i], name_len) == 0 && \
env[i][name_len] == '=' && (i == len_ev - 1)){
        return 2;
    }
    return 0;
}

char **sub_set_new_env(char **env, char** new_env, int i)
{
    new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    my_memset(new_env[i], '\0', my_strlen(env[i]) + 1);
    my_strcat(new_env[i], env[i]);
    return new_env;
}

char **final_var_len_ev_1(char** new_env, char* name_value, int i, int len_ev)
{
    new_env = re_write_env(new_env, name_value, i);
    new_env[len_ev + 1] = NULL;
    return new_env;
}

char **final_var_len_ev(char** new_env, char* name_value, int i, int len_ev)
{
    new_env = re_write_env(new_env, name_value, i);
    new_env[len_ev] = NULL;
    return new_env;
}

char** set_new_env(const char *name, const char *value, char** env)
{
    int len_ev = len_of_2d_array(env), i = 0, j = 0;
    char **new_env = malloc(sizeof(char *) * (len_ev + 2));
    char *name_value = name_value_string(name, value);
    while (env[i] != NULL) {
        if (set_env_verification(env, name, 1, i) == 1){
            new_env = re_write_env(new_env, name_value, i);
            j++;
            i++;
            continue;
        }
        if (set_env_verification(env, name, 2, i) == 2){
            return final_var_len_ev(new_env, name_value, i, len_ev);
        }
        new_env = sub_set_new_env(env, new_env, i);
        i++;
    }
    if (j == 0)
        return final_var_len_ev_1(new_env, name_value, i, len_ev);
    new_env[i] = NULL;
    return new_env;
}
