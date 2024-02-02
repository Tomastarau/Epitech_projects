/*
** EPITECH PROJECT, 2023
** exo1
** File description:
** exo1
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_printf.h"

int main(void)
{
    my_printf("%d\n", getpid());
    return 1;
}