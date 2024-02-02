/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>

int my_is_prime(int nb);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    int nb = 67;

    printf("%d\n", my_is_prime(nb));
    return (0);
}
