/*
** EPITECH PROJECT, 2022
** my_compute_power_it
** File description:
** task03
*/
void my_putchar(char c);

int my_compute_power_it(int nb, int p)
{
    long res = 1;

    if (p == 0){
        return (1);
    }
    if (p < 0){
        return (0);
    }
    while (p != 0){
        res = res * nb;
        p = p - 1;
        if (res < -2147483648 || res > 2147483647){
        return (0);
        }
    }
    return (res);
}
