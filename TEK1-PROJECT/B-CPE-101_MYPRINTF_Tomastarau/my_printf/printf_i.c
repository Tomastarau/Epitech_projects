/*
** EPITECH PROJECT, 2022
** Printf_i.c
** File description:
** Flag "i" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>

int printf_i(va_list ap)
{
    int char_flag = 0;

    char_flag = char_flag + my_put_nbr(va_arg(ap, int));
    return char_flag;
}
