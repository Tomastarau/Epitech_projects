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
            free(temp->data);
            temp->data = strdup(new_value);
        }
        temp = temp->next;
    }
}

// Create a new node with the given data
node_t* create_node(char* data)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node with the given data at the end of the list
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

// Delete the first node with the given data from the list
void delete_node(node_t** head, char* data)
{
    node_t* current = *head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

// Display the list elements
void display_list(node_t* head)
{
    node_t* current = head;

    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Free the memory allocated for the list
void free_list(node_t** head)
{
    node_t* current = *head;
    node_t* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}