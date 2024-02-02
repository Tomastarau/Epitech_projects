/*
** EPITECH PROJECT, 2023
** parse a string with multiple commands into array of same commands
** File description:
** str_commands_to_array
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

static int len_when_new_pipe(char **command_str, int delimiter_number, \
char *next_separator, char* separator)
{
    int i = 0, j = 0, len = 0;
    if ((my_strcmp(separator, "|") == 0 && (my_strcmp(next_separator, ">") == \
0 || my_strcmp(next_separator, "<") == 0 || my_strcmp(next_separator, ">>") == \
0 || my_strcmp(next_separator, "<<") == 0)) || (my_strcmp(next_separator, "|") \
!= 0 && my_strcmp(next_separator, ">") != 0 && my_strcmp(next_separator, "<") \
!= 0 && my_strcmp(next_separator, ">>") != 0 && my_strcmp(next_separator, \
"<<") != 0)) {
        return 0;
    }
    while (i != delimiter_number || command_str[j] == NULL) {
        if (my_strcmp(command_str[j], separator) == 0) {
            i++;
        }
        len = len + my_strlen(command_str[j]);
        j++;
    }
    return len;
}

static int str_index(char *str_array[], int index)
{
    int i = 0;
    int current_index = 0;

    while (str_array[i] != NULL) {
        current_index += strlen(str_array[i]);
        if (index < current_index) {
            return i;
        }
        i++;
    }

    return -1;
}

static int len_command(char** command_str, int i)
{
    int len_command = 0, delimiter_number = 0;
    char* separator = " ";
    while (command_str[i] != NULL) {
        if (is_delimiter(separator) && is_delimiter(command_str[i]) && my_st\
rcmp(separator, command_str[i]) != 0) {
            return (len_when_new_pipe(command_str, delimiter_number, \
command_str[i], separator) == 0 ? len_command : len_when_new_pipe(command_str, \
delimiter_number, command_str[i], separator));
        }
        if (is_delimiter(command_str[i])){
            delimiter_number++;
            separator = command_str[i];
        }
        len_command = len_command + my_strlen(command_str[i]);
        i++;
    }
    return len_command;
}

static char *strcat_range(char *dest, const char *src, int start, int end)
{
    if (start < 0 || end < start) {
        return dest;
    }
    int dest_len = strlen(dest);
    int src_len = strlen(src);
    if (end > src_len) {
        end = src_len;
    }
    for (int i = start; i < end; ++i) {
        dest[dest_len++] = src[i];
    }
    dest[dest_len] = '\0';

    return dest;
}

char **str_commands_to_array(char *commands_str)
{
    char** tab_of_commands = my_str_to_word_array_parse(commands_str);
    int index = 0, old_index = 0, number_of_commands = 0;
    char** final_command_arr = NULL;
    while (index < my_strlen(commands_str)) {
        index = index + len_command(tab_of_commands, \
str_index(tab_of_commands, index));
        number_of_commands++;
    }
    final_command_arr = malloc(sizeof(char *) * (number_of_commands + 1));
    index = 0;
    for (int m = 0; m < number_of_commands; m++) {
        index = index + len_command(tab_of_commands, \
str_index(tab_of_commands, index));
        final_command_arr[m] = malloc(sizeof(char) * ((index - old_index) + 1));
        my_memset(final_command_arr[m], '\0', (index - old_index) + 1);
        strcat_range(final_command_arr[m], commands_str, old_index, index);
        old_index = index;
    }
    final_command_arr[number_of_commands] = NULL;
    return final_command_arr;
}
