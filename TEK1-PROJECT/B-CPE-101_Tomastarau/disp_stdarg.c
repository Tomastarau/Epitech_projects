/*
** EPITECH PROJECT, 2022
** task03 bootstrap
** File description:
** task03 bootstrap
*/

#include "includes/bsprintf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int my_put_nbr(int nb);

void my_putchar(char c)
{
    write(1, &c, 1);
    write(1, '\n', 1);
}

int my_strlen(char const *str);

int my_putstr(char const *str);

void disp_stdarg(char *s, ...)
{
    va_list u;
    int index = 0;

    va_start(u, s);
    while (s[index] != '\0'){
        switch (*s++){
        case 'c':
            my_putchar(va_arg(u, int));
            break;
        case 'i':
            my_put_nbr(va_arg(u, int));
            break;
        case 's':
            my_putstr(va_arg(u, char*));
            break;
        default:
            break;
        }
        index++;
    }
    va_end(u);
}