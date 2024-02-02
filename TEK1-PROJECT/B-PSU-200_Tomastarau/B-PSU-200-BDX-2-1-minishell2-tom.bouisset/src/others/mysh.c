/*
** EPITECH PROJECT, 2023
** basic functions
** File description:
** functions
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

char* name_value_string(const char *name, const char *value)
{
    char *name_value = malloc(sizeof(char) * (my_strlen(name) + \
my_strlen(value) + 2));
    my_memset(name_value, '\0', (my_strlen(name) + my_strlen(value) + 2));
    my_strcat(name_value, name);
    my_strcat(name_value, "=");
    my_strcat(name_value, value);
    return name_value;
}

void free_2d_array(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}

int len_of_2d_array(char** tab)
{
    int i = 0;
    while (tab[i] != NULL){
        i++;
    }
    return i;
}

int len_of_chained_list(node_t *env)
{
    int i = 0;
    node_t *temp_env = env;
    while (temp_env->next != NULL){
        temp_env = temp_env->next;
        i++;
    }
    return i;
}

int mysh(node_t *env_list)
{
    char *pathname = "/bin/";
    char **args = NULL;
    while (1) {
        handle_parent(&args, &pathname, env_list);
    }
    return 0;
}
