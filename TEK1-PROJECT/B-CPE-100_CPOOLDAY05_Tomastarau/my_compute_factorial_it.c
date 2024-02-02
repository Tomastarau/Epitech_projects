/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it
** File description:
** task01
*/

void my_putchar(char c);

int my_compute_factorial_it(int nb)
{
    int res = 1;
    int i = 2;

    if (nb == 0 || nb == 1){
        return (1);
    }
    if (nb < 0 || nb > 12){
        return (0);
    }
    while (i <= nb){
        res = res * i;
        i = i + 1;
    }
    return (res);
}
