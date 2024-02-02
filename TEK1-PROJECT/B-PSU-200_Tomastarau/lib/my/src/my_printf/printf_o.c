/*
** EPITECH PROJECT, 2022
** Printf_o
** File description:
** Flag "o" for my_printf.c
*/

#include "my_printf.h"
#include "../my.h"
#include <unistd.h>

int printf_o(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01234567");
    return 0;
}
