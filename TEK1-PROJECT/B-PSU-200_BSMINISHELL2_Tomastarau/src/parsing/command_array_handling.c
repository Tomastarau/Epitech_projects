/*
** EPITECH PROJECT, 2023
** all fonction that handle command array
** File description:
** command_array_handling
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

int trypath(char *final_path, char **args, char **env)
{
    if (access(final_path, F_OK) != -1) {
        if (execve(final_path, args, env) == -1) {
            perror("execve");
            return 84;
        }
        return 0;
    }
    return 84;
}

void handle_fork_exec(char **parsed_command, node_t *env_list)
{
    pid_t pid;
    int status;
    char **env = linked_list_to_char_array(env_list);
    pid = fork();
    if (pid == 0) {
        exec_simple_command(parsed_command[0], parsed_command, env_list, env);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_both(char **parsed_command, node_t *env_list)
{

    if (is_builtin(parsed_command[0]) == 0) {
        exec_builtin(parsed_command, len_of_2d_array(parsed_command), env_list);
    } else {
        handle_fork_exec(parsed_command, env_list);
    }
}

int separator_distribution(char **commands, node_t* env_list)
{
    char **no_pipe = NULL;
    for (int j = 0; commands[j] != NULL; j++) {
        if ((detect_separator(commands[j]) == 0 && \
is_there_this_delimiter(commands[j], '|') == false) || \
detect_separator(commands[j]) == -1) {
            exec_complexe_command(commands[j], env_list);
            continue;
        }
        if (detect_separator(commands[j]) == 1 || \
(detect_separator(commands[j]) == 0 && is_there_this_delimiter(commands[j], \
'|') == true)) {
            no_pipe = my_str_to_word_array_minishell(commands[j], '|');
            pipe_ditrib(no_pipe, env_list);
            continue;
        }
    }
    return 0;
}

int path_handling(char** args, node_t* env_list)
{
    int i = 0, len_total = 0;
    char *str = NULL;
    char **commands = NULL;
    len_total = len_verification(args);
    str = malloc(sizeof(char) * (len_total + 1));
    my_memset(str, '\0', len_total);
    for (i = 0; args[i] != NULL; i++) {
        strcat(str, args[i]);
        strcat(str, " ");
    }
    commands = str_commands_to_array(str);
    separator_distribution(commands, env_list);
    return 0;
}
