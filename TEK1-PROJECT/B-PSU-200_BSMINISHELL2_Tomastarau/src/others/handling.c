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

void write_prompt(node_t* env)
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

int handle_parent(char*** args, char** pathname, node_t *env_list)
{
    char *input = NULL;
    size_t input_size = 0;
    write_prompt(env_list);
    if (getline(&input, &input_size, stdin) == -1) {
            write(2, "exit\n", 5);
            exit(0);
    }
    if (my_strlen(input) == 1) {
        return (0);
    }
    *args = my_str_to_word_array_2(input);
    *pathname = malloc(sizeof(char) * (my_strlen((*args)[0]) + \
my_strlen("/bin/") + 1));
    my_memset(*pathname, '\0', my_strlen((*args)[0]) + my_strlen("/bin/") + 1);
    my_strcat(*pathname, "/bin/");
    my_strcat(*pathname, (*args)[0]);
    parse_builtin(*args, env_list);
    return 0;
}
