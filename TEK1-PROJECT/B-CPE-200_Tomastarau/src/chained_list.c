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
#include "my_lemin.h"

// Create a new node with the given data
link_t* create_node(int data)
{
    link_t* new_node = malloc(sizeof(link_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node with the given data at the end of the list
void insert_at_end(link_t** head, int data)
{
    link_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    link_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Display the list elements
void display_list(link_t* head)
{
    link_t* current = head;

    while (current != NULL) {
        my_printf("%s\n", current->data);
        current = current->next;
    }
}

// Free the memory allocated for the list
void free_list(link_t** head)
{
    link_t* current = *head;
    link_t* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}