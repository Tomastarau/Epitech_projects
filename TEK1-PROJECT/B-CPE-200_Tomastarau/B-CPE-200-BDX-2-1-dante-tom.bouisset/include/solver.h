/*
** EPITECH PROJECT, 2023
** solver.h
** File description:
** h file for the solver part of dante
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
    #include <dirent.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct data_s {
    int widht;
    int height;
    int act_x;
    int act_y;
} data_t;

char **my_str_array(char const *str);

char *file_to_str(char const *filepath);

int error_maze(char *filepath);

int create_perfect_maze(int a, int b);

int height_maze(char *filepath);

void print_tab(char** maze, int nb_line);

int send_error(char* str);

int error_checker(int argc, char* argv[]);

int widht_maze(char *filepath);

char **fill_map_perfect(char **maze, int a, int y, int b);

char **fill_map_imperfect(char **maze, int a, int y, int b);

int create_imperfect_maze(int a, int b);

int a_star(char **maze);

int special_cases(int a, int b);

#endif /* !SOLVER_H_ */
