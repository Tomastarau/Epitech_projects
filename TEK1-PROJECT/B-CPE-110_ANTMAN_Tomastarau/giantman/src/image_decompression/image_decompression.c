/*
** EPITECH PROJECT, 2023
** image_decompression.c
** File description:
** file for image decompression
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

char *file_to_str(const char *filepath);

int count_lines(char *image)
{
    int result = 0;
    for (int i = 0; image[i] != '\0'; i++) {
        if (image[i] == '\n') {
            result++;
        }
    }
    return result;
}

int write_header_decompression(char *image)
{
    int n = 0;
    int length;
    for (int i = 0; n < 3; i++) {
        if (image[i] == '\n') {
            n++;
        }
        length++;
    }
    write(1, image, length);
    return length;
}

void image_file_decompression(char *filepath)
{
    char *image = file_to_str(filepath);
    int nb_lines = count_lines(image);
    int length = write_header_decompression(image);
    for (int i = length; i < nb_lines; i += 2) {
        unsigned char data = image[i];
        my_printf("%d\n", data);
    }
}
