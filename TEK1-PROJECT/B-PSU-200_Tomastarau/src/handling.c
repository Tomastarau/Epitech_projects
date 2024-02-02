/*
** EPITECH PROJECT, 2023
** all handling focntions
** File description:
** handling
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

int env_error(char** argv)
{
    if (argv[1][0] >= '0' && argv[1][0] <= '9'){
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 84;
    }
    if (my_str_isalpha(argv[1]) == 1){
        write(2, "setenv: Variable name must contain alphanumeric \
characters.\n", 61);
        return 84;
    }
    return 0;
}

int handle_exit(char **argv, int argc)
{
    if (argc == 2){
        if (my_str_isnum(argv[1]) == 0) {
            exit(my_getnbr(argv[1]));
        }
    }
    if (argc > 2) {
        write(1, "exit: too many arguments\n", 26);
        exit(84);
    }
    if (my_strcmp(argv[0], "exit") == 0) {
        exit(0);
    }
    return 0;
}

void handle_child(char** args, char *pathname, char** env)
{
    if (!args || !pathname || !env) {
        exit (84);
    }
    if (path_handling(pathname, args, env) == 84 && my_strcmp(args[0], "cd") \
!= 0 && \
my_strcmp(args[0], "setenv") != 0 && my_strcmp(args[0], "unsetenv") != 0 && \
my_strcmp(args[0], "env") && my_strcmp(args[0], "exit") != 0) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 22);
        exit(0);
    }
    exit(0);
}

void write_prompt(char** env)
{
    char* user_name = search_env("USER=", env);
    char* host_name = search_env("HOSTNAME=", env);
    char *cwd = getcwd(NULL, 0);
    int len_user = my_strlen(user_name);
    int len_host = my_strlen(host_name);
    if (!user_name) {
        user_name = "unknown";
    }
    if (!host_name) {
        host_name = "unknown";
    }
    write(1, "[", 1);
    write(1, user_name, len_user);
    write(1, "@", 1);
    write(1, host_name, len_host);
    write(1, " ", 1);
    write(1, cwd, my_strlen(cwd));
    write(1, "]$ ", 3);
}

int handle_parent(int pid, char*** args, char** pathname, char*** env)
{
    int status = 0;
    char *input = NULL;
    size_t input_size = 0;
    waitpid(pid, &status, 0);
    write_prompt(*env);
    if (getline(&input, &input_size, stdin) == -1) {
            write(2, "exit\n", 5);
            exit(0);
    }
    if (my_strlen(input) == 1) {
        return (0);
    }
    *args = my_str_to_word_array_2(input);
    exec_builtin(*args, len_of_2d_array(*args), env);
    *pathname = malloc(sizeof(char) * (my_strlen((*args)[0]) + \
my_strlen("/bin/") + 1));
    my_memset(*pathname, '\0', my_strlen((*args)[0]) + my_strlen("/bin/") + 1);
    my_strcat(*pathname, "/bin/");
    my_strcat(*pathname, (*args)[0]);
    return 0;
}
