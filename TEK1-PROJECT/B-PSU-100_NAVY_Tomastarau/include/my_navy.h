/*
** EPITECH PROJECT, 2023
** my_navy.h
** File description:
** h file for my_navy project
*/

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_
    #include <signal.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <time.h>
    #include <ucontext.h>

typedef struct data_s {
    pid_t pid_1;
    pid_t pid_2;
    char *attack;
}data_t;

void h_option(void);

int kill_usr1(pid_t pid);

int kill_usr2(pid_t pid);

void connection(int argc, char **argv);

int letter_to_number_check(char letter);

void print_sigusr1(pid_t pid_1);

void print_sigusr2(pid_t pid_1);

void player_turn(char** map);

int if_x(char **map, int i, int j);

int parse_input(int argc, char **argv, char** map);

int my_navy(int argc, char** argv);

int attack_handler(char *buffer);

void print_position(char **map);

void if_hit(char* pos, char* map[]);

void wait_for_attack(void);

int verif_game_integrity(int argc, char* argv[]);

int check_boat_integrity(char* pos_folder);

int win_condition(char **map, char **argv);

int fill_map_boat(char **map, int i, int letter_pos, char **array_pos);

int add_map_boat(char *pos_folder, char** map);

int char_to_int(char c);

void print_tab(char **tab);

int letter_to_number(char letter);

void handle_sig(int signum);

#endif /* !MY_NAVY_H_ */
