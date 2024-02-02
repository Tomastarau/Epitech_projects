/*
** EPITECH PROJECT, 2022
** sum_numbers
** File description:
** sum_numbers.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int my_put_nbr(int nb);

int sum_numbers(int n, ...)
{
    va_list nbr;
    int i = 0;
    long s = 0;

    va_start(nbr, n);
    while (i != n){
        if (s < 2147483647 && s > -2147483648){
            s = s + va_arg(nbr, long);
            i = i + 1;
        }else{
            write(2, "Overflow error", 15);
            return (84);
        }
    }
    va_end(nbr);
    return (s);
}
