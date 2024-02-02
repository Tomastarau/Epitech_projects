/*
** EPITECH PROJECT, 2022
** Printf_u
** File description:
** Flag "u" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>

int printf_u(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789");
}
