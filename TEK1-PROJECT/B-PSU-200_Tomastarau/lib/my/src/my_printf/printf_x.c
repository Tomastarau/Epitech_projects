/*
** EPITECH PROJECT, 2022
** Printf_x
** File description:
** Flag "x" for my_printf.c
*/

#include "my_printf.h"
#include "../my.h"
#include <unistd.h>

int printf_x(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    return 0;
}
