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

char** re_write_env(char **new_env, const char *name_value, int i)
{
    int name_value_len = my_strlen(name_value);
    new_env[i] = malloc(sizeof(char) * (name_value_len + 1));
    my_memset(new_env[i], '\0', name_value_len + 1);
    my_strcat(new_env[i], name_value);
    return new_env;
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

int mysh(char** env)
{
    char *pathname = "/bin/";
    int pid = 0;
    char **args = NULL;
    while (1) {
        pid = fork();
        if (pid != 0){
            handle_parent(pid, &args, &pathname, &env);
        }
        if (pid == 0){
            handle_child(args, pathname ,env);
        }
    }
    return 0;
}
