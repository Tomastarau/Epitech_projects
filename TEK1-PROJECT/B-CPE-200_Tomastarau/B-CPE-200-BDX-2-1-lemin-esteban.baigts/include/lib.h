/*
** EPITECH PROJECT, 2023
** lemin [WSL : Ubuntu]
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include "room.h"
    #include "list_utils.h"

/* LIB */
void free_arr(char **arr);
int get_arr_len(char **arr);
int str_len(char const *str);
void free_list(list_t *list);
void reset_list(list_t *list);
char *str_dup(char const *src);
int str_to_num(char const *str);
int print_nbr(int nb, char separator);
char *str_chr(char const *str, int ch);
char *str_cpy(char *dest, char const *src);
int str_cmp(char const *s1, char const *s2);
void add_to_list(list_t *list, void *buffer);
int print_buf(char const *str, char separator);
int print_error(char const *str, char separator);
char *strn_cpy(char *dest, char const *src, int n);
char **str_to_word_array(char const *str, char delim);
static int get_words_count(char const *str, char delim);
static void display_digit(int digit_count, long cur_div);

#endif /* !LIB_H_ */
