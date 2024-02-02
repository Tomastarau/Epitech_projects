/*
** EPITECH PROJECT, 2023
** fillmap fonction
** File description:
** fill_map
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

char **fill_map_imperfect(char **maze, int a, int y, int b)
{
    for (int x = 0; x != a; x++){
        if (y == 0){
            maze[y][x] = 'X';
            maze[y][0] = '*';
            continue;
        }
        if (y % 2 != 0){
            maze[y][x] = '*';
            continue;
        }
        maze[y][x] = 'X';
        if (y % 2 == 0 && y != 0 && y != b - 1) {
            maze[y][rand() % a] = '*';
            continue;
        }  else {
            maze[y][a - 1] = '*';
        }
    }
    return maze;
}

char **fill_map_perfect(char **maze, int a, int y, int b)
{
    int random_num = rand() % a;
    for (int x = 0; x != a; x++){
        if (y == 0){
            maze[y][x] = 'X';
            maze[y][0] = '*';
            continue;
        }
        if (y % 2 != 0){
            maze[y][x] = '*';
            continue;
        }
        maze[y][x] = 'X';
        if (y % 2 == 0 && y != 0 && y != b - 1) {
            maze[y][random_num] = '*';
            continue;
        }  else {
            maze[y][a - 1] = '*';
        }
    }
    return maze;
}
