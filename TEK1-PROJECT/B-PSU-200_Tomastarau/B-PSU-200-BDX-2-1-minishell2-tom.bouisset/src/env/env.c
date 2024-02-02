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
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

int unset_env(const char *name, node_t* env, int argc)
{
    node_t *temp_env = env;
    if (argc == 1) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 84;
    }
    int i = 0, name_len = my_strlen(name);
    while (temp_env != NULL) {
        if (my_strncmp(name, temp_env->data, name_len) == 0){
            delete_node(&temp_env, temp_env->data);
            return 0;
        }
        i++;
        temp_env = temp_env->next;
    }
    return 0;
}

int env_fonction(char **argv, node_t *env, int argc)
{
    if (my_strcmp(argv[0], "setenv") == 0 && argc == 2){
        if (env_error(argv) == 84)
            return 84;
        set_new_env_no_value(argv[1], env);
        return 0;
    }
    if ((my_strcmp(argv[0], "env") == 0) || (my_strcmp(argv[0], "setenv") == 0 \
&& argc == 1))
        display_list(env);
    if (my_strcmp(argv[0], "setenv") == 0 && argc != 1){
        if (env_error(argv) == 84)
            return 84;
        set_new_env(argv[1], argv[2], env);
        return 0;
    }
    if (my_strcmp(argv[0], "unsetenv") == 0){
        unset_env(argv[1], env, argc);
        return 0;
    }
    return 0;
}

node_t *replace_env_oldpwd(node_t *env, char *oldpwd)
{
    char *variable = "OLDPWD=";
    node_t *temp_env = env;
    char *full_oldpwd = malloc(sizeof(char) * (my_strlen(variable) + my_strlen(\
oldpwd) + 1));
    my_memset(full_oldpwd, '\0', my_strlen(variable) + my_strlen(oldpwd) + 1);
    int var_len = my_strlen(variable);
    char *newpwd = malloc(sizeof(char) * (my_strlen(oldpwd) + var_len + 1));
    my_memset(newpwd, '\0', (my_strlen(oldpwd) + var_len + 1));
    my_strcat(full_oldpwd, variable);
    my_strcat(full_oldpwd, oldpwd);
    while (temp_env->next != NULL) {
        if (my_strncmp(temp_env->data, variable, var_len) == 0 && \
my_strcmp(full_oldpwd, temp_env->data) != 0) {
            my_strcpy(newpwd, full_oldpwd);
            update_node(temp_env, temp_env->data, newpwd);
            break;
        }
        temp_env = temp_env->next;
    }
    return temp_env;
}

char* search_env(char* variable, node_t *env)
{
    char *variable_content = NULL;
    node_t *temp_env = env;
    int exist = 0;
    int var_len = my_strlen(variable);
    for (int i = 0; temp_env->next != NULL; i++) {
        if (my_strncmp(temp_env->data, variable, var_len) == 0) {
            variable_content = malloc(sizeof(char) * \
(my_strlen(temp_env->data) - var_len + 1));
            exist++;
            my_strncpy(variable_content, temp_env->data + var_len, \
my_strlen(temp_env->data) - var_len);
            variable_content[my_strlen(temp_env->data) - var_len] = '\0';
            break;
        }
        temp_env = temp_env->next;
    }
    if (exist == 0){
        return "";
    }
    return (variable_content);
}

node_t *create_new_env_list(char **env)
{
    int i = 0;
    node_t *new_list = NULL;
    while (env[i] != NULL){
        insert_at_end(&new_list, env[i]);
        i++;
    }
    return new_list;
}
