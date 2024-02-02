/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include "swap.h"
#include "printf.h"
#include "my.h"

int algo_for_4_arg(int argv1, int argv2, char *argv[])
{
    int argv3 = my_getnbr(argv[3]);

    if (argv1 > argv2 && argv1 < argv3)
        my_printf("pa\n");
    if (argv1 > argv2 && argv2 > argv3)
        my_printf("sa rra\n");
    if (argv1 > argv2 && argv2 < argv3)
        my_printf("ra\n");
    if (argv1 < argv2 && argv2 > argv3)
        my_printf("sa ra\n");
    if (argv1 < argv2 && argv1 > argv3)
        my_printf("rra\n");
    if (argv1 < argv2 && argv2 < argv3)
        write(1, "List already sorted\n", 21);
    return 0;
}

void algo_for_3_or_4_arg(int argc, char *argv[])
{
    int argv1 = my_getnbr(argv[1]);
    int argv2 = my_getnbr(argv[2]);
    if (argc == 3){
        if (argv1 < argv2){
            write(1, "List already sorted\n", 21);
            return;
        } else {
            my_printf("sa\n");
            return;
        }
    } else {
        algo_for_4_arg(argv1, argv2, argv);
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3){
        write(2, "Error too less arguments\n", 25);
        return (84);
    }
    if (argc == 3 || argc == 4){
        algo_for_3_or_4_arg(argc, argv);
        return 0;
    }
    if (add_arg_to_list(argc, argv) == 84){
        return 84;
    }
    return 0;
}
