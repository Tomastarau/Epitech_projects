/*
** EPITECH PROJECT, 2023
** solo stumper 2
** file description:
** solo stumper 2 functions
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my_printf.h"
#include "../include/my.h"

int hidenp(char *argv[])
{
    int i = 0, compteur = 0, j = 0;
    int len_haystack = my_strlen(argv[2]);
    while (i < len_haystack){
        if (argv[1][j] == argv[2][i]){
            compteur++;
            j++;
        }
        i++;
    }
    if (compteur == my_strlen(argv[1])){
            my_printf("1\n");
        } else {
            my_printf("0\n");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 3 && my_strlen(argv[1]) > 0 && my_strlen(argv[2]) > 0){
        hidenp(argv);
                return 0;
    } else {
        write(2, "Usage: ./hidenp needle haystack\n", 33);
        return 84;
    }
}
