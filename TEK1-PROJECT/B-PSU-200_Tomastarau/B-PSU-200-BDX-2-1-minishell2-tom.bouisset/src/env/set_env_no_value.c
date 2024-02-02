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

char *get_dir_path(char **argv, int argc, node_t *env)
{
    if (argc > 1) {
        if (my_strcmp(argv[1], "-") == 0) {
            return search_env("OLDPWD=", env);
        } else {
            return argv[1];
        }
    }
    return search_env("HOME=", env);
}

int check_cd_error_exist(char **argv, int argc, node_t *env)
{
    char *dir_path = get_dir_path(argv, argc, env);
    if (argc > 1 && my_strcmp(argv[1], "-") != 0 && folder_exist(argv) == 84) {
        return 84;
    }
    DIR *dir = opendir(dir_path);
    if (!dir || chdir_access_error(argv, argc, env) == 84) {
        write(2, ": No such file or directory.\n", 30);
        return 84;
    }
    closedir(dir);
    return 0;
}

node_t *modif_pwd_env(node_t *env)
{
    char *variable = "PWD=";
    char *pwd = getcwd(NULL, 0);
    char *new_pwd = malloc(sizeof(char) * (my_strlen(variable) + my_strlen(\
pwd) + 1));
    node_t *temp_env = env;
    my_memset(new_pwd, '\0', my_strlen(variable) + my_strlen(pwd) + 1);
    int var_len = my_strlen(variable);
    my_strcat(new_pwd, variable);
    my_strcat(new_pwd, pwd);
    while (temp_env->next != NULL) {
        if (my_strncmp(temp_env->data, variable, var_len) == 0 && \
my_strcmp(new_pwd, temp_env->data) != 0) {
            update_node(temp_env, temp_env->data, new_pwd);
        }
        temp_env = temp_env->next;
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

void set_new_env_no_value(char *name, node_t* env)
{
    int i = 0, name_len = my_strlen(name);
    node_t *temp_env = env;
    char *new_name = name_string(name);
    while (temp_env != NULL) {
        if (my_strncmp(name, temp_env->data, name_len) == 0){
            update_node(temp_env, temp_env->data, new_name);
            return;
        }
        temp_env = temp_env->next;
        i++;
    }
    insert_at_end(&env, new_name);
    return;
}
