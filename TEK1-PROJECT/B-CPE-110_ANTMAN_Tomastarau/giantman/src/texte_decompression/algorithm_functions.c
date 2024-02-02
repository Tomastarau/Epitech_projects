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

char **fill_tab_of_dup(char const *str)
{
    char *str1 = {'\0'};
    char **final_str;
    int i = 0;
    while (str[i] != '\n'){
        i++;
    }
    str1 = malloc(sizeof(char) * i + 1);
    i = 0;
    while (str[i] != '\n'){
        str1[i] = str[i];
        i++;
    }
    final_str = my_str_to_word_array_2(str1);
    return final_str;
}

char **fill_tab_of_dup_2(char const *str)
{
    char *str1 = {'\0'};
    char **final_str;
    int i = 0;
    while (str[i] != '\n'){
        i++;
    }
    str1 = malloc(sizeof(char) * i + 1);
    i = 0;
    while (str[i] != '\n'){
        str1[i] = str[i];
        i++;
    }
    final_str = my_str_to_word_array(str1);
    return final_str;
}

void check_if_spec_char(char **compressed_text, char **tab_of_dup, int i)
{
    char *table_of_compression[9] = {"@~", "@&", "@@", "@`", "øø", "øµ", "ø§", \
"ø°", "ø¨"};
    for (int j = 0; j != my_strstrlen(tab_of_dup); j++){
        if (my_strcmp(compressed_text[i], table_of_compression[j]) == 0){
            compressed_text[i] = tab_of_dup[j];
        }
    }
}

void my_text_decompression(char const *str)
{
    char **tab_of_dup = fill_tab_of_dup(str);
    char **tab_of_dup2 = fill_tab_of_dup_2(str);
    char **compressed_text = my_str_to_word_array(str);
    char *new_str;
    int len_tab_of_dup = my_strstrlen(tab_of_dup);
    while (compressed_text[len_tab_of_dup] != NULL){
        check_if_spec_char(compressed_text, tab_of_dup, len_tab_of_dup);
        len_tab_of_dup++;
    }
    new_str = concatenate_double_array_giant(compressed_text, tab_of_dup2);
    str_to_standard_output_giant(new_str);
}
