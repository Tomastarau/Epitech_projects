/*
** EPITECH PROJECT, 2023
** main antman
** File description:
** main
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "solver.h"
#include "my.h"
#include "printf.h"

void print_tab(char** maze, int nb_line)
{
    int i = 0;
    while (maze[i] != NULL){
        printf("%s", maze[i]);
        if (i < nb_line - 1) {
            printf("\n");
        }
        i++;
    }
}

int send_error(char* str)
{
    if (strcmp(str, "./generator") == 0){
        write(2, "Usage: './generator x y'. Add '[perfect]' \
to make a perfect maze.\nNote: x != y.\n", 81);
        exit(84);
    }
    if (strcmp(str, "./solver") == 0){
        write(2, "Usage: './solver maze.txt'\n", 28);
        return 84;
    }
    return 84;
}

int check_file_exist(const char *filepath)
{
    FILE *fp;
    fp = fopen(filepath, "r");
    if (fp == NULL)
        return 84;
    else {
        fclose(fp);
        return 0;
    }
}

int error_checker(int argc, char* argv[])
{
    if ((strcmp(argv[0], "./generator") == 0 && argc < 3) || (strcmp(argv[0], \
"./generator") == 0 && argc > 4) || (strcmp(argv[0], "./generator") == 0 && \
isdigit(atoi(argv[1])) == 1 ) || (strcmp(argv[0], "./generator") == 0 && \
isdigit(atoi(argv[2])) == 1))
        return 84;
    if ((strcmp(argv[0], "./solver") == 0 && argc != 2) || (strcmp(argv[0], \
"./solver") == 0 && check_file_exist(argv[1]) == 84))
        return 84;
    return 0;
}

int main(int argc, char* argv[]){
    int x = 0, y = 0;
    if (argc < 3 || argc > 4 || error_checker(argc, argv) == 84) {
        send_error(argv[0]);
        return 84;
    }
    if (!isdigit(*argv[1]) || !isdigit(*argv[2])) {
        send_error(argv[0]);
        return 84;
    }
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (argc == 3) {
        return (create_imperfect_maze(x, y));
    }
    if (argc == 4 && strcmp(argv[3], "perfect") == 0){
        return (create_perfect_maze(x, y));
    }
    send_error(argv[0]);
    return 84;
}
