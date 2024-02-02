/*
** EPITECH PROJECT, 2022
** Printf_d.c
** File description:
** Flag "d" for my_printf.c
*/

#include "my_printf.h"
#include "../my.h"
#include <unistd.h>

int printf_d(va_list ap)
{
    int char_flag = 0;

    char_flag = char_flag + my_put_nbr(va_arg(ap, int));
    return char_flag;
}
