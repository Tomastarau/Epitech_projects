/*
** EPITECH PROJECT, 2023
** connection.c
** File description:
** make the connections between the two terminal
*/

#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

void handle_sig(int signum)
{
    if (signum == SIGUSR1) {
        my_printf("enemy connected\n\n");
    }
    if (signum == SIGUSR2) {
        size_t buff_size = 3;
        char *buffer = (char *)malloc(sizeof(char) * buff_size);
        getline(&buffer, &buff_size, stdin);
        buffer[2] = '\0';
        my_printf("Enemy attacked at: %s\n", buffer);
        free(buffer);
    }
}

void connection(int argc, char **argv)
{
    signal(SIGUSR1, &handle_sig);
    signal(SIGUSR2, &handle_sig);
    if (argc == 2) {
        pid_t pid_1 = getpid();
        print_sigusr1(pid_1);
        pause();
    }
    if (argc == 3) {
        pid_t pid_1 = my_getnbr(argv[1]);
        pid_t pid_2 = getpid();
        print_sigusr2(pid_2);
        kill(pid_1, SIGUSR1);
    }
}
