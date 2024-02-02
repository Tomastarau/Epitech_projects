/*
** EPITECH PROJECT, 2022
** Modifier_l.c
** File description:
** Length modifier "l" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"

int modifier_l(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
