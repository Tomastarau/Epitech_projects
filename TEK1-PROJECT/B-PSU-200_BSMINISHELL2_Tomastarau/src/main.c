/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
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

char *const *my_str_to_word_array_3(char const *str)
{
    int y = count_word_number_2(str);
    char **result = malloc(sizeof(char *) * (y + 1));
    int a = space_correction_2(str, 0), b = 0, c = 0;
    while (b < y){
        c = 0;
        result[b] = malloc(sizeof(char) * (len_of_word_2(str, a) + 1));
        while (str[a] != '\0' && is_a_character_2(str[a]) != 0) {
            result[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        result[b][c] = '\0';
        a = space_correction_2(str, a);
        b = b + 1;
    }
    result[b] = NULL;
    return result;
}

char* try_every_path_command(char **args, node_t *env_list)
{
    int i = 0;
    if (!args[0])
        return 0;
    char **path = my_str_slash_to_word_array(args[0]);
    char **path_env = my_str_to_word_array(search_env("PATH=", env_list));
    char *final_path = malloc(sizeof(char) * (my_strlen(path_env[0]) + \
my_strlen(path[len_of_2d_array(path) - 1]) + 2));
    while (path_env[i] != NULL) {
        final_path = fillpath(final_path, path, path_env, i);
        if (access(final_path, F_OK) != -1) {
            return final_path;
        }
        i++;
    }
    free(final_path);
    return NULL;
}

void print_tab(char** tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
    return;
}

void free_list(node_t** head)
{
    node_t* current = *head;
    node_t* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

int main (int argc, char** argv, char** env)
{
    node_t *new_env_list = create_new_env_list(env);
    if (argc != 1) {
        write(2, "too much arguments !\n", 22);
        return 84;
    }
    (void) argv;
    mysh(new_env_list);
    free(new_env_list);
    return 0;
}
