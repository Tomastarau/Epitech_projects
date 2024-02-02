/*
** EPITECH PROJECT, 2022
** Modifier_ll.c
** File description:
** Length modifier "ll" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"

int modifier_ll(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}
