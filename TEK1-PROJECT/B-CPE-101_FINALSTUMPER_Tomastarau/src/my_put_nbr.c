/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return 0;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    if (nb <= 9) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_putchar( nb % 10 +'0');
    }
}
