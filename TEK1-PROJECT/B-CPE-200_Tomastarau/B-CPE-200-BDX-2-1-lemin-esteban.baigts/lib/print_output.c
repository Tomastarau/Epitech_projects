/*
** EPITECH PROJECT, 2023
** lemintest
** File description:
** print_error
*/

#include <unistd.h>

#include "../include/print_output.h"
#include "../include/str_utils.h"

int print_error(char const *str, char separator)
{
    if (!str) {
        return -1;
    }

    write(2, str, str_len(str));
    if (separator > 0)
        write(2, &separator, 1);

    return -1;
}

int print_buf(char const *str, char separator)
{
    if (!str)
        return 0;

    write(1, str, str_len(str));
    if (separator > 0)
        write(1, &separator, 1);

    return 0;
}

static void display_digit(int digit_count, long cur_div)
{
    for (int i = 0; i < digit_count; i++) {
        char ch = 48 + (cur_div % 10);
        write(1, &ch, 1);
        cur_div /= 10;
    }
}

int print_nbr(int nb, char separator)
{
    if (nb == 0)
        return print_buf("0", separator);

    long long new_number = nb, rest = 0, digit_count = 0;
    long cur_div = 0;

    new_number = (nb < 0) ? nb * -1L : nb;
    if (nb < 0)
        write(1, "-", 1);;

    while (new_number != 0) {
        rest = new_number % 10; cur_div = cur_div * 10 + rest;
        new_number /= 10; digit_count++;
    }

    display_digit(digit_count, cur_div);
    if (separator > 0)
        write(1, &separator, 1);

    return 0;
}
