/*
** EPITECH PROJECT, 2022
** Printf_b.c
** File description:
** Flag "b" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>

int printf_b(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
