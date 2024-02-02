/*
** EPITECH PROJECT, 2023
** fonctions_that_handle_pipes
** File description:
** pipe_exec_fonction
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

void pipe_builtin_or_not(node_t *env_list, char *const *commands)
{
    char **env = linked_list_to_char_array(env_list);
    if (is_builtin(commands[0]) == 0) {
        exec_builtin((char **)commands, len_of_2d_array((char **)commands), \
env_list);
    } else {
        char *path = try_every_path_command((char **)commands, env_list);
        if (path == NULL) {
            exit(EXIT_FAILURE);
        }
        execve(path, commands, env);
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

void exec_pipe_commands(int i, char *const *commands, int* pipe_fds, node_t \
*env_list)
{
    int num_commands = 0;
    while (commands[num_commands] != NULL)
        num_commands++;
    int num_pipes = num_commands - 1;
    if (i > 0)
        dup2(pipe_fds[(i - 1) * 2], STDIN_FILENO);
    if (i < num_commands - 1)
        dup2(pipe_fds[i * 2 + 1], STDOUT_FILENO);
    for (int j = 0; j < 2 * num_pipes; j++)
        close(pipe_fds[j]);
    pipe_builtin_or_not(env_list, commands);
}

static void close_file_and_child(int num_pipes, int *pipe_fds, int num_commands)
{
    for (int i = 0; i < 2 * num_pipes; i++) {
        close(pipe_fds[i]);
    }
    for (int i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}

void pipe_child_and_parent(int i, char** commands, node_t *env_list, \
int *pipe_fds)
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        char *const *array_input = my_str_to_word_array_3(commands[i]);
        exec_pipe_commands(i, array_input, pipe_fds, env_list);
        for (int j = 0; commands[j] != NULL; j++) {
            free(commands[j]);
        }
        free(commands);
        return;
    }
}

void pipe_ditrib(char** commands, node_t *env_list)
{
    int num_commands = 0;
    while (commands[num_commands] != NULL) {
        num_commands++;
    }
    int num_pipes = num_commands - 1;
    int pipe_fds[2 * num_pipes];
    for (int i = 0; i < num_pipes; i++) {
        if (pipe(pipe_fds + i * 2) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < num_commands; i++) {
        pipe_child_and_parent(i, commands, env_list, pipe_fds);
    }
    close_file_and_child(num_pipes, pipe_fds, num_commands);
}
