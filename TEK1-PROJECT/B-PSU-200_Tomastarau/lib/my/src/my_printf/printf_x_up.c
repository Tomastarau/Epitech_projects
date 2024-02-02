/*
** EPITECH PROJECT, 2022
** Printf_X.c
** File description:
** Flag "X" for my_printf.c
*/

#include "my_printf.h"
#include "../my.h"
#include <unistd.h>

int printf_x_up(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
    return 0;
}
