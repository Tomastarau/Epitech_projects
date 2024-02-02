/*
** EPITECH PROJECT, 2023
** my_antman
** File description:
** my_antman
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "solver.h"
#include "my.h"
#include "printf.h"

int array_contains(int *array, int size, int value)
{
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}

int special_cases(int a, int b)
{
    char **maze = malloc(sizeof(char *) * b + 1);
    if (b == 1 && a > 1) {
        maze[0] = malloc(sizeof(char) * a + 1);
        for (int y = 0; y != a; y++){
            maze[0][y] = '*';
        }
        maze[a] = '\0';
    } else {
        return 1;
    }
    maze[b] = NULL;
    print_tab(maze, b);
    return 0;
}

int create_perfect_maze(int a, int b)
{
    srand(time(NULL));
    if (a <= 0 || b <= 0)
        send_error("./generator");
    char **maze = malloc(sizeof(char *) * b + 1);
    if (special_cases(a, b) == 0) {
        return 0;
    }
    for (int y = 0; y != b; y++){
        maze[y] = malloc(sizeof(char) * a + 1);
        memset(maze[y], '\0', a + 1);
        maze = fill_map_perfect(maze, a, y, b);
    }
    maze[b] = NULL;
    print_tab(maze, b);
    return 0;
}

int create_imperfect_maze(int a, int b)
{
    srand(time(NULL));
    if (a <= 0 || b <= 0)
        send_error("./generator");
    char **maze = malloc(sizeof(char *) * b + 1);
    if (special_cases(a, b) == 0) {
        return 0;
    }
    for (int y = 0; y != b; y++) {
        maze[y] = malloc(sizeof(char) * a + 1);
        memset(maze[y], '\0', a + 1);
        maze = fill_map_imperfect(maze, a, y, b);
    }
    maze[b] = NULL;
    print_tab(maze, b);
    return 0;
}
