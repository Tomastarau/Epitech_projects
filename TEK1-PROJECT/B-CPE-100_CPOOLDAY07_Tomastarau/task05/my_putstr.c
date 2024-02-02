/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
            my_putchar(str[i]);
            i = i + 1;
        }
    my_putchar('\n');
    return (0);
}
