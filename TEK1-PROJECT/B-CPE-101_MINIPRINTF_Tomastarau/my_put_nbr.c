/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_put_nbr(int nb)
{
    long int n = nb;
    int i = 0;

    if (n < 0){
        i++;
        my_putchar('-');
        n = -n;
    }
    if (n > 9){
        i = i + my_put_nbr(n / 10);
    }
    i++;
    my_putchar(48 + n % 10);
    return (i);
}
