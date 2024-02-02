/*
** EPITECH PROJECT, 2022
** My_printf.c
** File description:
** Main function for my_printf.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/printf.h"
#include "../include/my.h"

int my_printf(const char *restrict format, ...)
{
    int index = 0;
    int char_printf = 0;

    va_list lili;
    va_start(lili, format);
    while (format[index] != '\0'){
        if (format[index] == '%'){
            index++;
            char_printf = char_printf + find_next_flag(format, lili, index);
        }else{
            my_putchar(format[index]);
            char_printf = char_printf + 1;
        }
        index++;
    }
    va_end(lili);
    return char_printf;
}
