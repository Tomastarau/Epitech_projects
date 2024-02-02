/*
** EPITECH PROJECT, 2022
** Modifier_hh.c
** File description:
** Length modifier "hh" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"

int modifier_hh(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
