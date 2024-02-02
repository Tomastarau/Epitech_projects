/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
