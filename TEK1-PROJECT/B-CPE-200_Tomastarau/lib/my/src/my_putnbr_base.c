/*
** EPITECH PROJECT, 2022
** nbrput base for printf
** File description:
** nbr put base for print f
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

int my_strlen(const char *str);

int my_putnbr_base(int nb, char const *base)
{
    int i = nb;
    int taille = my_strlen(base);
    int char_print = 0;

    if (i < 0){
        char_print++;
        i = -i;
        my_putchar('-');
    }
    if (i > (taille - 1)){
        char_print = char_print + my_putnbr_base(i / taille, base);
    }
    char_print++;
    my_putchar(base[i % taille]);
    return char_print;
}
