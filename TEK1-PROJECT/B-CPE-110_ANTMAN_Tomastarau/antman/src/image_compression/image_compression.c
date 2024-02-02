/*
** EPITECH PROJECT, 2023
** image_compression.c
** File description:
** file for image compression
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

int count_lines(char *str)
{
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            result++;
        }
    }
    return result;
}

void write_header_compression(char *image)
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
}

void image_compression(char *filepath)
{
    char *str = file_to_str(filepath);
    char **image = my_str_to_word_array_2(str);
    int lines = count_lines(str);
    write_header_compression(str);
    for (int i = 3; i < lines; i++) {
        int number = my_getnbr(image[i]);
        unsigned char data = number;
        write(1, &data, 1);
        my_putchar('\n');
    }
}
