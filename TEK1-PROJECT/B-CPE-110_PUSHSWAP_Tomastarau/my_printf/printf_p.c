/*
** EPITECH PROJECT, 2022
** printf_p
** File description:
** printf_p
*/
#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>

int printf_p(va_list ap)
{
    int char_printed = 0;

    my_putstr("0x");
    char_printed = char_printed +
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    return char_printed + 2;
}
