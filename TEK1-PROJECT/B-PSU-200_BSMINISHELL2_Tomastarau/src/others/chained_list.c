/*
** EPITECH PROJECT, 2023
** chained list fonctions
** File description:
** chained_list
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

void update_node(node_t *head, char *old_value, char *new_value)
{
    node_t *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, old_value) == 0) {
            temp->data = my_strdup(new_value);
        }
        temp = temp->next;
    }
}

node_t* create_node(char* data)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(node_t** head, char* data)
{
    node_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void delete_node(node_t** head, char* data)
{
    node_t* current = *head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            *head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
}

void display_list(node_t* head)
{
    node_t* current = head;
    while (current != NULL) {
        my_printf("%s\n", current->data);
        current = current->next;
    }
}
