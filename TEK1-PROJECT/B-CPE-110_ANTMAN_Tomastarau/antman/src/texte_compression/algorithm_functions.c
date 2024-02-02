/*
** EPITECH PROJECT, 2023
** algorithm_functions
** File description:
** algorithm_functions
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
#include "../../../include/my.h"
#include "../../../include/my_printf.h"
#include "../../../include/my_antman.h"

int check_tab_if_dup_and_replace(char **tab, char *word, int i_table_comp)
{
    int i = 0;
    char *table_of_compression[9] = {"@~", "@&", "@@", "@`", "øø", "øµ", "ø§", \
"ø°", "ø¨"};
    while (tab[i] != NULL){
        if (my_strcmp(tab[i], word) == 0){
            tab[i] = table_of_compression[i_table_comp];
        }
        i++;
    }
    return 0;
}

void compressing_algo(char **tab, char **tab_of_dup, int i_sec_tab)
{
    int j = 0;
    int i = 0;
    while (j < i_sec_tab){
        check_tab_if_dup_and_replace(tab, tab_of_dup[j], i);
        i++;
        j++;
    }
}

int check_tab_if_dup(char **tab, char *word)
{
    int i = 0;
    while (tab[i] != NULL){
        if (my_strcmp(tab[i], word) == 0){

            return 1;
        }
        i++;
    }
    return 0;
}

char **check_howmany_same(char *tab[], char**tab_of_dup, int i, int j)
{
    static int i_sec_tab = 0;
    if (i != j && my_strcmp(tab[i], tab[j]) == 0 && my_strlen(tab[i]) > 2 && \
check_tab_if_dup(tab_of_dup, tab[i]) == 0 && i_sec_tab < 9 && \
(is_character(tab[i][0]) == 1 || is_character(tab[i][0]) == 2)){
        tab_of_dup[i_sec_tab] = malloc(sizeof(char) * my_strlen(tab[i]));
        tab_of_dup[i_sec_tab] = tab[i];
        i_sec_tab++;
    }
    return tab_of_dup;
}

void my_text_compression(char *str)
{
    char **tab = my_str_to_word_array(str);
    char *tab_of_dup[9] = {NULL};
    char *str_of_dup = {'\0'}, *new_str = {'\0'};
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = i; tab[j] != NULL; j++) {
            check_howmany_same(tab, tab_of_dup, i, j);
        }
    }
    if (tab_of_dup[0] == NULL){
        send_same_file(str);
        return;
    }
    compressing_algo(tab, tab_of_dup, my_strstrlen(tab_of_dup));
    new_str = concatenate_double_array(tab);
    str_of_dup = concatenate_double_array_of_dup(tab_of_dup);
    str_to_standard_output(new_str, str_of_dup);
}
