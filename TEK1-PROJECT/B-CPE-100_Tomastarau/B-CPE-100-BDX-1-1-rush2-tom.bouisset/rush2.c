/*
** EPITECH PROJECT, 2022
** rush.c
** File description:
** test
*/

#include <stdlib.h>

#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

int *number_occu(int argc , char **argv)
{
    int occu = 0;
    int i = 0;
    if (argc < 3){
        my_printstr("Error");
        return (84);
    }
    while (argv[1][i] != '\0'){
        if (argv[1][i] + 32 == argv[2][0] || argv[1][i] - 32 == argv[2][0]){
            occu = occu + 1;
        }
        if (argv[1][i] == argv[2][0]){
            occu = occu + 1;
        }
        i = i + 1;
    }
    my_putchar (occu);
}

void my_printstr(char *str)
{
    int pntr = 0;
    while (str[pntr] != '\0'){
        write(2, &str[pntr], 1);
        pntr = pntr + 1;
    }
}

int main(int ac, char ** av)
{
    int n = 2;
    while(n < ac){
        my_putchar(av[n][0]);
        my_putchar(':');
        number_occu(ac, av);
        my_putchar('\n');
        n = n + 1;
    }
    return (0);
}
