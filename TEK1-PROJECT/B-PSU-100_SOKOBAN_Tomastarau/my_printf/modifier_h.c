/*
** EPITECH PROJECT, 2022
** Modifier_h.c
** File description:
** Length modifier "h" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"

int modifier_h(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
