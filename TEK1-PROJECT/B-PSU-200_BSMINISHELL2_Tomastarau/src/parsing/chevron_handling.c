/*
** EPITECH PROJECT, 2023
** handling chevron separator
** File description:
** chevron_handling
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "my.h"
#include "my_printf.h"
#include "my_sh.h"

/*int redirect_io(const char *filename, const char *redirect_type)
{
    int file_descriptor;

    if (strcmp(redirect_type, "input") == 0) {
        // Open the file for reading
        file_descriptor = open(filename, O_RDONLY);
        if (file_descriptor == -1) {
            perror("open");
            return -1;
        }
        // Redirect standard input (STDIN_FILENO) to the file
        if (dup2(file_descriptor, STDIN_FILENO) == -1) {
            perror("dup2");
            close(file_descriptor);
            return -1;
        }
    } else if (strcmp(redirect_type, "output") == 0) {
        file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (file_descriptor == -1) {
            perror("open");
            return -1;
        }
        // Redirect standard output (STDOUT_FILENO) to the file
        if (dup2(file_descriptor, STDOUT_FILENO) == -1) {
            perror("dup2");
            close(file_descriptor);
            return -1;
        }
    } else {
        fprintf(stderr, "Invalid redirect_type: %s\n", redirect_type);
        return -1;
    }

    // Close the file descriptor as it's no longer needed
    close(file_descriptor);
    return 0;
}*/
