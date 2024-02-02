/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec
** File description:
** task02
*/

void my_putchar(char c);

int my_compute_factorial_rec(int nb)
{
    if (nb == 0 || nb == 1){
        return (1);
    }
    if (nb < 0 || nb > 12){
        return (0);
    }
    return (my_compute_factorial_rec(nb - 1) * nb);
}
