/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long int n = nb;
    if (n < 0){
        my_putchar('-');
        n = -n;
    }
    if (n > 9){
        my_put_nbr(n / 10);
    }
    my_putchar(48 + n % 10);
}

