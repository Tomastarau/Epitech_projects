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
#include <errno.h>
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
        if (my_strncmp(name_value, temp_env->data, name_len) == 0){
            update_node(temp_env, temp_env->data, name_value);
            return;
        }
        temp_env = temp_env->next;
        i++;
    }
    insert_at_end(&env, name_value);
    return;
}

int cd_if_not_a_dir(char **argv)
{
    errno = ENOTDIR;
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

int exec_error_simple_command(char **args, char* final_path)
{
    char error_msg[] = ": Command not found.\n";
    write(2, args[0], my_strlen(args[0]));
    write(2, error_msg, sizeof(error_msg) - 1);
    free(final_path);
    return 84;
}
