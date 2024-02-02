/*
** EPITECH PROJECT, 2022
** printf_pourcentage
** File description:
** put a '%'
*/

#include "my_printf.h"
#include "../my.h"
#include <unistd.h>

int printf_pourcentage(va_list ap)
{
    int char_flag = 0;

    my_putchar('%');
    char_flag++;
    return char_flag;
}
