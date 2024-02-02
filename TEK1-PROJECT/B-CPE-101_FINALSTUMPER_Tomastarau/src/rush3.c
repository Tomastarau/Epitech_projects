/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** rush3
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

void display_xy(int x, int y)
{
    my_put_nbr(x);
    my_putchar(32);
    my_put_nbr(y);
}

void display_arg(int x, int y, char *buff)
{
    if (x == 1 || y == 1) {
        my_putstr("[rush1-3] ");
        display_xy(x, y);
        my_putstr(" || [rush1-4] ");
        display_xy(x, y);
        my_putstr(" || [rush1-5] ");
        display_xy(x, y);
    } else if (&buff[x - 1] == "A") {
        my_putstr("[rush1-3] ");
        display_xy (x, y);
    }
    if (&buff[x * y - 1] == "C") {
        my_putstr ("[rush1-5] ");
        display_xy (x, y);
    } else {
        my_putstr("[rush1-4] ");
        display_xy(x, y);
    }
    my_putchar('\n');
}

void rush3(char *buff)
{
    int x = 0;
    int y = 0;

    for (; buff[x] != '\n' && buff[x] != '\0'; x++);
    for (int i = 0; buff[i] != '\0'; i++)
        y += (buff[i] == '\n') ? 1 : 0;
    if (buff[0] == 'o') {
        my_putstr("[rush1-1] ");
        display_xy(x, y);
        my_putchar('\n');
    }
    while (buff[0] == '/' || buff[0] == '*') {
            my_putstr("[rush 1-2] ");
            display_xy(x, y);
            my_putchar('\n');
    }
    if (buff[0] == 'A' || buff[0] == 'B')
        display_arg(x, y, buff);
}
