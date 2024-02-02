/*
** EPITECH PROJECT, 2022
** Printf_c.c
** File description:
** Flag "c" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

int printf_c(va_list ap)
{
    int char_flag = 0;

    my_putchar(va_arg(ap, int));
    char_flag++;
    return char_flag;
}
