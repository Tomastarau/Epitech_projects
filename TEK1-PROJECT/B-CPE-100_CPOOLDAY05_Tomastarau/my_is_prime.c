/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** task day 05
*/

int my_is_prime(int nb)
{
    int i = 3;

    if (nb < 2 || nb % 2 == 0){
        return (0);
    }
    if (nb == 2){
        return (1);
    }
    while (i * i <= nb){
        if (nb % i == 0 || (nb < 2) || nb % 2 == 0){
            return (0);
        }
        i = i + 2;
    }
    return (1);
}
