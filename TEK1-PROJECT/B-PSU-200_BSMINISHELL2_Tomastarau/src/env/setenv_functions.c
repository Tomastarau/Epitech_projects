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

int set_env_verif(node_t *env, const char *name, int specificator, int i)
{
    int len_ev = len_of_chained_list(env), name_len = my_strlen(name);
    if (specificator == 1 && my_strncmp(name, env->data, name_len) == 0 && \
(i != len_ev - 1)){
        return 1;
    }
    if (specificator == 2 && my_strncmp(name, env->data, name_len) == 0 && \
(i == len_ev - 1)){
        return 2;
    }
    return 0;
}

void set_new_env(const char *name, const char *value, node_t* env)
{
    int i = 0, name_len = my_strlen(name);
    node_t *temp_env = env;
    char *name_value = name_value_string(name, value);
    while (temp_env != NULL) {
        if (strncmp(name_value, temp_env->data, name_len) == 0){
            update_node(temp_env, temp_env->data, name_value);
            return;
        }
        temp_env = temp_env->next;
        i++;
    }
    insert_at_end(&env, name_value);
    return;
}
