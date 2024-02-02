/*
** EPITECH PROJECT, 2022
** main
** File description:
** calling founction main and my_putchar
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    rush(50, 30);
    my_putchar('\n');
    rush(5, 10);
    my_putchar('\n');
    rush(16, 12);
    my_putchar('\n');
    rush(1, 5);
    my_putchar('\n');
    rush(1, 1);
    return (0);
}
