/*
** EPITECH PROJECT, 2022
** sum_numbers
** File description:
** sum_numbers.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int my_strlen(char const *str);

int my_put_nbr(int nb);

int sum_strings_length(int n, ...)
{
    va_list str;
    int i = 0;
    long s = 0;

    va_start(str, n);
    while (i != n){
        s = s + my_strlen(va_arg(str, char const *));
        i = i + 1;
    }
    va_end(str);
    my_put_nbr (s);
}
