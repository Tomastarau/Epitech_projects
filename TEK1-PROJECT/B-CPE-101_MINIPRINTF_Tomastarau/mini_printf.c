/*
** EPITECH PROJECT, 2022
** task03 bootstrap
** File description:
** task03 bootstrap
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int my_put_nbr(int nb);

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

int switchh(char const *format, va_list ap, int index)
{
    switch (format[index]){
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            break;
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list u;
    int index = 0;
    int len_return_miniprintf = 0;

    va_start(u, format);
    while (format[index] != '\0'){
        if (format[index] == '%'){
            index++;
            switchh(format, u, index);
            index++;
        }else{
            my_putchar(format[index]);
            index++;
        }
        va_end(u);
    }
    return 0;
}
