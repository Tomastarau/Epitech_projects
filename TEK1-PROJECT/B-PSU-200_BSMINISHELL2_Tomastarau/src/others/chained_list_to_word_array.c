/*
** EPITECH PROJECT, 2023
** chained list to word array
** File description:
** chained_list_to_word_array
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

int list_length(node_t *head)
{
    int length = 0;
    node_t *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

char **linked_list_to_char_array(node_t *head)
{
    int length = list_length(head);
    char **env_array = (char **)malloc((length + 1) * sizeof(char *));
    node_t *current = head;
    int i = 0;
    while (current != NULL) {
        env_array[i] = current->data;
        current = current->next;
        i++;
    }
    env_array[length] = NULL;
    return env_array;
}
